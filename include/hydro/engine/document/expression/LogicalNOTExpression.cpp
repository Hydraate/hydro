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

#include "LogicalNOTExpression.hpp"

namespace hydro::engine
{

LogicalNOTExpression::LogicalNOTExpression(Expression *expression) : UnaryExpression{ expression }
{
}

LogicalNOTExpression::~LogicalNOTExpression()
{
}

} // namespace hydro::engine
