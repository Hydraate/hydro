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

#include "GreaterThanOrEqualExpression.hpp"

namespace hydro::engine
{

GreaterThanOrEqualExpression::GreaterThanOrEqualExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

GreaterThanOrEqualExpression::~GreaterThanOrEqualExpression()
{
}

} // namespace hydro::engine
