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

#include "VariableExpression.hpp"

namespace hydro::compiler
{
VariableExpression::VariableExpression(AST *owner) : Expression{owner}
{
    name = nullptr;
    type = nullptr;
}

VariableExpression::~VariableExpression()
{
}

void VariableExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
