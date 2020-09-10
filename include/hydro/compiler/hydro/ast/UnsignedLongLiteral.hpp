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

#ifndef __h3o_UnsignedLongLiteral__
#define __h3o_UnsignedLongLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class UnsignedLongLiteral final : public Expression
{
public:
    uint64_t value;

    UnsignedLongLiteral(AST *owner);
    virtual ~UnsignedLongLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_UnsignedLongLiteral__ */
