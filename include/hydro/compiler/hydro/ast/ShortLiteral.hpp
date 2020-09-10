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

#ifndef __h3o_ShortLiteral__
#define __h3o_ShortLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class ShortLiteral final : public Expression
{
public:
    int16_t value;
    ShortLiteral(AST *owner);
    virtual ~ShortLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ShortLiteral__ */
