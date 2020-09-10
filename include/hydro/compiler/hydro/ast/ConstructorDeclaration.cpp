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

#include "ConstructorDeclaration.hpp"

namespace hydro::compiler
{
ConstructionDeclaration::ConstructionDeclaration(AST *owner) : FunctionDeclaration{owner} {}

ConstructionDeclaration::~ConstructionDeclaration() {}

void ConstructionDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
