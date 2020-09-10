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

#include "DescendantSelector.hpp"

namespace hydro::engine
{

DescendantSelector::DescendantSelector(Selector *subject, Selector *target) : CompoundSelector{ subject,  target }
{
}

DescendantSelector::~DescendantSelector()
{
}

} // namespace hydro::engine
