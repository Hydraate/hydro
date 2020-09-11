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

#include "EventTypeDeclaration.hpp"

namespace hydro::compiler
{
EventTypeDeclaration::EventTypeDeclaration(AST *owner) : Statement{owner}
{
    name = nullptr;
}

EventTypeDeclaration::~EventTypeDeclaration()
{
}

void EventTypeDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
