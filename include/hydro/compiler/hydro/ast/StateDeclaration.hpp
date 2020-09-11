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

#ifndef __h3o_StateDeclaration__
#define __h3o_StateDeclaration__

#include "BodyDeclaration.hpp"

namespace hydro::compiler
{
class StateDeclaration final : public BodyDeclaration
{
public:
    StateDeclaration(AST *owner);
    virtual ~StateDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_StateDeclaration__ */
