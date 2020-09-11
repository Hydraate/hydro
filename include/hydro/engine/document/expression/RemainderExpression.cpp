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

#include "RemainderExpression.hpp"

namespace hydro::engine
{

RemainderExpression::RemainderExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

RemainderExpression::~RemainderExpression()
{
}

} // namespace hydro::engine
