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

#ifndef __h3o_LambdaExpression__
#define __h3o_LambdaExpression__

#include "FunctionArgumentsList.hpp"

namespace hydro::compiler
{
class LambdaExpression final : public Expression
{
public:
    FunctionArgumentsList *arguments;

    LambdaExpression(AST *owner);
    virtual ~LambdaExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_LambdaExpression__ */
