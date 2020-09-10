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

#include "BinaryLiteral.hpp"

namespace hydro::compiler
{
BinaryLiteral::BinaryLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

BinaryLiteral::~BinaryLiteral() {}

void BinaryLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
