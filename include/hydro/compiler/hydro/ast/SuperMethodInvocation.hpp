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

#ifndef __h3o_SuperMethodInvocation__
#define __h3o_SuperMethodInvocation__

#include "Invocation.hpp"

namespace hydro::compiler
{
class SuperMethodInvocation : public Invocation
{
public:
    SuperMethodInvocation(AST *owner);
    virtual ~SuperMethodInvocation();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_SuperMethodInvocation__ */
