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

#ifndef __h3o_engine_RootSelector__
#define __h3o_engine_RootSelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The RootSelector class represents a self selector in a Performance document.
 */
class RootSelector final : public Selector
{
public:
    /**
     * Creates a RootSelector object with a token.
     */
    RootSelector(compiler::Token token);
    
    /**
     * Destroys the RootSelector object.
     */
    virtual ~RootSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the root selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine


#endif /* __h3o_engine_RootSelector__ */
