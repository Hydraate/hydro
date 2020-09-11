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

#ifndef __h3o_engine_Expression__
#define __h3o_engine_Expression__

#include "../Value.hpp"

namespace hydro::engine
{
/**
 * The abstract Expression class is the base class of all expressions. Expressions can be validated indepenently of the interpreter in a tree based way.
 */
class Expression : public Value
{
protected:
    /**
     * Creates the Expression object.
     */
    Expression();

    /**
     * Creates the Expression object.
     */
    Expression(compiler::Token token);

public:
    /**
     * Destructs the Expression object.
     */
    virtual ~Expression();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Expression__ */
