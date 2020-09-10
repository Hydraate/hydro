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

#ifndef __h3o_TokenType__
#define __h3o_TokenType__

#include <cstdlib>

enum TokenType : int32_t
{
    err_tkn = -5,  // erroneous token
    eof_tkn = -4,  // EOF
    nil_tkn = -3,  // nil
    ln_tkn = -2,   // linefeed
    ws_tkn = -1,   // whitespace
    token_tkn = 0, // standard token
    id_tkn = 1,    // identifier
    scomment_tkn,  // single-line comment
    mcomment_tkn,  // multi-line comment
    tab_tkn,       // tab token
    op_tkn,        // operator
    char_tkn,      // character literal
    bool_tkn,      // boolean literal
    int_tkn,       // integer literal
    uint_tkn,      // unsigned literal
    bin_tkn,       // binary literal
    hex_tkn,       // hexadecimal literal
    oct_tkn,       // octal literal
    float_tkn,     // float literal
    double_tkn,    // double literal
    string_tkn,    // string literal
    template_tkn,  // string template
    xml_tkn,       // xml literal
    regex_tkn,     // regular expression literal
    ushort_tkn,    // unsigned short literal
    short_tkn,     // short literal
    ulong_tkn,     // unsigned long literal
    long_tkn,      // long literal
    identity_tkn,  // identity literal (e.g., @MyButton)
    color_tkn,     // color literal (e.g, #ff0000)
    directive_tkn  // directive
};

#endif /* __h3o_TokenType__ */
