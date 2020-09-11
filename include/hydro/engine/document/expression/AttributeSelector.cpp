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

#include "AttributeSelector.hpp"

namespace hydro::engine
{
AttributeSelector::AttributeSelector(Name *name) : Selector{}
{
    mName = name;
}

AttributeSelector::~AttributeSelector()
{
}

} // namespace hydro::engine
