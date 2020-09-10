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

#include "WhileStatement.hpp"

namespace hydro::compiler
{
WhileStatement::WhileStatement(AST *owner) : Statement{owner}
{
    condition = nullptr;
    body = nullptr;
}

WhileStatement::~WhileStatement()
{
}

void WhileStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
