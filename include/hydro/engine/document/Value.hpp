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

#ifndef __h3o_engine_Value__
#define __h3o_engine_Value__

#include "Node.hpp"

namespace hydro::engine
{
/**
 * The abstract Value class is the base class for all value types including expressions and references.
 */
class Value : public Node
{
protected:
    /**
     * Creates a Value object.
     */
    Value();

    /**
     * Creates a Value object with an assigned token.
     */
    Value(compiler::Token token);

public:
    /**
     * Destroys the Value object.
     */
    virtual ~Value();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Value__ */
