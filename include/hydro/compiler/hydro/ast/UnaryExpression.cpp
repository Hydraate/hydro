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

#include "UnaryExpression.hpp"

namespace hydro::compiler
{
UnaryExpression::UnaryExpression(AST *owner) : Expression{owner}
{
    expression = nullptr;
}

UnaryExpression::~UnaryExpression()
{
}

void UnaryExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
