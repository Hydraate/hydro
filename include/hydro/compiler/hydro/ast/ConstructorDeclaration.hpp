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

#ifndef __h3o_ConstructorDeclaration__
#define __h3o_ConstructorDeclaration__

#include "BodyDeclaration.hpp"
#include "FunctionDeclaration.hpp"

namespace hydro::compiler
{
class ConstructionDeclaration final : public FunctionDeclaration
{
public:
    ConstructionDeclaration(AST *owner);
    virtual ~ConstructionDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ConstructorDeclaration__ */
