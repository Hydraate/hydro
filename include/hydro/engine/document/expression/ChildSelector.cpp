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

#include "ChildSelector.hpp"

namespace hydro::engine
{

ChildSelector::ChildSelector(Selector *subject, Selector *target) : CompoundSelector{ subject, target }
{
}

ChildSelector::~ChildSelector()
{
}

} // namespace hydro::engine
