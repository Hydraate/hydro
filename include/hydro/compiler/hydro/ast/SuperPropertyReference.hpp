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

#ifndef __h3o_SuperPropertyReference__
#define __h3o_SuperPropertyReference__

#include "Expression.hpp"

namespace hydro::compiler
{
class SuperPropertyReference : public Expression
{
public:
    SuperPropertyReference(AST *owner);
    virtual ~SuperPropertyReference();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_SuperPropertyReference__ */
