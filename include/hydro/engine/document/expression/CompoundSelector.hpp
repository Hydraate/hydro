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

#ifndef __h3o_engine_BinarySelector__
#define __h3o_engine_BinarySelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The abstract CompoundSelector class is the base class for all compound selector types. A compound selector is very similar to the concept of a binary expression. There is a selector to the left and to the right of the compound selector. All compound selectors are left associative and have identical precedence such that they can be evaluated from left to right. The compound selector normally represents a selector to some sort of attribute or nested descendant element.
 */
class CompoundSelector : public Selector
{
protected:
    /**
     * Creates a CompoundSelector object with a token, a subject selector, and a target selector.
     * @param subject The selector to the left of the compound selector. The subject may or may not be a compound selector.
     * @param target The selector to the right of the compound selector. The target should never be a compound selector.
     */
    CompoundSelector(Selector *subject, Selector *target);

public:
    /**
     * Destroys the CompoundSelector object.
     */
    virtual ~CompoundSelector();
    
    /**
     * Gets the subject selector.
     * @return Returns the Selector instance that represents the left selector (also called the subject).
     */
    Selector *getSubject() const { return mSubject; }
    
    /**
     * Gets the target selector.
     * @return Returns the Selector instance that represents the righ selector (also called the target).
     */
    Selector *getTarget() const { return mTarget; }
    
    /**
     * Computes the selector that is the left-most selector.
     * @return Returns a selector expression.
     */
    Selector *getTop() const;
    
private:
    /**
     * The left selector.
     */
    Selector *mSubject;
    
    /**
     * The right selector.
     */
    Selector *mTarget;
};

} // namespace hydro::engine


#endif /* BinarySelector_hpp */
