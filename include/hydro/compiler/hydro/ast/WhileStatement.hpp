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

#ifndef __h3o_WhileStatement__
#define __h3o_WhileStatement__

#include "Expression.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class WhileStatement : public Statement
{
public:
    Expression *condition;
    Statement *body;

    WhileStatement(AST *owner);
    virtual ~WhileStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_WhileStatement__ */
