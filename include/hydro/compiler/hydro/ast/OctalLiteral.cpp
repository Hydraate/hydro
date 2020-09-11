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

#include "OctalLiteral.hpp"

namespace hydro::compiler
{
OctalLiteral::OctalLiteral(AST *owner) : Expression{owner} {}

OctalLiteral::~OctalLiteral() {}

} // namespace hydro::compiler
