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

#ifndef __h3o_engine_ChildSelector__
#define __h3o_engine_ChildSelector__

#include "CompoundSelector.hpp"

namespace hydro::engine
{
/**
 * The ChildSelector class represents a child selector in a Performance document.
 */
class ChildSelector : public CompoundSelector
{
public:
    /**
     * Creates a ChildSelector object with a subject and target selector.
     */
    ChildSelector(Selector *subject, Selector *target);
    
    /**
     * Destroys the ChildSelector object.
     */
    virtual ~ChildSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the child selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ChildSelector__ */
