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

#ifndef __h3o_engine_PrototypeIdentity__
#define __h3o_engine_PrototypeIdentity__

#include "Identity.hpp"
#include "ElementClass.hpp"

namespace hydro::engine
{

/**
 * The PrototypeIdentity class stores information about the idetntity of an element prototype in a Performance document.
 */
class PrototypeIdentity final : public Identity
{
public:
    
    /**
     * Creates a PrototypeIdentity object with relationships and an element class.
     * @param relationships The identity relationships list.
     * @param elementClass The element class.
     */
    PrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass);
    
    /**
     * Creates a PrototypeIdentity object with relationships, a parent element class, and a derived element class.
     * @param relationships The identity relationships list.
     * @param parentClass The inherited element class.
     * @param derivedClass The derived element class.
     */
    PrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *parentClass, ElementClass *derivedClass);

    /**
     * Destroys the PrototypeIdentity object.
     */
    virtual ~PrototypeIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the prototype identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
private:
    /**
     * The parent element class.
     */
    ElementClass *mParentClass;
};

} // namespace hydro::engine

#endif /* __h3o_engine_PrototypeIdentity__ */
