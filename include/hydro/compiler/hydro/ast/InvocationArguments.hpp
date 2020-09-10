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

#ifndef __h3o_InvocationArguments__
#define __h3o_InvocationArguments__

#include <list>

#include "Expression.hpp"

namespace hydro::compiler
{
class InvocationArguments final : public ASTNode
{
public:
    InvocationArguments(AST *owner);
    virtual ~InvocationArguments();
    virtual void accept(ASTVisitor *visitor) override;
    void append(Expression *arg);
    const std::list<Expression *> &args();
    uint32_t size() const { return (uint32_t)m_args.size(); }

private:
    std::list<Expression *> m_args;
};

} // namespace hydro::compiler

#endif /* __h3o_InvocationArguments__ */
