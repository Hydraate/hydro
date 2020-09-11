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

#ifndef __h3o_UnsignedShortLiteral__
#define __h3o_UnsignedShortLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class UnsignedShortLiteral final : public Expression
{
public:
    uint16_t value;

    UnsignedShortLiteral(AST *owner);
    virtual ~UnsignedShortLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_UnsignedShortLiteral__ */
