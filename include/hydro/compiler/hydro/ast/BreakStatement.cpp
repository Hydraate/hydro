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

#include "BreakStatement.hpp"

namespace hydro::compiler
{
BreakStatement::BreakStatement(AST *owner) : Statement{owner}
{
    depth = 1;
}

BreakStatement::~BreakStatement() {}

void BreakStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
