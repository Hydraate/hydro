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

#include "DoubleLiteral.hpp"

namespace hydro::compiler
{
DoubleLiteral::DoubleLiteral(AST *owner) : Expression{owner}
{
    value = 0.0;
}

DoubleLiteral::~DoubleLiteral() {}

void DoubleLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
