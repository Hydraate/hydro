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

#ifndef __h3o_ObjectMember__
#define __h3o_ObjectMember__

#include "ASTNode.hpp"
#include "Expression.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class ObjectMember final : public ASTNode
{
public:
    ObjectMember(AST *owner);
    virtual ~ObjectMember();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ObjectMember__ */
