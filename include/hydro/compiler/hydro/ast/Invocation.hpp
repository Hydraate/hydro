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

#ifndef __h3o_Invocation__
#define __h3o_Invocation__

#include "Expression.hpp"
#include "InvocationArguments.hpp"

namespace hydro::compiler
{
class Invocation : public Expression
{
public:
    Expression *target;
    InvocationArguments *arguments;

    Invocation(AST *owner);
    virtual ~Invocation();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_Invocation__ */
