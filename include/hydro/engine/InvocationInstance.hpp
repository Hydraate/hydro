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

#ifndef __h3o_engine_InvocationInstance__
#define __h3o_engine_InvocationInstance__

#include "Instance.hpp"

namespace hydro::engine
{
class iInvocable;

/**
 * The InvocationInstance class represents an instance of the invocation entity invokes a target or set of targets.
 */
class InvocationInstance final : public Instance
{
public:
    /**
     * Creates an InvocationInstance object with an invocable target.
     */
    InvocationInstance(iInvocable *target);

    /**
     * Destroys the InvocationInstance object.
     */
    virtual ~InvocationInstance();

private:
    /**
     * The invocation target that will be called.
     */
    iInvocable *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_InvocationInstance__ */
