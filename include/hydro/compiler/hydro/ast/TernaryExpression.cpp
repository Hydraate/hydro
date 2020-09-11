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

#include "TernaryExpression.hpp"

namespace hydro::compiler
{
TernaryExpression::TernaryExpression(AST *owner) : Expression{owner}
{
    condition = trueExpression = falseExpression = nullptr;
}

TernaryExpression::~TernaryExpression()
{
}

void TernaryExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
