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

#include "SubscriptExpression.hpp"

namespace hydro::compiler
{
SubscriptExpression::SubscriptExpression(AST *owner) : BinaryExpression{owner} {}

SubscriptExpression::~SubscriptExpression() {}

} // namespace hydro::compiler
