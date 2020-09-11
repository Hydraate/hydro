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

#ifndef __h3o_LongLiteral__
#define __h3o_LongLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class LongLiteral final : public Expression
{
public:
    int64_t value;

    LongLiteral(AST *owner);
    virtual ~LongLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_LongLiteral__ */
