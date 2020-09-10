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

#ifndef __h3o_internal_Token__
#define __h3o_internal_Token__

#include <memory>
#include <string>

#include "SourcePosition.hpp"
#include "TokenType.hpp"

namespace hydro::compiler
{
/**
 * The Token class represents a standard language unit (also called lexemes).
 */
class Token final
{
public:
    /**
     * Creates a nil Token object.
     */
    Token(); // default constructor

    /**
     * Creates a Token object with a source position, token value, and token type.
     * @param pos The source position.
     * @param value The token value.
     * @param type The token type.
     */
    Token(SourcePosition pos, std::string value, int32_t type);

    /**
     * Creates a token value
     */
    Token(const Token &token);

    /**
     *
     */
    Token(Token &&token); // move constructor

    /**
     * Creates a nil Token object.
     */
    Token(std::nullptr_t);

    /**
     * Destroys the Token object.
     */
    ~Token();

    static Token eof(SourceID source) { return Token{ SourcePosition{ source, -1, -1, 0, 0 }, std::string{ 1, EOF }, eof_tkn }; }
    
    /**
     * Specifies whether or not the token is nil.
     * @return Returns true if the token does not have a value. Otherwise returns false.
     */
    bool isNil() const { return mToken == nullptr; }

    /**
     * Gets the source position.
     */
    SourcePosition pos() const { return mToken ? mToken->pos : nullptr; }

    /**
     * Gets the token value.
     */
    std::string value() const { return mToken ? mToken->value : ""; }

    /**
     * Gets the token type.
     */
    int32_t type() const { return mToken ? mToken->type : nil_tkn; }

    /**
     * Allows the token to be evaluated to a boolean. The token will evaluate to true if it is not nil. Otherwise the token will evaluate to false.
     */
    operator bool() const { return mToken != nullptr; }

    /**
     * Allows the token to be evaluated to false.
     * @return Returns true if the token is nil. Otherwise returns false.
     */
    bool operator!() const { return mToken == nullptr; }

    /**
     * Sets the token equal to another token using value semantics.
     * @param rhs The token in which to copy.
     * @return Returns a reference to itself.
     */
    Token &operator=(const Token &rhs);

    /**
     * Sets the token equal to another token using move semantics.
     * @param rhs The token in which to copy.
     * @return Returns a reference to itself.
     */
    Token &operator=(Token &&rhs);

    /**
     * Compares this token to another using equality.
     */
    bool operator==(const Token &rhs) const;

    /**
     *
     *
     */
    bool operator==(const std::nullptr_t &rhs) const;

    /**
     *
     *
     */
    bool operator!=(const Token &rhs) const;

    /**
     *
     *
     */
    bool operator!=(const std::nullptr_t &rhs) const;

private:
    /**
     * The token_data struct stores information about a token. Each instance is sharable between Token objects.
     */
    struct token_data
    {
        /**
         * The token's position in the source buffer.
         */
        SourcePosition pos;

        /**
         * The token value.
         */
        std::string value;

        /**
         * The token type.
         */
        int32_t type;
    };

    /**
     * The token data managed by a shared pointer for automatic garbage collection.
     */
    std::shared_ptr<token_data> mToken;
};

/**
 * Improves the readability of code by indicating that a token is nil.
 */
const Token NilToken{};

} // namespace hydro::compiler

#endif /* __h3o_internal_Token__ */
