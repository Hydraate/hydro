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

#include "BooleanLiteral.hpp"

namespace hydro::compiler
{
BooleanLiteral::BooleanLiteral(AST *owner) : Expression{owner}
{
    value = false;
}

BooleanLiteral::~BooleanLiteral() {}

void BooleanLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
