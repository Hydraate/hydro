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

#ifndef __h3o_engine_ActionIdentity__
#define __h3o_engine_ActionIdentity__

#include "EventClass.hpp"
#include "Identity.hpp"

namespace hydro::engine
{
/**
 * The ActionIdentity class provides information about the identity of an event action. Actions may not be named entities using a unique ID.
 */
class ActionIdentity final : public Identity
{
public:
    /**
     * Creates an ActionIdentity object with an event class.
     */
    ActionIdentity(IdentityRelationshipsList *relationships, EventClass *type);

    /**
     * Destroys the ActionIdentity object.
     */
    virtual ~ActionIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the action identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ActionIdentity__ */
