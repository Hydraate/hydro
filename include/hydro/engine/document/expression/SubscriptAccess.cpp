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

#include "SubscriptAccess.hpp"

namespace hydro::engine
{

SubscriptAccess::SubscriptAccess(Expression *lhs, compiler::Token token, Expression *rhs) : BinaryExpression{ lhs, token, rhs }
{
}

SubscriptAccess::~SubscriptAccess()
{
}

} // namespace hydro::engine
