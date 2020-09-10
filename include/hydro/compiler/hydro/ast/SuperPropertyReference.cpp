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

#include "SuperPropertyReference.hpp"

namespace hydro::compiler
{
SuperPropertyReference::SuperPropertyReference(AST *owner) : Expression{owner}
{
}

SuperPropertyReference::~SuperPropertyReference()
{
}

void SuperPropertyReference::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
