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

#ifndef __h3o_engine_Invocation__
#define __h3o_engine_Invocation__

#include "Entity.hpp"
#include "InvocationIdentity.hpp"

namespace hydro::engine
{

/**
 * The Invocation class represents an invocation entity in a Performance document.
 */
class Invocation : public Entity
{
public:
    /**
     * Creates an Invocation object with some parent entity and an identity.
     * @param parent The parent entity.
     * @param identity The invocation identity.
     */
    Invocation(Entity *parent, InvocationIdentity *identity);

    /**
     * Destroys the Invocation object.
     */
    virtual ~Invocation();
    
    /**
     * Accepts a visitor allowing the visitor to visit the invocation entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Invocation__ */
