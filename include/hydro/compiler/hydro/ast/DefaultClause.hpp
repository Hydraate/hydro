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

#ifndef __h3o_DefaultClause__
#define __h3o_DefaultClause__

#include "Statement.hpp"

namespace hydro::compiler
{
class DefaultClause final : public Statement
{
public:
    DefaultClause(AST *owner);
    virtual ~DefaultClause();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_DefaultClause__ */
