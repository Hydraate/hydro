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

#include "PackageDeclaration.hpp"

namespace hydro::compiler
{
PackageDeclaration::PackageDeclaration(AST *owner) : Statement{owner}
{
    name = nullptr;
}

PackageDeclaration::~PackageDeclaration()
{
}

void PackageDeclaration::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
