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

#ifndef __h3o_engine_ElementClass__
#define __h3o_engine_ElementClass__

#include "EntityType.hpp"
#include "PrototypeSymbol.hpp"

namespace hydro::engine
{
/**
 * The ElementClass class represents a reference to a single element object. The engine uses the element's class to determine which HElement class to instantiate.
 */
class ElementClass final : public EntityType
{
public:
    /**
     * Creates the ElementClass object with a name.
     * @param name The name of the element class.
     */
    ElementClass(Name *name);

    /**
     * Destroys the ElementClass instance.
     */
    virtual ~ElementClass();
    
    /**
     * Accepts a visitor allowing the visitor to visit the element class.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementClass__ */
