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

#include "IdentityRelationshipsList.hpp"

namespace hydro::engine
{
IdentityRelationshipsList::IdentityRelationshipsList()
{
}

IdentityRelationshipsList::~IdentityRelationshipsList()
{
}

void IdentityRelationshipsList::append(Relationship *relationship)
{
    mRelationships.push_back(relationship);
}

} // namespace hydro::engine
