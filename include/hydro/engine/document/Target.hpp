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

#ifndef __h3o_engine_Target__
#define __h3o_engine_Target__

#include "expression/Selector.hpp"

#include "Subject.hpp"

namespace hydro::engine
{
/**
 * The abstract Target class represents an indirect reference to zero or more entities. Subclasses of the Target class bind an expression or refernce.
 */
class Target : public Subject
{
protected:
    /**
     * Creates a Target object.
     */
    Target();

public:
    /**
     * Destroys the Target object.
     */
    virtual ~Target();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Target__ */
