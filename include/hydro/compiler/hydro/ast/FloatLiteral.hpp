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

#ifndef __h3o_FloatLiteral__
#define __h3o_FloatLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class FloatLiteral : public Expression
{
public:
    float value;

    FloatLiteral(AST *owner);
    virtual ~FloatLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_FloatLiteral__ */
