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

#include "PositiveExpression.hpp"

namespace hydro::engine
{

PositiveExpression::PositiveExpression(Expression *expression) : UnaryExpression{ expression }
{
}

PositiveExpression::~PositiveExpression()
{
}

} // namespace hydro::engine
