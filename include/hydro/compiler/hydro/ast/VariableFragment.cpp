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

#include "VariableFragment.hpp"

namespace hydro::compiler
{
VariableFragment::VariableFragment(AST *owner) : ASTNode{owner}
{
    name = nullptr;
    type = nullptr;
}

VariableFragment::~VariableFragment()
{
}

void VariableFragment::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
