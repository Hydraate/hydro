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

#include "NullLiteral.hpp"

namespace hydro
{

NullLiteral::NullLiteral(Token *token) : Literal{token} {}

NullLiteral::~NullLiteral() {}

} // namespace hydro
