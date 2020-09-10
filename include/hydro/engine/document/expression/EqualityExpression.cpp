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

#include "EqualityExpression.hpp"

namespace hydro::engine
{

EqualityExpression::EqualityExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

EqualityExpression::~EqualityExpression()
{
}

} // namespace hydro::engine
