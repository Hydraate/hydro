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

#include "PostfixExpression.hpp"

namespace hydro::compiler
{
PostfixExpression::PostfixExpression(AST *owner) : UnaryExpression{owner}
{
}

PostfixExpression::~PostfixExpression() {}

} // namespace hydro::compiler
