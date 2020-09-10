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

#ifndef __h3o_engine_SnapshotContext__
#define __h3o_engine_SnapshotContext__

#include <list>

#include "Instance.hpp"
#include "SnapshotInstance.hpp"

namespace hydro::engine
{
/**
 * The SnapshotContext class iterates snapshots. There is only a single snapshot that is in current focus or no snapshot may have focus. By default the first snapshot appended to the context has the initial focus.
 */
class SnapshotContext
{
public:
    /**
     * Creates a SnapshotContext object that is owned by a particular Instance.
     */
    SnapshotContext(Instance *owner);

    /**
     * Destroys the SnapshotContext.
     */
    ~SnapshotContext();

    /**
     * Binds a snapshot instance to the snapshot context.
     */
    void bind(SnapshotInstance *snapshot);

    /**
     * Brings the previous snapshot into focus.
     */
    void prev();

    /**
     * Brings the next snapshot into focus.
     */
    void next();

    /**
     * Gets the instance that owns the snapshot context.
     * @return Returns the Instance instance that this SnapshotContext is associated
     */
    Instance *getOwner() const { return mOwner; }

private:
    /**
     * The Instance object that this SnapshotContext belongs to.
     */
    Instance *mOwner;

    /**
     * The list of snapshot instances contained within the context.
     */
    std::list<SnapshotInstance *> mSnapshots;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotContext__ */
