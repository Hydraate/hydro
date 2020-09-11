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

#include "EntityType.hpp"

namespace hydro::engine
{
/**
 *
 */
EntityType::EntityType(Name *name)
{
    mName = name;
}

EntityType::~EntityType()
{
}

} // namespace hydro::engine
