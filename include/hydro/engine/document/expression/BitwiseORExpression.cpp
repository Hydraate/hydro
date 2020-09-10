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

#include "BitwiseORExpression.hpp"

namespace hydro::engine
{

BitwiseORExpression::BitwiseORExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

BitwiseORExpression::~BitwiseORExpression()
{
}

} // namespace hydro::engine
