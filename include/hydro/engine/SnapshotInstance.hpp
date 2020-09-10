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

#ifndef __h3o_engine_SnapshotInstance__
#define __h3o_engine_SnapshotInstance__

#include "Instance.hpp"
#include "Snapshot.hpp"

namespace hydro::engine
{
class SnapshotContext;

/**
 * The SnapshotInstance class represents an instance of a snapshot.
 */
class SnapshotInstance final : public Instance
{
public:
    /**
     * Creates a Snapshot object.
     */
    SnapshotInstance();

    /**
     * Destroys the Snapshot object.
     */
    virtual ~SnapshotInstance();

    /**
     * Gets the snapshot context that owns the Snapshot object.
     * @returns Returns the SnapshotContext in which the Snapshot object belongs to.
     */
    SnapshotContext *getSnapshotContext() const { return mContext; }

    /**
     * Requests focus for the snapshot instance such that the snapshot will become the current snapshot in its contexts. If the snapshot is already in focus this method does nothing.
     */
    void requestFocus();

    /**
     * Specifies whether or not the snapshot is the active snapshot in its context.
     * @return Returns true if the snapshot is has the current focus in its context. Otherwise returns false.
     */
    bool isFocused() const { return mFocused; }

    /**
     * Specifies whether or not the snapshot has requested focus via a call to the requestFocus() method.
     * @return Returns true if a call to requestFocus() method has been called requesting focus for the snapshot. Otherwise returns true.
     */
    bool isFocusRequested() const { return mFocusRequested; }

    /**
     * Specifies whether or not the snapshot has request focus successfully and though the snapshot is not currently in focus, the snapshot's focus is pending. Focus will be pending when interpolation between two snapshots is commencing.
     * @return Returns true if focus is pending for the snapshot. Otherwise returns false.
     */
    bool isFocusPending() const { return mFocusPending; }

private:
    /**
     * The SnapshotContext that owns the Snapshot object.
     */
    SnapshotContext *mContext;

    /**
     * Determines if the snapshot is in focus. This property is set by the owning SnapshotContext object.
     */
    bool mFocused;

    /**
     * The focus requested state for the snapshot.
     */
    bool mFocusRequested;

    /**
     * Determines if the snapshot is not in focus but focus is pending. This property is set by the owning SnapshotContext object.
     */
    bool mFocusPending;

    friend class SnapshotContext;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotInstance__ */
