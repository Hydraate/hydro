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

#ifndef __h3o_ThisExpression__
#define __h3o_ThisExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class ThisExpression : public Expression
{
public:
    ThisExpression(AST *owner);
    virtual ~ThisExpression();
    virtual void accept(ASTVisitor *visitor);
};

} // namespace hydro::compiler

#endif /* __h3o_ThisExpression__ */
