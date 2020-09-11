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

#include "StateDeclaration.hpp"

namespace hydro::compiler
{
StateDeclaration::StateDeclaration(AST *owner) : BodyDeclaration{owner} {}

StateDeclaration::~StateDeclaration() {}

void StateDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
