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

#include "BooleanLiteral.hpp"

namespace hydro::engine
{
BooleanLiteral::BooleanLiteral(compiler::Token token) : Expression{token}
{
}

BooleanLiteral::~BooleanLiteral()
{
}

} // namespace hydro::engine
