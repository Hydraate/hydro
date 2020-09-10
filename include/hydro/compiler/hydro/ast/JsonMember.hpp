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

#ifndef __h3o_JsonMember__
#define __h3o_JsonMember__

#include "ASTNode.hpp"
#include "StringLiteral.hpp"

namespace hydro::compiler
{
class JsonMember final : public ASTNode
{
public:
    StringLiteral *key;
    Expression *value;

    JsonMember(AST *owner);
    virtual ~JsonMember();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_JsonMember__ */
