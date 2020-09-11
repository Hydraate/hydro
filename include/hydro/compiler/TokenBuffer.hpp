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

#ifndef __h3o_TokenBuffer__
#define __h3o_TokenBuffer__

#include <memory>
#include <vector>

#include "Token.hpp"

namespace hydro::compiler
{
/**
 * The TokenBuffer class stores tokens in order to perform operations related to a group of tokens.
 */
class TokenBuffer final
{
public:
    /**
     * Creates an empty TokenBuffer object.
     */
    TokenBuffer();

    /**
     * Creates a copy of a TokenBuffer object using value semantics.
     * @param buffer The TokenBuffer object to copy.
     */
    TokenBuffer(const TokenBuffer &buffer);

    /**
     * Creates a copy of a TokenBuffer object using move semantics.
     * @param buffer The TokenBuffer object to copy.
     */
    TokenBuffer(TokenBuffer &&buffer);

    /**
     * Destroys the TokenBuffer object.
     */
    ~TokenBuffer();

    /**
     * Specifies whether or not the token buffer is empty.
     * @return Returns true if the buffer is empty. Otherwise returns false.
     */
    bool empty() const { return mContent->buffer.empty(); }

    /**
     * Reports the size of the buffer.
     */
    std::size_t size() const { return mContent->buffer.size(); }

    /**
     * Sets the TokenBuffer object to another using value semantics.
     * @param rhs The right-hand side of the assignment operator.
     * @return Returns a reference to itself.
     */
    TokenBuffer &operator=(const TokenBuffer &rhs);

    /**
     * Sets the TokenBuffer object to another using move semantics.
     * @param rhs The right-hand side of the assignment operator.
     * @return Returns a reference to itself.
     */
    TokenBuffer &operator=(TokenBuffer &&rhs);

    /**
     * Gets a reference to the token at a particular index.
     * @param index The token index to access.
     */
    Token &operator[](std::size_t index) const { return mContent->buffer[index]; }

private:
    struct token_buffer
    {
        std::vector<Token> buffer;
    };

    /**
     * A sharable token buffer.
     */
    std::shared_ptr<token_buffer> mContent;
};

} // namespace hydro::compiler

#endif /* __h3o_TokenBuffer__ */
