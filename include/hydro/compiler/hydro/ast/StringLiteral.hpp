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

#ifndef __h3o_StringLiteral__
#define __h3o_StringLiteral__

#include <list>

#include "Expression.hpp"

namespace hydro::compiler
{
class StringLiteral final : public Expression
{
public:
    StringLiteral(AST *owner);
    virtual ~StringLiteral();
    virtual void accept(ASTVisitor *visitor) override;
    virtual void append(Expression *value);
    bool isTemplate() const { return !m_values.empty(); }
    const std::list<Expression *> &values() const { return m_values; }

protected:
    std::list<Expression *> m_values;
};

} // namespace hydro::compiler

#endif /* __h3o_StringLiteral__ */
