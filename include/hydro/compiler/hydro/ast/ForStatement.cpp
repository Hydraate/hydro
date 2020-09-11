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

#include "ForStatement.hpp"

namespace hydro::compiler
{
ForStatement::ForStatement(AST *owner) : Statement{owner}
{
    initializer = condition = iterator = nullptr;
    body = nullptr;
}

ForStatement::~ForStatement()
{
}

void ForStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
