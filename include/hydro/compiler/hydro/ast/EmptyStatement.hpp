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

#ifndef __h3o_EmptyStatement__
#define __h3o_EmptyStatement__

#include "Statement.hpp"

namespace hydro::compiler
{
class EmptyStatement final : public Statement
{
public:
    EmptyStatement(AST *owner);
    virtual ~EmptyStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_EmptyStatement__ */
