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

#include "ReturnStatement.hpp"

namespace hydro::compiler
{
ReturnStatement::ReturnStatement(AST *owner) : Statement{owner}
{
    expression = nullptr;
}

ReturnStatement::~ReturnStatement()
{
}

void ReturnStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
