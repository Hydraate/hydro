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

#include "ObjectMember.hpp"

namespace hydro::compiler
{
ObjectMember::ObjectMember(AST *owner) : ASTNode{owner} {}

ObjectMember::~ObjectMember() {}

void ObjectMember::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
