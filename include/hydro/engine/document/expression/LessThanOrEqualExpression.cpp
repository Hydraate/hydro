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

#include "LessThanOrEqualExpression.hpp"

namespace hydro::engine
{

LessThanOrEqualExpression::LessThanOrEqualExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

LessThanOrEqualExpression::~LessThanOrEqualExpression()
{
}

} // namespace hydro::engine
