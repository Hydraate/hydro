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

#include "RegularExpressionLiteral.hpp"

namespace hydro::compiler
{
RegularExpressionLiteral::RegularExpressionLiteral(AST *owner) : Expression{owner} {}

RegularExpressionLiteral::~RegularExpressionLiteral() {}

void RegularExpressionLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
