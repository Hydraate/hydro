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

#ifndef __h3o_engine_SnapshotIdentity__
#define __h3o_engine_SnapshotIdentity__

#include "Identity.hpp"
#include "SnapshotDomain.hpp"

namespace hydro::engine
{
/**
 * The SnapshotIdentity class stores information about the identity of a snapshot entity.
 */
class SnapshotIdentity final : public Identity
{
public:
    /**
     * Creates a SnapshotIdentity object with a relationships list and a snapshot domain.
     */
    SnapshotIdentity(IdentityRelationshipsList *relationships, SnapshotDomain *type);

    /**
     * Destroys the SnapshotIdentity object.
     */
    virtual ~SnapshotIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the snapshot identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotIdentity__ */
