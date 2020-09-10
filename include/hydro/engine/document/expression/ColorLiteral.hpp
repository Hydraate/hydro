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

#ifndef __h3o_engine_ColorLiteral__
#define __h3o_engine_ColorLiteral__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The ColorLiteral class represents a color literal in a Performance document.
 */
class ColorLiteral final : public Expression
{
public:
    /**
     * Creates a ColorLiteral object with a token.
     */
    ColorLiteral(compiler::Token token);

    /**
     * Destroys the ColorLiteral object.
     */
    virtual ~ColorLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the color literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ColorLiteral__ */
