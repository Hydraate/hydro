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

#ifndef __h3o_BinaryExpression__
#define __h3o_BinaryExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class BinaryExpression : public Expression
{
public:
    Expression *lhs;
    Expression *rhs;
    BinaryExpression(AST *owner);
    virtual ~BinaryExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_BinaryExpression__ */
