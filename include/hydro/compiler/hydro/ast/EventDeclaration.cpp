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

#include "EventDeclaration.hpp"

namespace hydro::compiler
{
EventDeclaration::EventDeclaration(AST *owner) : BodyDeclaration{owner}
{
    name = nullptr;
}

EventDeclaration::~EventDeclaration()
{
}

void EventDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
