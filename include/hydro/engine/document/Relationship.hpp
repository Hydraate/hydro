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

#ifndef __h3o_engine_Relationship__
#define __h3o_engine_Relationship__

#include "expression/MultiplicityLiteral.hpp"

#include "Name.hpp"
#include "Node.hpp"

namespace hydro::engine
{

class Relationship final : public Node
{
public:
    /**
     * Creates a Relationship object with a name.
     */
    Relationship(Name *name);
    
    /**
     * Creates a Relationship
     */
    Relationship(Name *name, MultiplicityLiteral *multiplcitiy);
    
    /**
     * Destroys the Relationship object.
     */
    virtual ~Relationship();
    
    /**
     * Gets the name of the relationship.
     */
    Name *getName() const { return mName; }
    
    /**
     * Gets the multiplicity of the relationship.
     */
    MultiplicityLiteral *getMultiplicity() const { return mMultiplicity; }

private:
    /**
     * The name of the relationship.
     */
    Name *mName;
    
    /**
     * The multiplicity of the relationship.0o='
     */
    MultiplicityLiteral *mMultiplicity;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Relationship__ */
