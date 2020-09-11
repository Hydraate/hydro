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

#ifndef __h3o_ASTNode__
#define __h3o_ASTNode__

#include <list>

#include "../../Token.hpp"
#include "ASTVisitor.hpp"

namespace hydro::compiler
{
class AST;

class ASTNode
{
protected:
    ASTNode(AST *owner);

public:
    Token token;

    virtual ~ASTNode();
    virtual void accept(ASTVisitor *visitor) = 0;
    AST *getOwner() const { return m_owner; }
    const std::string geTokenValue() const { return token.value(); }
    int32_t getTokenType() const { return token.type(); }
    virtual int32_t getStartPosition() const;
    virtual int32_t getEndPosition() const;

private:
    AST *m_owner;
};

} // namespace hydro::compiler

#endif /* __h3o_ASTNode__ */
