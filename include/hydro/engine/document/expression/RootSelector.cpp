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

#include "RootSelector.hpp"

namespace hydro::engine
{

RootSelector::RootSelector(compiler::Token token) : Selector{ token }
{
}

RootSelector::~RootSelector()
{
}

} // namespace hydro::engine
