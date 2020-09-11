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

#include "ColorLiteral.hpp"

namespace hydro::engine
{
ColorLiteral::ColorLiteral(compiler::Token token) : Expression{token}
{
}

ColorLiteral::~ColorLiteral()
{
}

} // namespace hydro::engine
