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

#ifndef __h3o_engine_ModelIdentity__
#define __h3o_engine_ModelIdentity__

#include "Identity.hpp"
#include "ModelDescription.hpp"

namespace hydro::engine
{

/**
 * The ModelIdentity class represents a model identity in a Performance document.
 */
class ModelIdentity final : public Identity
{
public:
    /**
     * Creates a ModelIdentity object with a model description.
     * @param description The model description that describes the data model.
     */
    ModelIdentity(ModelDescription *description);
    
    /**
     * Destroys the ModelIdentity object.
     */
    virtual ~ModelIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the model identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ModelIdentity__ */
