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

#include "SnapshotDecorator.hpp"

namespace hydro::engine
{
SnapshotDecorator::SnapshotDecorator(SnapshotInstance *instance, Snapshot *snapshot)
    : InstanceDecorator{instance, snapshot}
{
}

SnapshotDecorator::~SnapshotDecorator()
{
}

} // namespace hydro::engine
