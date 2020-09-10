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

#include "IntegerLiteral.hpp"

namespace hydro::compiler
{
IntegerLiteral::IntegerLiteral(AST *owner) : Expression{owner}
{
    value = 0;
}

IntegerLiteral::~IntegerLiteral() {}

} // namespace hydro::compiler
