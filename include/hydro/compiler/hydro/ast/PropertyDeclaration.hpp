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

#ifndef __h3o_PropertyDeclaration__
#define __h3o_PropertyDeclaration__

#include "Expression.hpp"
#include "Name.hpp"
#include "TypeSpecifier.hpp"
#include "VariableDeclaration.hpp"

namespace hydro::compiler
{
class PropertyDeclaration final : public VariableDeclaration
{
public:
    SimpleName *name;
    TypeSpecifier *type;
    Expression *initialValue;

    PropertyDeclaration(AST *owner);
    virtual ~PropertyDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_PropertyDeclaration__ */
