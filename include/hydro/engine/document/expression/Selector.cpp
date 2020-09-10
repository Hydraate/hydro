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

#include "Selector.hpp"

namespace hydro::engine
{

Selector::Selector() : Expression{}
{
}

Selector::Selector(compiler::Token token) : Expression{ token }
{
}

Selector::~Selector()
{
}

} // namespace hydro::engine
