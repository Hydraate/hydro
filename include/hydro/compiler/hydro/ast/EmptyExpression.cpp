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

#include "EmptyExpression.hpp"

namespace hydro::compiler
{
EmptyExpression::EmptyExpression(AST *owner) : Expression{owner} {}

EmptyExpression::~EmptyExpression() {}

void EmptyExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
