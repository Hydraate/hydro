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

#ifndef __h3o_engine_DescendantSelector__
#define __h3o_engine_DescendantSelector__

#include "CompoundSelector.hpp"

namespace hydro::engine
{

/**
 * The DescendantSelector class represents a decendant selector in a Performance document.
 */
class DescendantSelector final : public CompoundSelector
{
public:
    /**
     * Creates a DescendantSelector object.
     * @param subject The subject selector.
     * @param target The target selector.
     */
    DescendantSelector(Selector *subject, Selector *target);
    
    /**
     * Destroys the DescendantSelector object.
     */
    virtual ~DescendantSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the descendant selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_DescendantSelector__ */
