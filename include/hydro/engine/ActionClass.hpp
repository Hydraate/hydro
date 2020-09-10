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

#ifndef __h3o_engine_ActionClass__
#define __h3o_engine_ActionClass__

#include "EntityType.hpp"

namespace hydro::engine
{
/**
 * The ActionClass represents an event target.
 */
class EventClass : public EntityType
{
public:
    /**
     * 
     */
    EventClass(Name *name);

    /**
     * 
     */
    virtual ~EventClass();
};

} // namespace hydro::engine

#endif /* __h3o_engine_ActionClass__ */
