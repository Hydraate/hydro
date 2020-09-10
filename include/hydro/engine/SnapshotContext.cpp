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

#include "SnapshotContext.hpp"

namespace hydro::engine
{
SnapshotContext::SnapshotContext(Instance *owner)
{
    mOwner = owner;
}

SnapshotContext::~SnapshotContext() {}

void SnapshotContext::bind(SnapshotInstance *snapshot)
{
    mSnapshots.push_back(snapshot);
}

} // namespace hydro::engine
