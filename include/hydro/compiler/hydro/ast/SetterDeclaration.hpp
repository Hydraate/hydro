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

#ifndef __h3o_SetterDeclaration__
#define __h3o_SetterDeclaration__

#include "BodyDeclaration.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class SetterDeclaration : public BodyDeclaration
{
public:
    SimpleName *nameOfValue;
    SetterDeclaration(AST *owner);
    virtual ~SetterDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_SetterDeclaration__ */
