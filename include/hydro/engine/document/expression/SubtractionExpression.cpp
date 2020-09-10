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

#include "SubtractionExpression.hpp"

namespace hydro::engine
{

SubtractionExpression::SubtractionExpression(Expression *lhs, Expression *rhs) : BinaryExpression{ lhs, rhs }
{
}

SubtractionExpression::~SubtractionExpression()
{
}

} // namespace hydro::engine
