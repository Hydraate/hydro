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

#include "ElementIdentity.hpp"

namespace hydro::engine
{

ElementIdentity::ElementIdentity(IdentityRelationshipsList *relationships, ElementClass *type, ElementID *id) : Identity{ relationships, type }
{
    mID = id;
}

ElementIdentity::~ElementIdentity()
{
}

} // namespace hydro::engine
