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

#include "PDocumentLexer.hpp"

namespace hydro::engine
{
/**
 *
 */
static std::regex h3olexer_operator{"^(\\+|\\+\\+|\\-|\\-\\-|\\*|\\*\\*|\\/|%|=|==|!=|~|!|\\.|&|&&|@>|@>>|<->|->|\\+=|-=|\\*=|\\*\\*=|\\/=|%=|&=|>|>=|<|<=|>>|<<|>>=|\\^|\\||\\|\\||\\?|:|::|\\(|\\)|\\.|\\.\\.|\\.\\.\\.)$"};

/**
 *
 */
static std::regex h3olexer_token{"^\\{|\\}|\\(|\\)|\\[|\\]|;|\\:|,$"};

/**
 *
 */
static std::regex h3olexer_identity{"^\\@[a-zA-Z_][a-zA-Z0-9_]*$"};

/**
 *
 */
static std::regex drip_ws{"^[ \\f\\r]*$"};

/**
 *
 */
PDocumentLexer::PDocumentLexer()
    : PDocumentLexer{nullptr}
{
}

/**
 *
 */
PDocumentLexer::PDocumentLexer(compiler::ErrorReporter *errorReporter)
    : Lexer{errorReporter}
{
    mState = engine_parse_entity;
    registerTokenPattern(ws_tkn, compiler::lexer_whitespace);
    registerTokenPattern(id_tkn, compiler::lexer_identifier);
    registerTokenPattern(identity_tkn, h3olexer_identity); // identity
    registerTokenPattern(token_tkn, h3olexer_token);
    registerTokenPattern(op_tkn, h3olexer_operator);

    registerTokenName(identity_tkn, "identity");
    registerTokenName(double_tkn, "number literal");
}

/**
 *
 */
PDocumentLexer::~PDocumentLexer() {}

/**
 *
 */
bool PDocumentLexer::predictTab()
{
    specStart();
    if (specMatch(' ') && specMatch(' ') && specMatch(' ') && specMatch(' '))
        return specSuccess();
    /*
    uint32_t spacesEqualTab = 4; // amount of spaces that equal a tab
    
    while (--spacesEqualTab > 0)
        if(!specMatch(' '))
            return specFail();
    */
    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictHex()
{
    specStart();

    if (specMatch('0') && (specMatch('x') || specMatch('X')))
    {
        // must be at least one hex digit
        if (specMatch(compiler::lexer_hexadecimal_digit))
        {
            while (specMatch(compiler::lexer_hexadecimal_digit))
                ; // eat hex digits

            if (validateNum())
                return specSuccess();
        }
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictBin()
{
    specStart();

    if (specMatch('0') && (specMatch('b') || specMatch('B')))
    {
        while (specMatch(compiler::lexer_binary_digit))
            ;

        // any trailing characters result in failure
        while (specMatch(compiler::lexer_alphanum_underscore))
            return specFail();

        // otherwise success!
        return specSuccess();
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictOct()
{
    specStart();

    if (specMatch('0') && (specMatch(compiler::lexer_octal_digit)))
    {
        while (specMatch(compiler::lexer_octal_digit))
            ;

        // any trailing characters result in failure
        while (specMatch(compiler::lexer_alphanum_underscore))
            return specFail();

        // otherwise success!
        return specSuccess();
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictInt(bool bypassCheck)
{
    specStart();

    // must be at least one digit
    if (specMatch(compiler::lexer_digit))
    {
        while (specMatch(compiler::lexer_digit))
            ; // eat all digits

        if (bypassCheck || validateNum())
            return specSuccess();
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictExp()
{
    specStart();

    if (specMatch('e') || specMatch('E'))
    {
        if (!specMatch('+'))
            specMatch('-'); // both are optional

        if (specMatch(compiler::lexer_digit))
        {
            while (specMatch(compiler::lexer_digit))
                ; // eat digits

            // do not check value for trailing alphanumeric characters and underscores (i.e., validateNum())
            return specSuccess();
        }
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::predictDouble(bool bypassCheck)
{
    specStart();

    if (specMatch(compiler::lexer_digit))
    {
        while (specMatch(compiler::lexer_digit))
            ; // eat digits

        // check for exponential or decimal
        if (predictExp())
        {
            if (bypassCheck || validateNum())
                return specSuccess();
        }
        else if (specMatch('.'))
        {
            // must have at least one digit after the decimal
            if (specMatch(compiler::lexer_digit))
            {
                while (specMatch(compiler::lexer_digit))
                    ; // eat digits

                if (predictExp())
                {
                    // eat optional exponential
                }

                if (bypassCheck || validateNum())
                    return specSuccess();
            }
        }
        else
            return specSuccess(); // changed this line to make all numerical values doubles
    }

    return specFail();
}

/**
 *
 */
bool PDocumentLexer::validateNum()
{
    specStart();

    while (specMatch(compiler::lexer_alphanum_underscore))
        return specFail();

    return specSuccess();
}

/**
 *
 */
compiler::Token
PDocumentLexer::id()
{
    while (matchBufferWithNext(id_tkn))
        consume();

    if(buffer() == "true" || buffer() == "false")
        return flush(bool_tkn);
    else if(buffer() == "Infinity" || buffer() == "NaN")
        return flush(double_tkn);
    return flush(id_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::hex()
{
    consume(); // eat 0
    consume(); // eat x

    while (matchBufferWithNext(compiler::lexer_hexadecimal))
        consume();

    if (matchBufferWithNext(compiler::lexer_alpha))
    {
        // not a valid hex
        advance();
        abrupt();
    }

    return flush(hex_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::bin()
{
    consume(); // eat 0
    consume(); // eat b

    while (matchBufferWithNext(compiler::lexer_binary))
        consume();

    return flush(bin_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::oct()
{
    consume(); // eat 0

    while (matchBufferWithNext(compiler::lexer_octal))
        consume();

    return flush(oct_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::i32()
{
    consume(); // eat first digit

    while (matchBufferWithNext(compiler::lexer_digit))
        consume(); // eat digits

    return flush(double_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::exp()
{
    consume(); // eat e

    if (matchNext('+') || matchNext('-'))
        consume(); // consume optional sign

    while (matchNext(compiler::lexer_digit))
        consume(); // consume exponential

    // float
    if (matchNext('f') || matchNext('F'))
    {
        consume();
        return flush(float_tkn);
    }
    else if (matchNext('d') || matchNext('D'))
        consume(); // eat optional d

    // double
    return flush(double_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::dbl()
{
    consume(); // eat first digit

    while (matchNext(compiler::lexer_digit))
        consume(); // eat digit

    if (matchNext('e') || matchNext('E'))
        return exp();

    if (matchNext('.'))
    {
        consume(); // eat .
        while (matchNext(compiler::lexer_digit))
            consume(); // eat digits
    }

    if (matchNext('e') || matchNext('E'))
        return exp();

    if (matchNext('d') || matchNext('D'))
        consume(); // eat optional d

    return flush(double_tkn);
}

compiler::Token
PDocumentLexer::string()
{
    bool terminated = false;
    consume(); // eat "

    while (nextExists() && !terminated)
    {
        if (matchNext('\\'))
        {
            // escape sequence
            consume(); // eat reverse solidus

            switch (next())
            {
                case 'a':  // alert
                case 'b':  // backspace
                case 'e':  //
                case '?':  // question mark
                case '\'': // apostrophe
                case '"':  // solidus
                case '\\': // reverse solidus
                case 'n':  // linefeed
                case 't':  // horizontal tab
                case 'v':  // vertical tab
                case 'r':  // carriage return
                case 'f':  // formfeed
                {
                    consume(); // eat escape sequence
                    break;
                }
                case 'u':
                {
                    // unicode (under 1000)
                    // TODO do unicode
                    break;
                }
                case 'U':
                {
                    // unicode
                    // TODO do unicode
                    break;
                }
                default:
                {
                    if (matchNext(compiler::lexer_digit))
                    {
                        // TODO octal
                    }
                    else if (nextExists())
                        reportError(HVM_COMPILE_ERROR_UNKNOWN_ESCAPE_SEQUENCE);
                    else
                        abrupt();
                }
            }
        }
        else if (matchNext('"'))
        {
            consume(); // eat "
            terminated = true;
        }
        else
            consume(); // eat any
    }

    if (!terminated)
        reportError(HVM_COMPILE_ERROR_UNTERMINATED_STRING_LITERAL);

    return flush(string_tkn);
}

/**
 *
 */
compiler::Token
PDocumentLexer::tpl()
{
    consume(); // eat @
    consume(); // eat "
    return flush(template_tkn);
}

compiler::Token
PDocumentLexer::did()
{
    // eat @ and consume characters
    do
        consume();
    while (matchNext(compiler::lexer_identifier));
    return flush(identity_tkn);
}

compiler::Token
PDocumentLexer::com()
{
    // mult-line comment
    uint32_t depth = 1;
    consume(); // eat /
    consume(); // eat *

    while (hasNext())
    {
        if (matchNext('*') && matchLa('/', 2))
        {
            consume();
            consume();
            depth--;
            if (depth == 0)
                break;
        }
        else if (matchNext('/') && matchLa('*', 2))
        {
            consume();
            consume();
            depth++;
        }
        else
            consume(); // eat any
    }

    return flush(mcomment_tkn);
}

compiler::Token
PDocumentLexer::readNext()
{
    if (isEof(1))
    {
        // eof
        consume();
        return flush(eof_tkn);
    }
    else if (matchNext('\t'))
    {
        reportError("Tab characters are not allowed. Use four spaces to represent a tab.");
    }
    else if (matchNext('\n'))
    {
        // linefeed
        consume();
        return flush(ln_tkn);
    }
    else if (predictTab())
    {
        consume(4);
        return flush(tab_tkn);
    }
    else if (matchNext(drip_ws))
    {
        do
            consume();
        while (matchNext(drip_ws));

        return flush(ws_tkn);
    }
    else if (matchNext(id_tkn))
        return id();
    else if (predictDouble(false))
        return dbl();
    else if (matchNext(compiler::lexer_digit))
    {
        reportError(HVM_COMPILE_ERROR_INVALID_NUMBER_SYNTAX);
    }
    else if (matchNext('"')) // assume string literal
        return string();
    else if (matchNext('@') && matchLa('"', 2)) // assume string template
        return tpl();
    else if (matchNext('@') && matchLa(compiler::lexer_identifier, 2))
        return did(); // drip identity
    else if (matchNext('/') && matchLa('*', 2))
        return com(); // comment

    if (mState == engine_parse_expression)
    {
        if (compiler::Token op = devour(op_tkn))
            return op;
    }
    else if (compiler::Token token = devour(token_tkn))
        return token;

    consume();
    return flush(token_tkn);
}

} // namespace hydro::engine
