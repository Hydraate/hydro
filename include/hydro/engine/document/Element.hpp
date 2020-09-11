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

#ifndef __h3o_engine_Element__
#define __h3o_engine_Element__

#include "ElementIdentity.hpp"
#include "Entity.hpp"

namespace hydro::engine
{
/**
 * The Element class represents an object entity. Element entities indirectly manipulate a proxied system.Element.
 */
class Element final : public Entity
{
public:
    /**
     * Creates an Element object with a parent.
     * @param parent The parent entity.
     * @param identity The element identity.
     */
    Element(Entity *parent, ElementIdentity *identity);

    /**
     * Destroys the Element object.
     */
    virtual ~Element();
    
    /**
     * Accepts a visitor allowing the visitor to visit the element.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

};

} // namespace hydro::engine

#endif /* __h3o_engine_Element__ */
