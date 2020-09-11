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

#include "ForEachStatement.hpp"

namespace hydro::compiler
{
ForEachStatement::ForEachStatement(AST *owner) : Statement{owner}
{
    variable = nullptr;
    expression = nullptr;
}

ForEachStatement::~ForEachStatement()
{
}

void ForEachStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
