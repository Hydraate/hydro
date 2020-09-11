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

#ifndef __h3o_internal_Modifiers__
#define __h3o_internal_Modifiers__

#include <list>

#include "ASTNode.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class Modifiers final : public ASTNode
{
public:
    Modifiers(AST *owner);
    virtual ~Modifiers();
    virtual void accept(ASTVisitor *visitor) override;
    void append(SimpleName *mod);
    bool hasModifier(std::string name) const;
    bool isPublic() const;
    bool isInternal() const;
    bool isProtected() const;
    bool isPrivate() const;
    bool isRestricted() const;
    bool isAbstract() const;
    bool isNative() const;
    bool isDynamic() const;
    bool isOverride() const;
    bool isFinal() const;
    bool isStatic() const;
    bool isReadOnly() const;
    bool isWriteOnly() const;
    bool isSychronized() const;

    const std::list<SimpleName *> &mods() const { return m_mods; }

private:
    std::list<SimpleName *> m_mods;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_Modifiers__ */
