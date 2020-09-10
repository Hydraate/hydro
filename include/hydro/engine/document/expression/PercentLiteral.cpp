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

#include "PercentLiteral.hpp"

namespace hydro::engine
{

PercentLiteral::PercentLiteral(compiler::Token token, NumberLiteral *value) : Expression{ token }
{
    mValue = value;
}

PercentLiteral::~PercentLiteral()
{
}

} // namespace hydro::engine
