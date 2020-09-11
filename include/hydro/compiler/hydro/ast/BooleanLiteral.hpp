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

#ifndef __h3o_BooleanLiteral__
#define __h3o_BooleanLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class BooleanLiteral final : public Expression
{
public:
    bool value;

    BooleanLiteral(AST *owner);
    virtual ~BooleanLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_BooleanLiteral__ */
