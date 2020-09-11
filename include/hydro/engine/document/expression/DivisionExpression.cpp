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

#include "DivisionExpression.hpp"

namespace hydro::engine
{

DivisionExpression::DivisionExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

DivisionExpression::~DivisionExpression()
{
}

} // namespace hydro::engine
