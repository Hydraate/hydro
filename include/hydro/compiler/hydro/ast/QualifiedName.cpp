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

#include "QualifiedName.hpp"

namespace hydro::compiler
{
QualifiedName::QualifiedName(AST *owner) : Name{owner}
{
    m_qualifier = m_name = nullptr;
}

QualifiedName::~QualifiedName()
{
}

void QualifiedName::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

std::string QualifiedName::getValue() const
{
    if (!m_qualifier || !m_name)
        return ""; // invalid
    return m_qualifier->getValue() + "." + m_name->getValue();
}

bool QualifiedName::compare(Name *name) const
{
    if (name == this)
        return true;
    if (QualifiedName *qname = dynamic_cast<QualifiedName *>(name))
        if (qname->m_qualifier->compare(m_qualifier) && qname->m_name->compare(name))
            return true;
    return false;
}

} // namespace hydro::compiler
