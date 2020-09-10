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

#include "FunctionArgumentsList.hpp"

namespace hydro::compiler
{
FunctionArgumentsList::FunctionArgumentsList(AST *owner) : ASTNode{owner} {}

FunctionArgumentsList::~FunctionArgumentsList()
{
}

void FunctionArgumentsList::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
