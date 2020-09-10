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

#include "Snapshot.hpp"

namespace hydro::engine
{
Snapshot::Snapshot(Entity *parent, SnapshotIdentity *identity)
    : Entity{parent, identity}
{
}

Snapshot::~Snapshot()
{
}

} // namespace hydro::engine
