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

#ifndef __h3o_engine_SnapshotContextSymbol__
#define __h3o_engine_SnapshotContextSymbol__

#include "Symbol.hpp"

namespace hydro::engine
{

/**
 * The SnapshotContextSymbol class represents a snapshot context symbol in a Performance document.
 */
class SnapshotContextSymbol final : public Symbol
{
public:
    /**
     * Creates a SnapshotContextSymbol object with a name.
     * @param name The name of the snapshot domain.
     */
    SnapshotContextSymbol(std::string name);
    
    /**
     * Destroys the SnapshotContextSymbol object.
     */
    virtual ~SnapshotContextSymbol();
    
    /**
     * Compares the snapshot context symbol to another symbol to test equality.
     * @param symbol The symbol to compare.
     * @return Returns true if the supplied symbol can be assumed to be identitical. Otherwise returns false.
     */
    virtual bool compare(Symbol* symbol) const override;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SnapshotContextSymbol__ */
