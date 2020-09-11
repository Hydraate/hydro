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

#include "SuperMethodInvocation.hpp"

namespace hydro::compiler
{
SuperMethodInvocation::SuperMethodInvocation(AST *owner) : Invocation{owner}
{
}

SuperMethodInvocation::~SuperMethodInvocation() {}

void SuperMethodInvocation::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
