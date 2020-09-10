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

#ifndef __h3o_engine_SelfSelector__
#define __h3o_engine_SelfSelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The SelfSelector class represents a self selector in a Performance document.
 */
class SelfSelector final : public Selector
{
public:
    /**
     * Creates a SelfSelector object with a token.
     */
    SelfSelector(compiler::Token token);
    
    /**
     * Destroys the SelfSelector object.
     */
    virtual ~SelfSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the self selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_SelfSelector__ */
