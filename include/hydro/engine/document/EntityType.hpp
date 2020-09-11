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

#ifndef __h3o_engine_EntityClass__
#define __h3o_engine_EntityClass__

#include <regex>
#include <string>

#include "Name.hpp"
#include "Subject.hpp"

namespace hydro::engine
{
/**
 * The abstract EntityType class is the base class for all entity type classes.
 */
class EntityType : public Subject
{
protected:
    /**
     * Creates an EntityType object with a name.
     * @param name The name of the entity type.
     */
    EntityType(Name *name);

public:
    /**
     * Destroys the EntityType object.
     */
    virtual ~EntityType();
    
    /**
     * Gets the name of the entity type.
     * @return Returns the Name instance that represents the name of the entity type.
     */
    Name *getName() const { return mName; }

private:
    /**
     * The name of the entity type.
     */
    Name *mName;
};

} // namespace hydro::engine

#endif /* __h3o_engine_EntityClass__ */
