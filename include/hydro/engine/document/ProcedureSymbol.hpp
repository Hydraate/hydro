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

#ifndef __h3o_engine_ProcedureSymbol__
#define __h3o_engine_ProcedureSymbol__

#include "Symbol.hpp"

namespace hydro::engine
{

/**
 * The ProcedureSymbol class represents an procedure symbol in a Performance document.
 */
class ProcedureSymbol final : public Symbol
{
public:
    /**
     * Creates an ProcedureSymbol object with a name.
     * @param name The name of the procedure.
     */
    ProcedureSymbol(std::string name);
    
    /**
     * Destroys the ProcedureSymbol object.
     */
    virtual ~ProcedureSymbol();
    
    /**
     * Compares the procedure symbol to another symbol to test equality.
     * @param symbol The symbol to compare.
     * @return Returns true if the supplied symbol can be assumed to be identitical. Otherwise returns false.
     */
    virtual bool compare(Symbol* symbol) const override;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureSymbol__ */
