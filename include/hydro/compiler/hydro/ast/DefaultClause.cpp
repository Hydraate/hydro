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

#include "DefaultClause.hpp"

namespace hydro::compiler
{
DefaultClause::DefaultClause(AST *owner) : Statement{owner} {}

DefaultClause::~DefaultClause() {}

void DefaultClause::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
