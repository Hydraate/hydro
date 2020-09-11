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

#ifndef __h3o_engine_Model__
#define __h3o_engine_Model__

#include "Entity.hpp"
#include "ModelIdentity.hpp"

namespace hydro::engine
{
/**
 * The Model class represents a model entity in a Performance document.
 */
class Model final : public Entity
{
public:
    /**
     * Creates a Model object as a child of some entity.
     * @param parent The parent entity.
     * @param identity The model identity.
     */
    Model(Entity *parent, ModelIdentity *identity);
    
    /**
     * Destroys the Model object.
     */
    virtual ~Model();
    
    /**
     * Accepts a visitor allowing the visitor to visit the model.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Model__ */
