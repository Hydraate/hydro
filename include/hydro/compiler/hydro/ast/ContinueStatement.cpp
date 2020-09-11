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

#include "ContinueStatement.hpp"

namespace hydro::compiler
{
ContinueStatement::ContinueStatement(AST *owner) : Statement{owner}
{
    depth = 1;
}

ContinueStatement::~ContinueStatement() {}

void ContinueStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
