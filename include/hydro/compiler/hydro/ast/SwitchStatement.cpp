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

#include "SwitchStatement.hpp"

namespace hydro::compiler
{
SwitchStatement::SwitchStatement(AST *owner) : Statement{owner} {}

SwitchStatement::~SwitchStatement() {}

void SwitchStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void SwitchStatement::append(CaseClause *clause)
{
    m_clauses.push_back(clause);
}

void SwitchStatement::append(DefaultClause *clause)
{
    m_clauses.push_back(clause);
}

} // namespace hydro::compiler
