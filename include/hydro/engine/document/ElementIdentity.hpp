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

#ifndef __h3o_engine_ElementIdentity__
#define __h3o_engine_ElementIdentity__

#include "ElementClass.hpp"
#include "ElementID.hpp"
#include "Identity.hpp"

namespace hydro::engine
{
/**
 * The ElementIdentity class stores information about an element entity's identity.
 */
class ElementIdentity final : public Identity
{
public:
    /**
     * Creates an ElementIdentity object with a relationships list, element class, and ID.
     */
    ElementIdentity(IdentityRelationshipsList *relationships, ElementClass *type, ElementID *id);

    /**
     * Destroys the ElementIdentity object.
     */
    virtual ~ElementIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the element identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the element entity's ID.
     * @return Returns the IDName instance for the element entity. Returns null if the element entity is anonymous.
     */
    ElementID *getID() const { return mID; }
    
private:
    /**
     * A sharable identifier assigned to element entities representing a single instance.
     */
    ElementID *mID;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementIdentity__ */
