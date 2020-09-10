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

#include "NullExpression.hpp"

namespace hydro::engine
{
NullExpression::NullExpression(compiler::Token token) : Expression{token}
{
}

NullExpression::~NullExpression()
{
}

} // namespace hydro::engine
