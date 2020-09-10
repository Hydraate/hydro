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

#ifndef __h3o_Block__
#define __h3o_Block__

#include <list>

#include "Statement.hpp"

namespace hydro::compiler
{
class Block final : public Statement
{
public:
    Block(AST *owner);
    virtual ~Block();
    virtual void accept(ASTVisitor *visitor) override;
    void append(Statement *statement);
    const std::list<Statement *> &statements() const { return m_statements; }

protected:
    std::list<Statement *> m_statements;
};

} // namespace hydro::compiler

#endif /* __h3o_Block__ */
