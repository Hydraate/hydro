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

#include "ShortLiteral.hpp"

namespace hydro::compiler
{
ShortLiteral::ShortLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

ShortLiteral::~ShortLiteral() {}

void ShortLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
