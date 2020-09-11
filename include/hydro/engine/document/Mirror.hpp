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

#ifndef __h3o_engine_Mirror__
#define __h3o_engine_Mirror__

#include "expression/Selector.hpp"

#include "Attribute.hpp"
#include "Name.hpp"

namespace hydro::engine
{

/**
 * The Mirror class represents an attribute mirror binding in a Performance document. An attribute mirror binds the value of child attribute to a parent attribute. Whatever the parent value is, the child value copies.
 */
class Mirror final : public Attribute
{
public:
    /**
     * Creates a Mirror object with a name and a value.
     */
    Mirror(Name *name, Value *value);
    
    /**
     * Destroys the Mirror object.
     */
    virtual ~Mirror();
    
    /**
     * Accepts a visitor allowing the visitor to visit the mirror binding.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Mirror__ */
