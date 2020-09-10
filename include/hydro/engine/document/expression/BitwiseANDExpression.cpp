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

#include "BitwiseANDExpression.hpp"

namespace hydro::engine
{

BitwiseANDExpression::BitwiseANDExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

BitwiseANDExpression::~BitwiseANDExpression()
{
}

} // namespace hydro::engine
