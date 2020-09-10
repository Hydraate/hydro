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

#include "SimpleName.hpp"

namespace hydro::compiler
{
SimpleName::SimpleName(AST *owner) : Name{owner} {}

SimpleName::~SimpleName() {}

void SimpleName::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

bool SimpleName::compare(Name *name) const
{
    if (name == this)
        return true;
    if (SimpleName *simpleName = dynamic_cast<SimpleName *>(name))
        return (simpleName->m_value == m_value);
    return false;
}

} // namespace hydro::compiler
