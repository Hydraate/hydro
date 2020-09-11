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

#include "UnsignedLongLiteral.hpp"

namespace hydro::compiler
{
UnsignedLongLiteral::UnsignedLongLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

UnsignedLongLiteral::~UnsignedLongLiteral() {}

void UnsignedLongLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
