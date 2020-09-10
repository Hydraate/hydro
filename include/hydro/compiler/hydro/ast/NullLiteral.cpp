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

#include "NullLiteral.hpp"

namespace hydro::compiler
{
NullLiteral::NullLiteral(AST *owner) : Expression{owner} {}

NullLiteral::~NullLiteral() {}

void NullLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
