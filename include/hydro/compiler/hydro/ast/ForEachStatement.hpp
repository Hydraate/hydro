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

#ifndef __h3o_ForEachStatement__
#define __h3o_ForEachStatement__

#include "Expression.hpp"
#include "Statement.hpp"
#include "VariableFragment.hpp"

namespace hydro::compiler
{
class ForEachStatement : public Statement
{
public:
    VariableFragment *variable;
    Expression *expression;

    ForEachStatement(AST *owner);
    virtual ~ForEachStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ForEachStatement__ */
