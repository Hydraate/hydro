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

#ifndef __h3o_internal_Undefined__
#define __h3o_internal_Undefined__

#include "Expression.hpp"

namespace hydro::compiler
{
class Undefined final : public Expression
{
public:
    Undefined(AST *owner);
    virtual ~Undefined();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_Undefined__ */
