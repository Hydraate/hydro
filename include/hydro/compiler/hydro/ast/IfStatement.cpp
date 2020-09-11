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

#include "IfStatement.hpp"

namespace hydro::compiler
{
IfStatement::IfStatement(AST *owner) : Statement{owner}
{
    condition = nullptr;
    elseStatement = nullptr;
}

IfStatement::~IfStatement()
{
}

void IfStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
