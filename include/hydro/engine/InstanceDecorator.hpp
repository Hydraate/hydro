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

#ifndef __h3o_engine_InstanceDecorator__
#define __h3o_engine_InstanceDecorator__

#include "Element.hpp"
#include "Instance.hpp"

namespace hydro::engine
{
/**
 * The InstanceDecorator class decorates an Instance by adding the appropriate entities as children and altering the state of the instance.
 */
class InstanceDecorator
{
protected:
    /**
     * Creates an EntityDecorator object.
     */
    InstanceDecorator(Instance *instance, Entity *entity);

public:
    /**
     * Destroys the EntityDecorator.
     */
    virtual ~InstanceDecorator();

    /**
     * Gets the instance
     * @return Returns the Instance that the EntityDecorator
     */
    Instance *getInstance() const { return mInstance; }

    /**
     * Gets the Entity associated with the decorator. The Entity is used to describe
     * @return Returns the Entity that provides information on how the decorator should affect the instance.
     */
    Entity *getEntity() const { return mEntity; }

private:
    /**
     * The Instance that the decorator will manipute.
     */
    Instance *mInstance;

    /**
     * The Entity that contains data about how to decorate the Instance.
     */
    Entity *mEntity;
};

} // namespace hydro::engine

#endif /* __h3o_engine_EntityDecorator__ */
