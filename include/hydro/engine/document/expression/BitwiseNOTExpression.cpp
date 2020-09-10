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

#include "BitwiseNOTExpression.hpp"

namespace hydro::engine
{

BitwiseNOTExpression::BitwiseNOTExpression(Expression *expression) : UnaryExpression{ expression }
{
}

BitwiseNOTExpression::~BitwiseNOTExpression()
{
}

} // namespace hydro::engine
