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

#include "LongLiteral.hpp"

namespace hydro::compiler
{
LongLiteral::LongLiteral(AST *owner) : Expression{owner}
{
    value = 0L;
}

LongLiteral::~LongLiteral() {}

void LongLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
