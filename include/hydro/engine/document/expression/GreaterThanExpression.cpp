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

#include "GreaterThanExpression.hpp"

namespace hydro::engine
{

GreaterThanExpression::GreaterThanExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

GreaterThanExpression::~GreaterThanExpression()
{
}

} // namespace hydro::engine
