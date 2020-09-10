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

#ifndef __h3o_engine_IDName__
#define __h3o_engine_IDName__

#include "Node.hpp"

namespace hydro::engine
{

/**
 * The IDName class represents an elements's ID in a Performance document.
 */
class ElementID final : public Node
{
public:
    /**
     * Creates an IDName object with a value.
     * @param token The ID token.
     */
    ElementID(compiler::Token token);
    
    /**
     * Destroys the IDName object.
     */
    virtual ~ElementID();
    
    /**
     * Accepts a visitor allowing the visitor to visit the ID name.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the value of the ID.
     * @return Returns the ID value as a string.
     */
    std::string getValue() const { return mValue; }

private:
    /**
     * The ID's value.
     */
    std::string mValue;
};

} // namespace hydro::engine

#endif /* __h3o_engine_IDName__ */
