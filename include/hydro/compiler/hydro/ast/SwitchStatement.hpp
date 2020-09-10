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

#ifndef __h3o_SwitchStatement__
#define __h3o_SwitchStatement__

#include <list>

#include "CaseClause.hpp"
#include "DefaultClause.hpp"

namespace hydro::compiler
{
class SwitchStatement final : public Statement
{
public:
    SwitchStatement(AST *owner);
    virtual ~SwitchStatement();
    virtual void accept(ASTVisitor *visitor) override;
    void append(CaseClause *clause);
    void append(DefaultClause *clause);
    const std::list<Statement *> &clauses() const { return m_clauses; }

private:
    std::list<Statement *> m_clauses;
};

} // namespace hydro::compiler

#endif /* SwitchStatement_hpp */
