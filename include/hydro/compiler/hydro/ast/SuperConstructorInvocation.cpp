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

#include "SuperConstructorInvocation.hpp"

namespace hydro::compiler
{
SuperConstructorInvocation::SuperConstructorInvocation(AST *owner) : Invocation{owner} {}

SuperConstructorInvocation::~SuperConstructorInvocation() {}

void SuperConstructorInvocation::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
