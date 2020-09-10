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

#include "ConditionalExpression.hpp"

namespace hydro::engine
{

ConditionalExpression::ConditionalExpression(Expression *condition, Expression *trueExpression, Expression *falseExpression) : Expression{}
{
}

ConditionalExpression::~ConditionalExpression()
{
}

} // namespace hydro::engine
