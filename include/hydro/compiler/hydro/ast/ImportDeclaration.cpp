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

#include "ImportDeclaration.hpp"

namespace hydro::compiler
{
ImportDeclaration::ImportDeclaration(AST *owner) : Statement{owner}
{
    target = nullptr;
}

ImportDeclaration::~ImportDeclaration()
{
}

void ImportDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
