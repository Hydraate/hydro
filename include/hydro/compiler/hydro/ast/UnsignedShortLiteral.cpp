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

#include "UnsignedShortLiteral.hpp"

namespace hydro::compiler
{
UnsignedShortLiteral::UnsignedShortLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

UnsignedShortLiteral::~UnsignedShortLiteral() {}

void UnsignedShortLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
