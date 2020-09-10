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

#include "ThisExpression.hpp"

namespace hydro::compiler
{
ThisExpression::ThisExpression(AST *owner) : Expression{owner} {}

ThisExpression::~ThisExpression() {}

void ThisExpression::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
