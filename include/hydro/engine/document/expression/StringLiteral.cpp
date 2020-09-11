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

#include "StringLiteral.hpp"

namespace hydro::engine
{
StringLiteral::StringLiteral(compiler::Token token) : Expression{token}
{
}

StringLiteral::~StringLiteral()
{
}

} // namespace hydro::engine
