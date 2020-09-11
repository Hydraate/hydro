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

#include "MemberAccess.hpp"

namespace hydro::engine
{
MemberAccess::MemberAccess(Expression *lhs, Expression *rhs)
    : BinaryExpression{lhs, rhs}
{
}

MemberAccess::~MemberAccess()
{
}

} // namespace hydro::engine
