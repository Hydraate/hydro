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

#ifndef __h3o_engine_InvocationTarget__
#define __h3o_engine_InvocationTarget__

#include "Target.hpp"
#include "Reference.hpp"

namespace hydro::engine
{

/**
 * The InvocationTarget class binds a reference to a target as required by an invocation entity in a Performance document.
 */
class InvocationTarget : public Target
{
public:
    /**
     * Creates an InvocationTarget object with a reference.
     */
    InvocationTarget(Reference *reference);
    
    /**
     * Destroys the InvocationTarget object.
     */
    virtual ~InvocationTarget();
    
    /**
     * Gets the reference.
     */
    Reference *getReference() const { return mReference; }
    
private:
    /**
     *
     */
    Reference *mReference;
};

} // namespace hydro::engine

#endif /* __h3o_engine_InvocationTarget__ */
