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

#include "BitwiseLeftShiftExpression.hpp"

namespace hydro::engine
{

BitwiseLeftShiftExpression::BitwiseLeftShiftExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs}
{
}

BitwiseLeftShiftExpression::~BitwiseLeftShiftExpression()
{
}

} // namespace hydro::engine
