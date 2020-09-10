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

#include "BinaryExpression.hpp"

namespace hydro::compiler
{
BinaryExpression::BinaryExpression(AST *owner) : Expression{owner}
{
    lhs = rhs = nullptr;
}

BinaryExpression::~BinaryExpression()
{
}

void BinaryExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
