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

#ifndef __h3o_ListInitializer__
#define __h3o_ListInitializer__

#include <list>

#include "Expression.hpp"

namespace hydro::compiler
{
class ListInitializer final : public Expression
{
public:
    ListInitializer(AST *owner);
    virtual ~ListInitializer();
    virtual void accept(ASTVisitor *visitor) override;
    void append(Expression *item);
    const std::list<Expression *> &items() const { return m_items; }
    uint32_t size() const { return (uint32_t)m_items.size(); }

protected:
    std::list<Expression *> m_items;
};

} // namespace hydro::compiler

#endif /* ListInitializer_hpp */
