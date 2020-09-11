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

#include "Identifier.hpp"

namespace hydro::compiler
{
Identifier::Identifier(AST *owner) : Expression{owner}
{
    value = nullptr;
}

Identifier::~Identifier()
{
}

void Identifier::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
