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

#include "ExpressionStatement.hpp"

namespace hydro::compiler
{
ExpressionStatement::ExpressionStatement(AST *owner) : Statement{owner}
{
    expression = nullptr;
}

ExpressionStatement::~ExpressionStatement()
{
}

void ExpressionStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
