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

#ifndef __h3o_BinaryLiteral__
#define __h3o_BinaryLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class BinaryLiteral final : public Expression
{
public:
    int32_t value;

    BinaryLiteral(AST *owner);
    virtual ~BinaryLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_BinaryLiteral__ */
