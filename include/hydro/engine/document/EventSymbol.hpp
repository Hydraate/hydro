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

#ifndef __h3o_engine_EventSymbol__
#define __h3o_engine_EventSymbol__

#include "Symbol.hpp"

namespace hydro::engine
{

/**
 * The EventSymbol class represents an event symbol in a Performance document.
 */
class EventSymbol final : public Symbol
{
public:
    /**
     * Creates an EventSymbol object with a name.
     * @param name The name of the event class.
     */
    EventSymbol(std::string name);
    
    /**
     * Destroys the EventSymbol object.
     */
    virtual ~EventSymbol();
    
    /**
     * Compares the event symbol to another symbol to test equality.
     * @param symbol The symbol to compare.
     * @return Returns true if the supplied symbol can be assumed to be identitical. Otherwise returns false.
     */
    virtual bool compare(Symbol* symbol) const override;
};

} // namespace hydro::engine

#endif /* __h3o_engine_EventSymbol__ */
