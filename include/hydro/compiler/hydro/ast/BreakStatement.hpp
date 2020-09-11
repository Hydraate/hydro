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

#ifndef __h3o_BreakStatement__
#define __h3o_BreakStatement__

#include "Statement.hpp"

namespace hydro::compiler
{
class BreakStatement final : public Statement
{
public:
    uint32_t depth;

    BreakStatement(AST *owner);
    virtual ~BreakStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_BreakStatement__ */
