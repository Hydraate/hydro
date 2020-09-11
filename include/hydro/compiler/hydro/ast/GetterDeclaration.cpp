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

#include "GetterDeclaration.hpp"

namespace hydro::compiler
{
GetterDeclaration::GetterDeclaration(AST *owner) : BodyDeclaration{owner}
{
    valueName = nullptr;
}

GetterDeclaration::~GetterDeclaration()
{
}

void GetterDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
