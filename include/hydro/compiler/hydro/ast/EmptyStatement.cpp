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

#include "EmptyStatement.hpp"

namespace hydro::compiler
{
EmptyStatement::EmptyStatement(AST *owner) : Statement{owner} {}

EmptyStatement::~EmptyStatement() {}

void EmptyStatement::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
