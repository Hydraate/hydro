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

#ifndef __h3o_engine_Name__
#define __h3o_engine_Name__

#include <string>

#include "Node.hpp"

namespace hydro::engine
{

/**
 * The abstract Name class is the base class of all name nodes.
 */
class Name : public Node
{
protected:
    /**
     * Creates a Name object with a token.
     * @param token The token.
     */
    Name(compiler::Token token);

public:
    /**
     * Destroys the Name object.
     */
    virtual ~Name();

    /**
     * Gets the value of the name.
     */
    virtual std::string getValue() const = 0;

    /**
     * Specifies whether or not the Name object is a simple name.
     * @return Returns true if this name is a simple name. Otherwise returns false.
     */
    virtual bool isSimpleName() const = 0;

    /**
     * Specifies whether or not the Name object is a qualified name.
     * @return Returns true if this name is a qualified name. Otherwise returns false.
     */
    virtual bool isQualifiedName() const = 0;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Name__ */
