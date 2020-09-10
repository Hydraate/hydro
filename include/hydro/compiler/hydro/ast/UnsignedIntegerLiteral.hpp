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

#ifndef __h3o_UnsignedIntegerLiteral__
#define __h3o_UnsignedIntegerLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class UnsignedIntegerLiteral final : public Expression
{
public:
    uint32_t value;
    UnsignedIntegerLiteral(AST *owner);
    virtual ~UnsignedIntegerLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_UnsignedIntegerLiteral__ */
