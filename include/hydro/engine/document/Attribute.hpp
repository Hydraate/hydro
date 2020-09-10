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

#ifndef __h3o_engine_Attribute__
#define __h3o_engine_Attribute__

#include <string>

#include "Name.hpp"
#include "Value.hpp"

namespace hydro::engine
{
/**
 * The Attribute class represents an attribute node.
 */
class Attribute : public Node
{
public:
    /**
     * Creates an Attribute object with a name and a value.
     * @param name The name of the attribute.
     * @param value The value of the attribute.
     */
    Attribute(Name *name, Value *value);

    /**
     * Destroys the Attribute object.
     */
    virtual ~Attribute();

    /**
     * Accepts a visitor allowing the visitor to visit the attribute.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Gets the name of the attribute.
     * @return Returns the Name instance that represents the attribute's name.
     */
    Name *getName() const { return mName; }

    /**
     * Gets the value of the attribute.
     * @return Returns the Value instance that represents the attribute's value.
     */
    Value *getValue() const { return mValue; }

private:
    /**
     * The name of the attribute.
     */
    Name *mName;

    /**
     * Any value for the attribute.
     */
    Value *mValue;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Attribute__ */
