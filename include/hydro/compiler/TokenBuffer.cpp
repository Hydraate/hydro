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

#include "TokenBuffer.hpp"

namespace hydro::compiler
{
TokenBuffer::TokenBuffer() : mContent{new token_buffer{}}
{
}

TokenBuffer::TokenBuffer(const TokenBuffer &buffer) : mContent{buffer.mContent}
{
}

TokenBuffer::TokenBuffer(TokenBuffer &&buffer) : mContent{buffer.mContent}
{
}

TokenBuffer::~TokenBuffer()
{
}

TokenBuffer &TokenBuffer::operator=(const TokenBuffer &rhs)
{
    return (*this);
}

TokenBuffer &TokenBuffer::operator=(TokenBuffer &&rhs)
{
    return (*this);
}

} // namespace hydro::compiler
