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

#ifndef __h3o_engine_ModelDescription__
#define __h3o_engine_ModelDescription__

#include "expression/StringLiteral.hpp"

#include "Subject.hpp"

namespace hydro::engine
{

class ModelDescription : public Subject
{
public:
    /**
     * Creates a ModelDescription object with a key represented as a string literal.
     */
    ModelDescription(StringLiteral *key);
    
    /**
     * Destroys the ModelDescription object.
     */
    virtual ~ModelDescription();
    
    /**
     * Accepts a visitor allowing the visitor to visit the model description.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

private:
    /**
     * The property key.
     */
    StringLiteral *mKey;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ModelDescription__ */
