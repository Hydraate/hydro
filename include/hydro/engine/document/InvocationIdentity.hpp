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

#ifndef __h3o_engine_InvocationIdentity__
#define __h3o_engine_InvocationIdentity__

#include "Identity.hpp"
#include "InvocationTarget.hpp"

namespace hydro::engine
{
/**
 * The InvocationIdentity class stores information about the identity of an invocation entity in a Performance document.
 */
class InvocationIdentity final : public Identity
{
public:
    /**
     * Creates an InvocationIdentity with relationships and an invocation target.
     * @param target The invocation target.
     */
    InvocationIdentity(InvocationTarget *target);

    /**
     * Destroys the InvocationIdentity object.
     */
    virtual ~InvocationIdentity();

    /**
     * Accepts a visitor allowing the visitor to visit the invocation identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Gets the invocation target. This is the same as the identity's subject.
     */
    InvocationTarget *getTarget() const { return mTarget; }
    
private:
    /**
     * The invocation target.
     */
    InvocationTarget *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_InvocationIdentity__ */
