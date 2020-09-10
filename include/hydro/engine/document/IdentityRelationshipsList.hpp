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

#ifndef __h3o_engine_IdentityRelationshipsList__
#define __h3o_engine_IdentityRelationshipsList__

#include <list>

#include "Node.hpp"
#include "Relationship.hpp"

namespace hydro::engine
{
/**
 * The IdentityRelationshipsList class represents a list of relationships that describe an entity in relation to some ancestor.
 */
class IdentityRelationshipsList final : public Node
{
public:
    /**
     * Creates an empty IdentityRelationshipsList object.
     */
    IdentityRelationshipsList();

    /**
     * Destroys the IdentityRelationshipsList object.
     */
    virtual ~IdentityRelationshipsList();
    
    /**
     * Accepts a visitor allowing the visitor to visit the identity relationships list.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Appends a relationship to the list.
     * @param relationship The relationship to append.
     */
    void append(Relationship *relationship);

    /**
     * Gets a list of relationships stored within the list.
     * @return Returns a constant reference of the relationships list.
     */
    const std::list<Relationship *> &relationships() const { return mRelationships; }

    /**
     * Reports the size of the list.
     * @return Returns the size of the contained list.
     */
    auto size() const { return mRelationships.size(); }

private:
    /**
     * The list of relationships.
     */
    std::list<Relationship *> mRelationships;
};

} // namespace hydro::engine

#endif /* __h3o_engine_IdentityRelationshipsList__ */
