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

#ifndef __h3o_engine_ActionSelector__
#define __h3o_engine_ActionSelector__

#include "../EventClass.hpp"

#include "EntitySelector.hpp"

namespace hydro::engine
{

/**
 * The ActionSelector class represents an action selector in a Perfrmance document.
 */
class ActionSelector final : public EntitySelector
{
public:
    /**
     * Creates an ActionSelector object with an event class.
     * @param _class The event class.
     */
    ActionSelector(EventClass *_class);
    
    /**
     * Destroys the ActionSelector object.
     */
    virtual ~ActionSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the action selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ActionSelector__ */
