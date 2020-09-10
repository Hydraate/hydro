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

#ifndef __h3o_engine_Symbol__
#define __h3o_engine_Symbol__

#include <string>

namespace hydro::engine
{

class PDocumentContext;

/**
 * The abstract Symbol class is the base class of all symbol types. Symbols keep track of definitions in a Performance document.
 */
class Symbol
{
protected:
    /**
     * Creates an anyonmous Symbol object.
     */
    Symbol();
    
    /**
     * Creates a named Symbol object.
     */
    Symbol(std::string name);
    
public:
    /**
     * Destroys the Symbol object.
     */
    virtual ~Symbol();
    
    /**
     * Gets the name of the symbol.
     * @return Returns a constant reference to the name string.
     */
    const std::string &getName() const { return mName; }
    
    /**
     * Specifies whether or not the symbol is named.
     * @return Returns true if the symbol does not have a named. Otherwise returns false.
     */
    bool isAnonymous() const { return mName.empty(); }
    
    /**
     * Gets the context owner that contains this symbol.
     */
    PDocumentContext *getContext() const { return mContext; }
    
    /**
     * Compares the symbol to another.
     * @return Returns true if both symbol instances can be assumed to be identical. Otherwise returns false.
     */
    virtual bool compare(Symbol *symbol) const = 0;
    
private:
    /**
     * The name of the symbol.
     */
    std::string mName;
    
    /**
     * The context that owns this symbol.
     */
    PDocumentContext *mContext;
    
    friend class PDocumentContext;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Symbol__ */
