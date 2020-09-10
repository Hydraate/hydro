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

#ifndef __h3o_EventTypeDeclaration__
#define __h3o_EventTypeDeclaration__

#include "Declaration.hpp"
#include "SimpleName.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class EventTypeDeclaration : public Statement
{
public:
    SimpleName *name;

    EventTypeDeclaration(AST *owner);
    virtual ~EventTypeDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* EventTypeDeclaration_hpp */
