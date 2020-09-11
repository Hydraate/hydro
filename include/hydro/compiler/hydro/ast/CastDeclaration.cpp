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

#include "CastDeclaration.hpp"

namespace hydro::compiler
{
CastDeclaration::CastDeclaration(AST *owner) : BodyDeclaration{owner}
{
    target = nullptr;
}

CastDeclaration::~CastDeclaration()
{
}

void CastDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
