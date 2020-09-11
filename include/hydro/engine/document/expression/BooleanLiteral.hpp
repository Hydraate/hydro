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

#ifndef __h3o_engine_BooleanLiteral__
#define __h3o_engine_BooleanLiteral__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The BooleanLiteral class represents a boolean literal in a Performance document.
 */
class BooleanLiteral final : public Expression
{
public:
    /**
     *
     */
    BooleanLiteral(compiler::Token token);

    /**
     *
     */
    virtual ~BooleanLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the boolean literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BooleanLiteral__ */
