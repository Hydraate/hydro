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

#include "LogicalORExpression.hpp"

namespace hydro::engine
{

LogicalORExpression::LogicalORExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

LogicalORExpression::~LogicalORExpression()
{
}

} // namespace hydro::engine
