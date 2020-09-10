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

#include "PropertyDeclaration.hpp"

namespace hydro::compiler
{
PropertyDeclaration::PropertyDeclaration(AST *owner) : VariableDeclaration{owner}
{
    name = nullptr;
    type = nullptr;
    initialValue = nullptr;
}

PropertyDeclaration::~PropertyDeclaration()
{
}

void PropertyDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
