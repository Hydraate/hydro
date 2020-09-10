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

#include "Modifiers.hpp"

namespace hydro::compiler
{
Modifiers::Modifiers(AST *owner) : ASTNode{owner} {}

Modifiers::~Modifiers()
{
}

void Modifiers::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void Modifiers::append(SimpleName *mod)
{
    m_mods.push_back(mod);
}

bool Modifiers::hasModifier(std::string modifier) const
{
    for (SimpleName *mod : m_mods)
        if (mod->getValue() == modifier)
            return true;
    return false;
}

bool Modifiers::isPublic() const { return hasModifier("public"); }

bool Modifiers::isInternal() const { return hasModifier("internal"); }

bool Modifiers::isProtected() const { return hasModifier("protected"); }

bool Modifiers::isPrivate() const { return hasModifier("private"); }

bool Modifiers::isRestricted() const { return hasModifier("restricted"); }

bool Modifiers::isAbstract() const { return hasModifier("abstract"); }

bool Modifiers::isNative() const { return hasModifier("native"); }

bool Modifiers::isDynamic() const { return hasModifier("dynamic"); }

bool Modifiers::isOverride() const { return hasModifier("override"); }

bool Modifiers::isFinal() const { return hasModifier("final"); }

bool Modifiers::isStatic() const { return hasModifier("static"); }

bool Modifiers::isReadOnly() const { return hasModifier("readonly"); }

bool Modifiers::isWriteOnly() const { return hasModifier("writeonly"); }

bool Modifiers::isSychronized() const { return hasModifier("sychronized"); }

} // namespace hydro::compiler
