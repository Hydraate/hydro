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

#ifndef __h3o_engine_SimpleReference__
#define __h3o_engine_SimpleReference__

#include "Reference.hpp"
#include "Subject.hpp"

namespace hydro::engine
{
/**
 * The abstract SimpleReference class is the base class of all simple reference types.
 */
class SimpleReference : public Reference
{
protected:
    /**
     * Creates a Reference object with a target.
     * @param subject The referenced subject.
     */
    SimpleReference(Subject *subject);
    
public:
    /**
     * Destroys the SimpleReference object.
     */
    virtual ~SimpleReference();
    
    /**
     * Gets the subject.
     */
    Subject *getSubject() const { return mSubject; }
    
private:
    /**
     * The subject of the simple reference.
     */
    Subject *mSubject;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SimpleReference__ */
