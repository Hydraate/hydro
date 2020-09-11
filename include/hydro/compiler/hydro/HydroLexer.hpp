//
//                 __  __            __           
//                / / / /__  __ ____/ /_____ ____ 
//               / /_/ // / / // __  // ___// __ \
//              / __  // /_/ // /_/ // /   / /_/ /
//             /_/ /_/ \__, / \__,_//_/    \____/ 
//                    /____/                      
//
//              The Hydro Programming Language
//

#ifndef __h3o_internal_HydroLexer__
#define __h3o_internal_HydroLexer__

#include "../Lexer.hpp"
#include "hvm_compile_errors.hpp"

namespace hydro::compiler
{
class HydroLexer : public Lexer
{
private:
    // speculation
    bool predictHex();
    bool predictBin();
    bool predictOct();
    bool predictInt(bool bypassCheck = true);
    bool predictShort();
    bool predictLong();
    bool predictUint(bool bypassCheck = true);
    bool predictUshort();
    bool predictUlong();
    bool predictExp();
    bool predictFloat();
    bool predictDouble(bool bypassCheck = true);
    bool validateNum();

    // consumption
    Token id();     // identifier
    Token hex();    // hexadecimal literal
    Token bin();    // binary literal
    Token oct();    // octal literal
    Token u16();    // ushort literal
    Token i16();    // short literal
    Token u32();    // uint literal
    Token i32();    // int literal
    Token u64();    // ulong litearl
    Token i64();    // long literal
    Token exp();    // scientific notation (float/double)
    Token flt();    // float literal
    Token dbl();    // double literal
    Token chr();    // character literal
    Token string(); // string literal
    Token tpl();    // string template
    Token com1();   // single line comment
    Token com2();   // multi-line comment

public:
    HydroLexer(ErrorReporter *errorReporter);
    virtual ~HydroLexer();
    virtual Token readNext() override;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_HydroLexer__ */
