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

#ifndef __h3o_engine_Selector__
#define __h3o_engine_Selector__

#include "Expression.hpp"

namespace hydro::engine
{

/**
 * The abstract Selector class is the base class for all selector expression types.
 */
class Selector : public Expression
{
protected:
    /**
     * Creates a Selector object.
     */
    Selector();

    /**
     * Creates a Selector object with a token.
     */
    Selector(compiler::Token token);

public:
    /**
     * Destroys the Selector object.
     */
    virtual ~Selector();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Selector__ */
