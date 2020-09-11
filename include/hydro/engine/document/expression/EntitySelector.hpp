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

#ifndef __h3o_engine_EntitySelector__
#define __h3o_engine_EntitySelector__

#include "../EntityType.hpp"

#include "Selector.hpp"

namespace hydro::engine
{
/**
 * The abstract EntitySelector class is the base class of all entity selector types.
 */
class EntitySelector : public Selector
{
protected:
    /**
     * Creates an EntitySelector object.
     */
    EntitySelector();
    
    /**
     * Creates an EntitySelector object with a type.
     * @param type The entity type.
     */
    EntitySelector(EntityType *type);
    
public:
    /**
     * Destroys the EntitySelector object.
     */
    virtual ~EntitySelector();
    
    /**
     * Gets the entity reference.
     */
    EntityType *getType() const { return mType; }
    
private:
    /**
     * The entity type.
     */
    EntityType *mType;
};

} // namespace hydro::engine

#endif /* __h3o_engine_EntitySelector__ */
