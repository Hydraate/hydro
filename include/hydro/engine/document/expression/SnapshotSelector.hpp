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

#ifndef __h3o_engine_SnapshotSelector__
#define __h3o_engine_SnapshotSelector__

#include "../SnapshotDomain.hpp"

#include "EntitySelector.hpp"

namespace hydro::engine
{

/**
 * The SnapshotSelector class represents a snapshot selector in a Performance document.
 */
class SnapshotSelector final : public EntitySelector
{
public:
    /**
     * Creates a SnapshotSelector with a snapshot domain.
     * @param domain The snapshot domain.
     */
    SnapshotSelector(SnapshotDomain *domain);
    
    /**
     * Destroys the SnapshotSelector object.
     */
    virtual ~SnapshotSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the snapshot selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotSelector__ */
