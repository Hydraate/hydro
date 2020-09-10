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

#ifndef __h3o_DoubleLiteral__
#define __h3o_DoubleLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class DoubleLiteral final : public Expression
{
public:
    double value;

    DoubleLiteral(AST *owner);
    virtual ~DoubleLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_DoubleLiteral__ */
