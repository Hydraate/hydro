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

#ifndef __h3o_SuperConstructorInvocation__
#define __h3o_SuperConstructorInvocation__

#include "Invocation.hpp"

namespace hydro::compiler
{
class SuperConstructorInvocation final : public Invocation
{
public:
    SuperConstructorInvocation(AST *owner);
    virtual ~SuperConstructorInvocation();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_SuperConstructorInvocation__ */
