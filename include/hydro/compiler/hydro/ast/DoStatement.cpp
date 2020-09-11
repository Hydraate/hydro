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

#include "DoStatement.hpp"

namespace hydro::compiler
{
DoStatement::DoStatement(AST *owner) : Statement{owner}
{
    condition = nullptr;
}

DoStatement::~DoStatement()
{
}

void DoStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
