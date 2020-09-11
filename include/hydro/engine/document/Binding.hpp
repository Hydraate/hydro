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

#ifndef __h3o_engine_Binding__
#define __h3o_engine_Binding__

#include "Node.hpp"

namespace hydro::engine
{

/**
 * The abstract Binding class is the base class of all binding types.
 */
class Binding : public Node
{
protected:
    /**
     * Creates a Binding object.
     */
    Binding();
    
    /**
     * Creates a Binding object with a token.
     * @param token The token.
     */
    Binding(compiler::Token token);
    
public:
    /**
     * Destroys the Binding object.
     */
    virtual ~Binding();

};

} // namespace hydro::engine

#endif /* __h3o_engine_Binding__ */
