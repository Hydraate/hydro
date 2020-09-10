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

#ifndef __h3o_Prototype__
#define __h3o_Prototype__

#include "Entity.hpp"
#include "PrototypeIdentity.hpp"

namespace hydro::engine
{
/**
 * The Prototype class represents an element prototype in a Performance document.
 */
class Prototype final : public Entity
{
public:
    /**
     * Creates a Prototype object with some parent entity and an identity.
     * @param parent The parent entity.
     * @param identity The prototype identity.
     */
    Prototype(Entity *parent, PrototypeIdentity *identity);
    
    /**
     * Destroys the Prototype object.
     */
    virtual ~Prototype();

    /**
     * Accepts a visitor allowing the visitor to visit the prototype entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_Prototype__ */
