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

#ifndef __h3o_engine_InvocationReference__
#define __h3o_engine_InvocationReference__

#include "InvocationTarget.hpp"
#include "SimpleReference.hpp"

namespace hydro::engine
{

/**
 * The InvocationReference class represents a reference to invocation in a Performance document.
 */
class InvocationReference final : public SimpleReference
{
public:
    /**
     * Creates an InvocationReference object with an invocation target.
     * @param target The invocation target.
     */
    InvocationReference(InvocationTarget *target);
    
    /**
     * Destroys the InvocationReference object.
     */
    virtual ~InvocationReference();
    
    /**
     * Accepts a visitor allowing the visitor to visit the invocation reference.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the invocation target reference.
     */
    InvocationTarget *getTarget() const { return mTarget; }
    
private:
    /**
     * The invocation target reference.
     */
    InvocationTarget *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_InvocationReference__ */
