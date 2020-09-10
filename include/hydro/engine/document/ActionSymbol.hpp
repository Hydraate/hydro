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

#ifndef ActionSymbol_hpp
#define ActionSymbol_hpp

#include "Symbol.hpp"

namespace hydro::engine
{

/**
 * The ActionSymbol class represents an action symbol in a Performance document.
 */
class ActionSymbol final : public Symbol
{
public:
    /**
     * Creates an ActionSymbol object with a name.
     * @param name The name of the action class.
     */
    ActionSymbol(std::string name);
    
    /**
     * Destroys the ActionSymbol object.
     */
    virtual ~ActionSymbol();
    
    /**
     * Compares the action symbol to another symbol to test equality.
     * @param symbol The symbol to compare.
     * @return Returns true if the supplied symbol can be assumed to be identitical. Otherwise returns false.
     */
    virtual bool compare(Symbol* symbol) const override;
};

} // namespace hydro::engine

#endif /* ActionSymbol_hpp */
