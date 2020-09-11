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

#ifndef __h3o_engine_Reference__
#define __h3o_engine_Reference__

#include "Node.hpp"

namespace hydro::engine
{

/**
 * The abstract Reference class represents a reference to some entity in the Performance document. It is the base class of all reference classes. References are required to semantically distingure various selectors from direct references.
 */
class Reference : public Node
{
protected:
    /**
     * Creates a Reference object.
     */
    Reference();
    
    /**
     * Creates a Reference object with a token.
     * @param token The token.
     */
    Reference(compiler::Token token);
    
public:
    /**
     * Destroys the Reference object.
     */
    virtual ~Reference();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Reference__ */
