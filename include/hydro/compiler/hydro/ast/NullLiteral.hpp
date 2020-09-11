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

#ifndef __h3o_NullLiteral__
#define __h3o_NullLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class NullLiteral final : public Expression
{
public:
    NullLiteral(AST *owner);
    virtual ~NullLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_NullLiteral__ */
