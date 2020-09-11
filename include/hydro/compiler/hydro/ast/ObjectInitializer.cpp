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

#include "ObjectInitializer.hpp"

namespace hydro::compiler
{
ObjectInitializer::ObjectInitializer(AST *owner) : Expression{owner} {}

ObjectInitializer::~ObjectInitializer()
{
}

void ObjectInitializer::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void ObjectInitializer::append(ObjectMember *member)
{
    m_members.push_back(member);
}

} // namespace hydro::compiler
