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

#ifndef __h3o_ForStatement__
#define __h3o_ForStatement__

#include "Expression.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class ForStatement : public Statement
{
public:
    Expression *initializer;
    Expression *condition;
    Expression *iterator;
    Statement *body;

    ForStatement(AST *owner);
    virtual ~ForStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ForStatement__ */
