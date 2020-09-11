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

#include "InvocationArguments.hpp"

namespace hydro::compiler
{
InvocationArguments::InvocationArguments(AST *owner) : ASTNode{owner} {}

InvocationArguments::~InvocationArguments()
{
}

void InvocationArguments::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void InvocationArguments::append(Expression *arg)
{
    m_args.push_back(arg);
}

} // namespace hydro::compiler
