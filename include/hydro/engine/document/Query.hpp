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

#ifndef __h3o_engine_Query__
#define __h3o_engine_Query__

#include "Entity.hpp"
#include "QueryIdentity.hpp"

namespace hydro::engine
{
/**
 * The Query class represents a query entity that selects and modifies a collection of similar entity instances.
 */
class Query final : public Entity
{
public:
    /**
     * Creates a Query object as a child of some parent entity.
     */
    Query(Entity *parent, QueryIdentity *identity);

    /**
     * Destroys the Query object.
     */
    virtual ~Query();
    
    /**
     * Accepts a visitor allowing the visitor to visit the query entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Query__ */
