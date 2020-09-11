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

#include "HexadecimalLiteral.hpp"

namespace hydro::compiler
{
HexadecimalLiteral::HexadecimalLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

HexadecimalLiteral::~HexadecimalLiteral() {}

void HexadecimalLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
