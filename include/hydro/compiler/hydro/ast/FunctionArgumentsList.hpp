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

#ifndef __h3o_FunctionArgumentsList__
#define __h3o_FunctionArgumentsList__

#include <list>

#include "ASTNode.hpp"
#include "FunctionArgument.hpp"

namespace hydro::compiler
{
class FunctionArgumentsList final : public ASTNode
{
public:
    FunctionArgumentsList(AST *owner);
    virtual ~FunctionArgumentsList();
    virtual void accept(ASTVisitor *visitor) override;
    void append(FunctionArgument *arg);
    const std::list<FunctionArgument *> &args() const { return m_args; }
    uint32_t size() const { return (uint32_t)m_args.size(); }

private:
    std::list<FunctionArgument *> m_args;
};

} // namespace hydro::compiler

#endif /* __h3o_FunctionArgumentsList__t */
