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

#ifndef __h3o_RegularExpressionLiteral__
#define __h3o_RegularExpressionLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class RegularExpressionLiteral : public Expression
{
public:
    RegularExpressionLiteral(AST *owner);
    virtual ~RegularExpressionLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_RegularExpressionLiteral__ */
