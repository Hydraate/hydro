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

#ifndef __h3o_engine_PDocumentLexer__
#define __h3o_engine_PDocumentLexer__

#include "../../compiler/Lexer.hpp"
#include "../../compiler/hydro/hvm_compile_errors.hpp"

namespace hydro::engine
{
/**
 * The performance_lexer_state is required to alter how the lexer creates tokens for given situations.
 */
enum performance_lexer_state
{
    engine_parse_entity,
    engine_parse_expression
};

/**
 *
 */
class PDocumentLexer : public compiler::Lexer
{
public:
    /**
     *
     */
    PDocumentLexer();

    /**
     *
     */
    PDocumentLexer(compiler::ErrorReporter *errorReporter);

    /**
     *
     */
    virtual ~PDocumentLexer();

    performance_lexer_state getState() const { return mState; }

    void setState(performance_lexer_state state) { mState = state; }

protected:
    /**
     *
     */
    virtual compiler::Token readNext() override;

private:
    /**
     *
     */
    performance_lexer_state mState;

    /**
     *
     */
    bool predictTab();

    /**
     *
     */
    bool predictHex();

    /**
     *
     */
    bool predictBin();

    /**
     *
     */
    bool predictOct();

    /**
     *
     */
    bool predictInt(bool bypassCheck = true);

    /**
     *
     */
    bool predictShort();

    /**
     *
     */
    bool predictLong();

    /**
     *
     */
    bool predictUint(bool bypassCheck = true);

    /**
     *
     */
    bool predictUshort();

    /**
     *
     */
    bool predictUlong();

    /**
     *
     */
    bool predictExp();

    /**
     *
     */
    bool predictFloat();

    /**
     *
     */
    bool predictDouble(bool bypassCheck = true);

    /**
     *
     */
    bool validateNum();

    /**
     *
     */
    compiler::Token id(); // identifier

    /**
     *
     */
    compiler::Token hex(); // hexadecimal literal

    /**
     *
     */
    compiler::Token bin(); // binary literal

    /**
     *
     */
    compiler::Token oct(); // octal literal

    /**
     *
     */
    compiler::Token i16(); // short literal

    /**
     *
     */
    compiler::Token i32(); // int literal

    /**
     *
     */
    compiler::Token exp(); // scientific notation (float/double)

    /**
     *
     */
    compiler::Token dbl(); // double literal

    /**
     *
     */
    compiler::Token chr(); // character literal

    /**
     *
     */
    compiler::Token string(); // string literal

    /**
     *
     */
    compiler::Token tpl(); // string template

    /**
     *
     */
    compiler::Token did(); // drip identity

    /**
     *
     */
    compiler::Token com(); // comment
};

} // namespace hydro::engine

#endif /* __h3o_engine_PDocumentLexer__ */
