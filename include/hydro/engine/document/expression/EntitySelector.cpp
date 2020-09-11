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

#include "EntitySelector.hpp"

namespace hydro::engine
{

EntitySelector::EntitySelector() : Selector{}
{
    mType = nullptr;
}

EntitySelector::EntitySelector(EntityType *type) : Selector{}
{
    mType = type;
}

EntitySelector::~EntitySelector()
{
}

} // namespace hydro::engine
