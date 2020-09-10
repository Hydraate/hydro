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

#include "ParentSelector.hpp"

namespace hydro::engine
{

ParentSelector::ParentSelector(compiler::Token token) : Selector{ token }
{
}

ParentSelector::~ParentSelector()
{
}

} // namespace hydro::engine
