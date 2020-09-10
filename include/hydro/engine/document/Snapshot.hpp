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

#ifndef __h3o_engine_Snapshot__
#define __h3o_engine_Snapshot__

#include "Entity.hpp"
#include "SnapshotIdentity.hpp"
#include "expression/TimePointLiteral.hpp"

namespace hydro::engine
{
class Snapshot;

/**
 * The Snapshot class represents data associated with a virtual snapshot of content at a given moment. Snapshots are particularly similar to the concept of the state pattern requiring a context in which only one snapshot within a domain is active at a time.
 */
class Snapshot : public Entity
{
public:
    /**
     * Creates a  named snapshot object as a child of some parent entity.
     */
    Snapshot(Entity *parent, SnapshotIdentity *identity);

    /**
     * Destroys the snapshot instance.
     */
    virtual ~Snapshot();
    
    /**
     * Accepts a visitor allowing the visitor to visit the snapshot entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Snapshot__ */
