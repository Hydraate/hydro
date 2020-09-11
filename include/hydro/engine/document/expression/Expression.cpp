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

#include "Expression.hpp"

namespace hydro::engine
{
Expression::Expression()
{
}

Expression::Expression(compiler::Token token) : Value{token}
{
}

Expression::~Expression()
{
}

} // namespace hydro::engine
