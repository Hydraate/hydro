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

#include "LambdaExpression.hpp"

namespace hydro::compiler
{
LambdaExpression::LambdaExpression(AST *owner) : Expression{owner}
{
    arguments = nullptr;
}

LambdaExpression::~LambdaExpression()
{
}

void LambdaExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
