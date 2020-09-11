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

#ifndef __h3o_EventDeclaration__
#define __h3o_EventDeclaration__

#include "BodyDeclaration.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class EventDeclaration final : public BodyDeclaration
{
public:
    SimpleName *name;

    EventDeclaration(AST *owner);
    virtual ~EventDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_EventDeclaration__ */
