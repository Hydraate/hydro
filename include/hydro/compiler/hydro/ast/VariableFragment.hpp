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

#ifndef __h3o_VariableFragment__
#define __h3o_VariableFragment__

#include "ASTNode.hpp"
#include "Declaration.hpp"
#include "SimpleName.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class VariableFragment : public ASTNode, public Declaration
{
public:
    SimpleName *name;
    TypeSpecifier *type;

    VariableFragment(AST *owner);
    virtual ~VariableFragment();
    virtual void accept(ASTVisitor *visitor) override;
};
} // namespace hydro::compiler

#endif /* __h3o_VariableFragment__ */
