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

#include "ActionIdentity.hpp"

namespace hydro::engine
{

ActionIdentity::ActionIdentity(IdentityRelationshipsList *relationships, EventClass *type)
: Identity{ relationships, type }
{
}

ActionIdentity::~ActionIdentity()
{
}

} // namespace hydro::engine
