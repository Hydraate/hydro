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

#include "ElementSelector.hpp"

namespace hydro::engine
{
ElementSelector::ElementSelector(ElementClass *type) : EntitySelector{ type }
{
    mID = nullptr;
}

ElementSelector::ElementSelector(ElementID *id) : EntitySelector{ nullptr }
{
    mID = id;
}

ElementSelector::ElementSelector(ElementClass *type, ElementID *id) : EntitySelector{ type }
{
    mID = id;
}

ElementSelector::~ElementSelector()
{
}

} // namespace hydro::engine
