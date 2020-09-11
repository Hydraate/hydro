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

#include "NestedExpression.hpp"

namespace hydro::engine
{
NestedExpression::NestedExpression(compiler::Token token, Expression *expression)
    : Expression{ token }
{
    mExpression = expression;
}

NestedExpression::~NestedExpression()
{
}

} // namespace hydro::engine
