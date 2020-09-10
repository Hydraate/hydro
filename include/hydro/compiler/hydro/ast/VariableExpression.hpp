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

#ifndef __h3o_internal_VariableExpression__
#define __h3o_internal_VariableExpression__

#include "Declaration.hpp"
#include "Expression.hpp"
#include "SimpleName.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class VariableExpression final : public Expression, public Declaration
{
public:
    SimpleName *name;
    TypeSpecifier *type;

    VariableExpression(AST *owner);
    virtual ~VariableExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_VariableExpression__ */
