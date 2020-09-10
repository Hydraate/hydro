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

#include "FloatLiteral.hpp"

namespace hydro::compiler
{
FloatLiteral::FloatLiteral(AST *owner) : Expression{owner}
{
    value = 0.0f;
}

FloatLiteral::~FloatLiteral() {}

void FloatLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
