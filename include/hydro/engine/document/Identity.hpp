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

#ifndef __h3o_engine_Identity__
#define __h3o_engine_Identity__

#include <string>
#include <vector>

#include "EntityType.hpp"
#include "IdentityRelationshipsList.hpp"
#include "ElementID.hpp"
#include "Subject.hpp"

namespace hydro::engine
{
/**
 * The abstract Identity class stores information about the identity and relationships of an entity in relation to the document and its parent.
 */
class Identity : public Node
{
protected:
    /**
     * Creates a nil Identity object.
     */
    Identity();

    /**
     * Creates an Identity object with a subject.
     * @param subject The identity's subject.
     */
    Identity(Subject *subject);

    /**
     * Creates an Identity object with a relationships and a subject.
     * @param relationships The identity relationships list.
     * @param subject The identity's subject. In this context the subject is intended to be an entity type.
     */
    Identity(IdentityRelationshipsList *relationships, Subject *subject);
    
    /**
     * Creates an Identity object with a relationship, a subject, and an ID. This constructor is reserved for element identities.
     */
    Identity(IdentityRelationshipsList *relationships, Subject *subject, ElementID *id);

public:
    /**
     * Destroys the Identity object.
     */
    virtual ~Identity();

    /**
     * Gets the relationships decribed with this identity.
     * @return Returns the IdentityRelationshipsList instance associated with the Identity object. Returns null if the Identity does support relationships.
     */
    IdentityRelationshipsList *getRelationships() const { return mRelationships; }

    /**
     * A helper method that specifies whether or not the identity is decribed with relationships.
     * @return Returns true if the relationships list exists and is occupied by at least one relationship description. Otherwise returns false.
     */
    bool hasRelationships() const { return mRelationships && mRelationships->size() > 0; }

    /**
     * Gets the subject of this identity. The subject is the class or target that the entity references as a part of its description.
     * @return Returns the Subject instance associated with the Identity. Returns null if the Identity has not subject.
     */
    Subject *getSubject() const { return mSubject; }
    
    /**
     * Gets the entity ID.
     */
    ElementID *getID() const { return mID; }
    
private:
    /**
     * The list of relationships that describe the relationship between the entity and an ancestor.
     */
    IdentityRelationshipsList *mRelationships;

    /**
     * The subject of the identity. This will be an entity type or a reference to an entity.
     */
    Subject *mSubject;
    
    /**
     * The ID of an element entity. Reserved for element entities only.
     */
    ElementID *mID;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Identity__ */
