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

#ifndef __h3o_CatchClause__
#define __h3o_CatchClause__

#include "Statement.hpp"
#include "VariableFragment.hpp"

namespace hydro::compiler
{
class CatchClause final : public Statement
{
public:
    VariableFragment *variable;

    CatchClause(AST *owner);
    virtual ~CatchClause();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_CatchClause__ */
