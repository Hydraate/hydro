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

#include "LessThanExpression.hpp"

namespace hydro::engine
{

LessThanExpression::LessThanExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

LessThanExpression::~LessThanExpression()
{
}

} // namespace hydro::engine
