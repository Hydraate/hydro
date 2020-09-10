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

#include "UnsignedIntegerLiteral.hpp"

namespace hydro::compiler
{
UnsignedIntegerLiteral::UnsignedIntegerLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

UnsignedIntegerLiteral::~UnsignedIntegerLiteral() {}

void UnsignedIntegerLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
