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

#ifndef __h3o_engine_AttributeQualifier__
#define __h3o_engine_AttributeQualifier__

#include "../Name.hpp"
#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The AttributeSelector class represents a selector for a single attribute value.
 */
class AttributeSelector final : public Selector
{
public:
    /**
     * Creates an AttributeSelector object with a name qualifier.
     */
    AttributeSelector(Name *name);

    /**
     * Destroys the AttributeSelector object.
     */
    virtual ~AttributeSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the attribute selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Gets the name qualifier for the attribute.
     * @return Returns a pointer to the Name object that represents the attribute's name.
     */
    Name *getName() const { return mName; }

private:
    /**
     * The name of the entity.
     */
    Name *mName;
};

} // namespace hydro::engine

#endif /* __h3o_engine_AttributeQualifier__ */
