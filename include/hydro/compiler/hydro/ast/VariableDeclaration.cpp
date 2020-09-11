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

#include "VariableDeclaration.hpp"

namespace hydro::compiler
{
VariableDeclaration::VariableDeclaration(AST *owner) : Statement{owner}
{
    name = nullptr;
    type = nullptr;
    initialValue = nullptr;
}

VariableDeclaration::~VariableDeclaration()
{
}

void VariableDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
