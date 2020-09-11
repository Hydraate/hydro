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

#include "FunctionArgument.hpp"

namespace hydro::compiler
{
FunctionArgument::FunctionArgument(AST *owner) : ASTNode{owner}
{
    name = nullptr;
    type = nullptr;
    defaultValue = nullptr;
}

FunctionArgument::~FunctionArgument()
{
}

void FunctionArgument::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
