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

#include "SetterDeclaration.hpp"

namespace hydro::compiler
{
SetterDeclaration::SetterDeclaration(AST *owner) : BodyDeclaration{owner}
{
    nameOfValue = nullptr;
}

SetterDeclaration::~SetterDeclaration()
{
}

void SetterDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
