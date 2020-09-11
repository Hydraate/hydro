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

#include "UndefinedExpression.hpp"

namespace hydro::engine
{
UndefinedExpression::UndefinedExpression(compiler::Token token) : Expression{token}
{
}

UndefinedExpression::~UndefinedExpression() {}

} // namespace hydro::engine
