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

#include "ExponentiationExpression.hpp"

namespace hydro::engine
{

ExponentiationExpression::ExponentiationExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

ExponentiationExpression::~ExponentiationExpression()
{
}

} // namespace hydro::engine
