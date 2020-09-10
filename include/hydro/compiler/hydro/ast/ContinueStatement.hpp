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

#ifndef __h3o_ContinueStatement__
#define __h3o_ContinueStatement__

#include "Statement.hpp"

namespace hydro::compiler
{
class ContinueStatement final : public Statement
{
public:
    uint32_t depth;

    ContinueStatement(AST *owner);
    virtual ~ContinueStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ContinueStatement__ */
