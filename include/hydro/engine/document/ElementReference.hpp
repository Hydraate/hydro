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

#ifndef __h3o_engine_ElementReference__
#define __h3o_engine_ElementReference__

#include "ElementClass.hpp"
#include "ElementID.hpp"
#include "SimpleReference.hpp"

namespace hydro::engine
{
/**
 * The ElementReference class represents a direct reference to a qualified element entity.
 */
class ElementReference final : public SimpleReference
{
public:
    /**
     * Creates an ElementReference object with a name and an optional ID. The element class and ID or both optional but at least one should be used. Otherwise the element reference is considered nil and thus redundant.
     * @param elementClass The element class.
     * @param id The optional ID of the referenced element.
     */
    ElementReference(ElementClass *elementClass = nullptr, ElementID *id = nullptr);

    /**
     * Destroys the ElementReference object.
     */
    virtual ~ElementReference();
    
    /**
     * Gets the ID of the referenced element.
     */
    ElementID *getID() const { return mID; }
    
    /**
     * Specifies whether or not the element reference is nil.
     * @return Returns true if the element class is null and the element ID is null. Otherwise returns false.
     */
    bool isNil() const { return getSubject() == nullptr && mID == nullptr; }
    
private:
    /**
     * The ID of the referenced element.
     */
    ElementID *mID;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementReference__ */
