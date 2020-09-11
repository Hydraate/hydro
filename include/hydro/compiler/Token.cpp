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

#include "Token.hpp"

namespace hydro::compiler
{
Token::Token() {}

Token::Token(SourcePosition pos, std::string value, int32_t type) : mToken{new token_data{pos, value, type}}
{
}

Token::Token(const Token &token) : mToken{token.mToken} {}

Token::Token(Token &&token) : mToken{token.mToken} {}

Token::Token(std::nullptr_t)
{
}

Token::~Token() {}

Token &Token::operator=(const Token &rhs)
{
    mToken = rhs.mToken;
    return (*this);
}

Token &Token::operator=(Token &&rhs)
{
    mToken = rhs.mToken;
    return (*this);
}

bool Token::operator==(const Token &rhs) const
{
    return mToken == rhs.mToken;
}

bool Token::operator==(const std::nullptr_t &rhs) const
{
    return mToken == nullptr;
}

bool Token::operator!=(const Token &rhs) const
{
    return mToken != rhs.mToken;
}

bool Token::operator!=(const std::nullptr_t &rhs) const
{
    return mToken != nullptr;
}

} // namespace hydro::compiler
