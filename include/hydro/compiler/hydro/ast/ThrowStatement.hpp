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

#ifndef __h3o_ThrowStatement__
#define __h3o_ThrowStatement__

#include "Expression.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class ThrowStatement final : public Statement
{
public:
    Expression *expression;

    ThrowStatement(AST *owner);
    virtual ~ThrowStatement();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ThrowStatement__ */
