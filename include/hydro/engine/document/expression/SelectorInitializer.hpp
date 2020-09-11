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

#ifndef __h3o_engine_SelectorInitializer__
#define __h3o_engine_SelectorInitializer__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The SelectorInitializer class represents a selector initializer expression in a Performance document.
 */
class SelectorInitializer : public Expression
{
public:
    /**
     * Creates SelectorInitializer with a token and a selector.
     * @param token The token.
     * @param selector The selector.
     */
    SelectorInitializer(compiler::Token token, Selector *selector);
    
    /**
     * Destroys the SelectorInitializer object.
     */
    virtual ~SelectorInitializer();
    
    /**
     * Accepts a visitor allowing the visitor to visit the selector initializer expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the selector.
     */
    Selector *getSelector() const { return mSelector; }
    
private:
    /**
     * The selector.
     */
    Selector *mSelector;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SelectorInitializer__ */
