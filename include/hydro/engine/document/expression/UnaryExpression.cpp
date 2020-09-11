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

#include "UnaryExpression.hpp"

namespace hydro::engine
{

UnaryExpression::UnaryExpression(Expression *expression) : Expression{}
{
    mExpression = expression;
}

UnaryExpression::~UnaryExpression()
{
}

} // namespace hydro::engine
