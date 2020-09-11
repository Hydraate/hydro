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

#include "ThrowStatement.hpp"

namespace hydro::compiler
{
ThrowStatement::ThrowStatement(AST *owner) : Statement{owner}
{
    expression = nullptr;
}

ThrowStatement::~ThrowStatement()
{
}

void ThrowStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
