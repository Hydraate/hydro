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

#include "ClassDeclaration.hpp"

namespace hydro::compiler
{
ClassDeclaration::ClassDeclaration(AST *owner) : BodyDeclaration{owner}
{
    name = nullptr;
}

ClassDeclaration::~ClassDeclaration()
{
}

void ClassDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void ClassDeclaration::appendParent(Name *parent)
{
    m_parents.push_back(parent);
}

} // namespace hydro::compiler
