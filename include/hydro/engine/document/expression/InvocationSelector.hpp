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

#ifndef __h3o_engine_InvocationSelector__
#define __h3o_engine_InvocationSelector__

#include "../Target.hpp"
#include "Selector.hpp"

namespace hydro::engine
{
/**
 * The InvocationSelector class represents a selector for an invocation entity.
 */
class InvocationSelector final : public Selector
{
public:
    /**
     *
     */
    InvocationSelector(Selector *target);

    /**
     *
     */
    virtual ~InvocationSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the invocation selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     *
     */
    Selector *getTarget() const { return mTarget; }

private:
    /**
     *
     */
    Selector *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_InvocationSelector__ */
