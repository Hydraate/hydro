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

#ifndef __h3o_TryStatement__
#define __h3o_TryStatement__

#include "Statement.hpp"

namespace hydro::compiler
{
class TryStatement final : public Statement
{
public:
    TryStatement(AST *owner);
    virtual ~TryStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_TryStatement__ */
