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

#include "SnapshotIdentity.hpp"

namespace hydro::engine
{
SnapshotIdentity::SnapshotIdentity(IdentityRelationshipsList *relationships, SnapshotDomain *type)
    : Identity{relationships, type}
{
}

SnapshotIdentity::~SnapshotIdentity()
{
}

} // namespace hydro::engine
