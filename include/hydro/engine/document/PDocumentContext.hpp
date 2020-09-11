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

#ifndef __h3o_PDocumentContext__
#define __h3o_PDocumentContext__

#include <vector>

#include "Symbol.hpp"

namespace hydro::engine
{

class Entity;

/**
 * The PDocumentContext implements scope in a Performance document. Each entity contains its own context. The highest level context should always be the document's context.
 */
class PDocumentContext
{
public:
    /**
     * Creates PDocumentContext object that is the root context in a Performance document.
     */
    PDocumentContext();
    
    /**
     * Creates PDocumentContext object that is a child of some other context.
     */
    PDocumentContext(PDocumentContext *parent);
    
    /**
     * Destroys the PDocumentContext object.
     */
    virtual ~PDocumentContext();
    
    /**
     * Determines if a supplied symbol is contained with this context.
     * @return Returns true if the PDocumentContext object contains the symbol. Otherwise returns false.
     */
    bool contains(Symbol *symbol);
    
    /**
     * Appends a symbol to the context.
     * @param symbol The symbol to append to the context.
     */
    void define(Symbol *symbol);
    
    /**
     * Gets the list of symbols contained within this context.
     * @return Returns a constant reference to the vector contained symbols owned by the PDocumentContext object.
     */
    const std::vector<Symbol *> &symbols() const { return mSymbols; }
    
    /**
     * Gets the parent context, or in other words, the enclosing scope.
     */
    PDocumentContext *getParent() const { return mParent; }
    
    /**
     * Gets entity that owns this context.
     * @return Returns the Entity instance that owns the PDocumentContext object. Returns null if the context is not owned.
     */
    Entity *getOwner() const { return mOwner; }
    
protected:
    /**
     * The list of symbols contained within this scope.
     */
    std::vector<Symbol *> mSymbols;
    
    /**
     * The parent context.
     */
    PDocumentContext *mParent;
    
    /**
     * The entity owner.
     */
    Entity *mOwner;
    
    friend class Entity;
};

} // namespace hydro::engine

#endif /* __h3o_PDocumentContext__ */
