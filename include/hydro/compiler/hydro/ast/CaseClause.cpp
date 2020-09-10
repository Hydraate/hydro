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

#include "CaseClause.hpp"

namespace hydro::compiler
{
CaseClause::CaseClause(AST *owner) : Statement{owner}
{
    expression = nullptr;
}

CaseClause::~CaseClause()
{
}

void CaseClause::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
