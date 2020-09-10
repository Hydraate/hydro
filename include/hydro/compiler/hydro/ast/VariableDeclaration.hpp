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

#ifndef __h3o_VariableDeclaration__
#define __h3o_VariableDeclaration__

#include "Declaration.hpp"
#include "Expression.hpp"
#include "SimpleName.hpp"
#include "Statement.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class VariableDeclaration : public Statement, public Declaration
{
public:
    SimpleName *name;
    TypeSpecifier *type;
    Expression *initialValue;

    VariableDeclaration(AST *owner);
    virtual ~VariableDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_VariableDeclaration__ */
