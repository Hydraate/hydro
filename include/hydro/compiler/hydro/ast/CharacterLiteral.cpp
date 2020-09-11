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

#include "CharacterLiteral.hpp"

namespace hydro::compiler
{
CharacterLiteral::CharacterLiteral(AST *owner) : Expression{owner}
{
    value = '\0';
}

CharacterLiteral::~CharacterLiteral() {}

void CharacterLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
