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

#include "NestedExpression.hpp"

namespace hydro::compiler
{
NestedExpression::NestedExpression(AST *owner) : Expression{owner}
{
    expression = nullptr;
}

NestedExpression::~NestedExpression()
{
}

void NestedExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
