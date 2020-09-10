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

#include "SelectorInitializer.hpp"

namespace hydro::engine
{

SelectorInitializer::SelectorInitializer(compiler::Token token, Selector *selector) : Expression{ token }
{
    mSelector = selector;
}

SelectorInitializer::~SelectorInitializer()
{
}

} // namespace hydro::engine
