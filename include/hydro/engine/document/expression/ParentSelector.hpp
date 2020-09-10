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

#ifndef __h3o_engine_ParentSelector__
#define __h3o_engine_ParentSelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The ParentSelector class represents a self selector in a Performance document.
 */
class ParentSelector final : public Selector
{
public:
    /**
     * Creates a ParentSelector object with a token.
     */
    ParentSelector(compiler::Token token);
    
    /**
     * Destroys the ParentSelector object.
     */
    virtual ~ParentSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the parent selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ParentSelector__ */
