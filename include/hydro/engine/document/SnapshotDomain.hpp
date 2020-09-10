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

#ifndef __h3o_engine_SnapshotClass__
#define __h3o_engine_SnapshotClass__

#include "EntityType.hpp"

namespace hydro::engine
{
/**
 * The SnapshotDomain represents a domain reserved for a single snapshot context that is normally shared among numerous snapshots.
 */
class SnapshotDomain final : public EntityType
{
public:
    /**
     * Creates a SnapshotDomain object with a Name.
     * @param name The name of the snapshot domain.
     */
    SnapshotDomain(Name *name);

    /**
     * Destroys the SnapshotDomain object.
     */
    virtual ~SnapshotDomain();
    
    /**
     * Accepts a visitor allowing the visitor to visit the snapshot domain.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotClass__ */
