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

#include "CatchClause.hpp"

namespace hydro::compiler
{
CatchClause::CatchClause(AST *owner) : Statement{owner}
{
    variable = nullptr;
}

CatchClause::~CatchClause()
{
}

void CatchClause::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
