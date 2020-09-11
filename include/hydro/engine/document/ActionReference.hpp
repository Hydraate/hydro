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

#ifndef __h3o_engine_ActionReference__
#define __h3o_engine_ActionReference__

#include "EventClass.hpp"
#include "SimpleReference.hpp"

namespace hydro::engine
{

/**
 * The ActionReference class represents a direct reference to an action entity.
 */
class ActionReference final : public SimpleReference
{
public:
    /**
     * Creates an ActionReference object with a name.
     * @param _class The event class.
     */
    ActionReference(EventClass *_class);
    
    /**
     * Destroys the ActionReference class.
     */
    virtual ~ActionReference();
};

} // namespace hydro::engine

#endif /* __h3o_engine_ActionReference__ */
