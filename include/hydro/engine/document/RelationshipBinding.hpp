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

#ifndef __h3o_engine_RelationshipBinding__
#define __h3o_engine_RelationshipBinding__

#include <string>

namespace hydro::engine
{
class Entity;

/**
 * The RelationshipBinding struct establishes a formal relationship binding between two entities. The engine supports user-defined rules for relationships.
 * For example, most UI elements require the "content" relationship in order to be displayed graphically.
 */
struct RelationshipBinding

{
    /**
     * The name of the relationship.
     */
    std::string name;

    /**
     * A reference to the parent in the relationship.
     */
    Entity *parent;

    /**
     * A reference to the child in the relationship.
     */
    Entity *child;
};

} // namespace hydro::engine

#endif /* __h3o_engine_RelationshipBinding__ */
