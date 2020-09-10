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

#include "EventParameterDeclaration.hpp"

namespace hydro::compiler
{
EventParameterDeclaration::EventParameterDeclaration(AST *owner) : Statement{owner}
{
    name = nullptr;
    type = nullptr;
    defaultValue = nullptr;
}

EventParameterDeclaration::~EventParameterDeclaration()
{
}

void EventParameterDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
