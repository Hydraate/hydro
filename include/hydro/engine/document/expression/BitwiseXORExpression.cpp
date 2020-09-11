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

#include "BitwiseXORExpression.hpp"

namespace hydro::engine
{

BitwiseXORExpression::BitwiseXORExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

BitwiseXORExpression::~BitwiseXORExpression()
{
}

} // namespace hydro::engine
