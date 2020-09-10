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

#include "MultiplicationExpression.hpp"

namespace hydro::engine
{

MultiplicationExpression::MultiplicationExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

MultiplicationExpression::~MultiplicationExpression()
{
}

} // namespace hydro::engine
