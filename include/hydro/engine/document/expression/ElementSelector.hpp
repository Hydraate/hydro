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

#ifndef __h3o_engine_ElementSelector__
#define __h3o_engine_ElementSelector__

#include "../ElementID.hpp"
#include "../ElementClass.hpp"

#include "EntitySelector.hpp"

namespace hydro::engine
{
/**
 *
 */
class ElementSelector final : public EntitySelector
{
public:
    /**
     * Creates an ElementSelector with an element class.
     * @param type The element class.
     */
    ElementSelector(ElementClass *type);
    
    /**
     * Creates an ElementSelector with an element ID.
     * @param id The element ID.
     */
    ElementSelector(ElementID *id);
    
    /**
     * Creates an ElementSelector with an element class and an element ID.
     * @param type The element class.
     * @param id The element ID.
     */
    ElementSelector(ElementClass *type, ElementID *id);
    /**
     * Destroys the ElementSelector object.
     */
    virtual ~ElementSelector();

    /**
     * Gets the ID of the referenced element.
     * @return Returns a Name
     */
    ElementID *getID() const { return mID; }
    
    /**
     * Accepts a visitor allowing the visitor to visit the element selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

private:
    /**
     * The ID of the
     */
    ElementID *mID;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementSelector__ */
