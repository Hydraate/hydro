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

#include "JsonMember.hpp"

namespace hydro::compiler
{
JsonMember::JsonMember(AST *owner) : ASTNode{owner}
{
    key = nullptr;
    value = nullptr;
}

JsonMember::~JsonMember()
{
}

void JsonMember::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
