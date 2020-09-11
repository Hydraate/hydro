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

#include "MethodDeclaration.hpp"

namespace hydro::compiler
{
MethodDeclaration::MethodDeclaration(AST *owner) : Statement{owner}
{
    name = nullptr;
    arguments = nullptr;
    returnType = nullptr;
}

MethodDeclaration::~MethodDeclaration()
{
}

void MethodDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
