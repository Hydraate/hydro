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

#include "AdditionExpression.hpp"

namespace hydro::engine
{

AdditionExpression::AdditionExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

AdditionExpression::~AdditionExpression()
{
}

} // namespace hydro::engine
