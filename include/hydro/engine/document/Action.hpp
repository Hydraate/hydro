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

#ifndef __h3o_engine_Action__
#define __h3o_engine_Action__

#include "ActionIdentity.hpp"
#include "Entity.hpp"

namespace hydro::engine
{
/**
 * The Action class represents an Action entity in a document.
 */
class Action final : public Entity
{
public:
    /**
     * Creates an Action object as a child of some parent entity.
     * @param parent The parent entity that will own the action entity.
     * @param identity The identity that describes the action entity.
     */
    Action(Entity *parent, ActionIdentity *identity);

    /**
     * Destroys the action object.
     */
    virtual ~Action();
    
    /**
     * Accepts a visitor allowing the visitor to visit the action entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Action__ */
