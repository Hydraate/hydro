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

#include "DocumentSelector.hpp"

namespace hydro::engine
{

DocumentSelector::DocumentSelector(compiler::Token token) : Selector{ token }
{
}

DocumentSelector::~DocumentSelector()
{
}

} // namespace hydro::engine
