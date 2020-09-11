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

#ifndef __h3o_engine_PrototypeSymbol__
#define __h3o_engine_PrototypeSymbol__

#include "Symbol.hpp"

namespace hydro::engine
{

/**
 * The PrototypeSymbol class represents a prototype symbol in a Performance document.
 */
class PrototypeSymbol final : public Symbol
{
public:
    /**
     * Creates a PrototypeSymbol object with a name.
     * @param name The name of the element class.
     */
    PrototypeSymbol(std::string name);

    /**
     * Destroys the PrototypeSymbol object.
     */
    virtual ~PrototypeSymbol();
    
    /**
     * Gets the parent prototype symbol.
     * @return Returns the PrototypeSymbol instance that represents the parent symbol. Returns null if the prototype does not inherit or the parent prototype has not been set.
     */
    PrototypeSymbol *getParent() const { return mParent; }
    
    /**
     * Sets the parent prototype symbol.
     * @param parent The parent prototype symbol.
     */
    void setParent(PrototypeSymbol *parent) { mParent = parent; }
    
    /**
     * Compares the protoype symbol to another symbol to test equality.
     * @param symbol The symbol to compare.
     * @return Returns true if the supplied symbol can be assumed to be identitical. Otherwise returns false.
     */
    virtual bool compare(Symbol* symbol) const override;
    
private:
    /**
     * The parent prototype.
     */
    PrototypeSymbol *mParent;
};

} // namespace hydro::engine

#endif /* __h3o_engine_PrototypeSymbol__ */
