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

#ifndef __h3o_engine_SnapshotReference__
#define __h3o_engine_SnapshotReference__

#include "SimpleReference.hpp"
#include "SnapshotDomain.hpp"

namespace hydro::engine
{

/**
 * The SnapshotReference class represents a reference to an active snapshot in a snapshot context within a Performance document.
 */
class SnapshotReference final : public SimpleReference
{
public:
    /**
     * Creates a SnapshotReference with a name.
     * @param domain The snapshot context domain.
     */
    SnapshotReference(SnapshotDomain *domain);
    
    /**
     * Destroys the SnapshotReference object.
     */
    virtual ~SnapshotReference();
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotReference__ */
