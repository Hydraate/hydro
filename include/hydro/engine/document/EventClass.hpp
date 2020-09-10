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

#ifndef __h3o_engine_EventClass__
#define __h3o_engine_EventClass__

#include "EntityType.hpp"
#include "PrototypeSymbol.hpp"

namespace hydro::engine
{
/**
 * The EventClass represents an event target. Actions bind to elements via an event class that allows the action to observe the element.
 */
class EventClass : public EntityType
{
public:
    /**
     * Creates an EventClass object with a name.
     */
    EventClass(Name *name);

    /**
     * Destroys the EventClass object.
     */
    virtual ~EventClass();
    
    /**
     * Accepts a visitor allowing the visitor to visit the event class.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the prototype symbol that the event class references.
     */
    PrototypeSymbol *getPrototype() const { return mSymbol; }
    
    /**
     * Sets the prototype symbol.
     */
    void setPrototype(PrototypeSymbol *symbol) { mSymbol = symbol; }
    
private:
    /**
     * The element prototype that the event class represents.
     */
    PrototypeSymbol *mSymbol;
};

} // namespace hydro::engine

#endif /* __h3o_engine_EventClass__ */
