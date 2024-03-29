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

#ifndef __h3o_UnaryExpression__
#define __h3o_UnaryExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class UnaryExpression : public Expression
{
public:
    Expression *expression;

    UnaryExpression(AST *owner);
    virtual ~UnaryExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_UnaryExpression__ */
