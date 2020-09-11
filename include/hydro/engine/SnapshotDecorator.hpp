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

#ifndef __h3o_engine_SnapshotDecorator__
#define __h3o_engine_SnapshotDecorator__

#include "InstanceDecorator.hpp"
#include "Snapshot.hpp"
#include "SnapshotInstance.hpp"

namespace hydro::engine
{
/**
 * The SnapshotDecorator class decorates a snapshot instance with attributes and child instances.
 */
class SnapshotDecorator : public InstanceDecorator
{
public:
    /**
     * Creates a SnapshotDecorator object that decorators some snapshot instance based on a snapshot entity description.
     */
    SnapshotDecorator(SnapshotInstance *instance, Snapshot *snapshot);

    /**
     * Destroys the SnapshotDecorator object.
     */
    virtual ~SnapshotDecorator();
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotDecorator__ */
