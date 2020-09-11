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

#ifndef __h3o_ObjectInitializer__
#define __h3o_ObjectInitializer__

#include <list>

#include "ObjectMember.hpp"

namespace hydro::compiler
{
class ObjectInitializer final : public Expression
{
public:
    ObjectInitializer(AST *owner);
    virtual ~ObjectInitializer();
    virtual void accept(ASTVisitor *visitor) override;
    void append(ObjectMember *member);
    const std::list<ObjectMember *> &members() const { return m_members; }
    uint32_t size() const { return (uint32_t)m_members.size(); }

private:
    std::list<ObjectMember *> m_members;
};

} // namespace hydro::compiler

#endif /* __h3o_ObjectInitializer__ */
