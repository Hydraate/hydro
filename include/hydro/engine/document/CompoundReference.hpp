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

#ifndef __h3o_engine_CompoundTarget__
#define __h3o_engine_CompoundTarget__

#include "SimpleReference.hpp"

namespace hydro::engine
{
/**
 * The CompoundReference class represents a reference to an entity that is nested within another target.
 */
class CompoundReference final : public Reference
{
public:
    /**
     * Creates a CompoundTarget object with a subject and a simple target.
     * @param subject The subject target.
     * @param token The token.
     * @param target The final target.
     */
    CompoundReference(Reference *subject, compiler::Token token, SimpleReference *target);

    /**
     * Destroys the CompoundTarget object.
     */
    virtual ~CompoundReference();

    /**
     * Gets the subject.
     * @return Returns the Target instance the represents the subject in the compound target.
     */
    Reference *getSubject() const { return mSubject; }

    /**
     * Gets the destination target.
     * @return Returns the SimpleTarget instance that represents the destination target of this compound target.
     */
    SimpleReference *getTarget() const { return mTarget; }

private:
    /**
     * The subject target.
     */
    Reference *mSubject;

    /**
     * The destination reference.
     */
    SimpleReference *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_CompoundTarget__ */
