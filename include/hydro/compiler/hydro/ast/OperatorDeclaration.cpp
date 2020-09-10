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

#include "OperatorDeclaration.hpp"

namespace hydro::compiler
{
OperatorDeclaration::OperatorDeclaration(AST *owner) : BodyDeclaration{owner}
{
    _operator = nullptr;
}

OperatorDeclaration::~OperatorDeclaration()
{
}

void OperatorDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
