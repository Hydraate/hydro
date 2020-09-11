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

#ifndef __h3o_TernaryExpression__
#define __h3o_TernaryExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class TernaryExpression : public Expression
{
public:
    Expression *condition;
    Expression *trueExpression;
    Expression *falseExpression;

    TernaryExpression(AST *owner);
    virtual ~TernaryExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_TernaryExpression__ */
