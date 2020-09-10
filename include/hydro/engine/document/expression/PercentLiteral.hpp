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

#ifndef __h3o_engine_PercentLiteral__
#define __h3o_engine_PercentLiteral__

#include "NumberLiteral.hpp"

namespace hydro::engine
{
/**
 * The PercentLiteral class represents a percent literal in a Performance document.
 */
class PercentLiteral final : public Expression
{
public:
    /**
     * Creates a PercentLiteral object with a token and a number.
     * @param token The token that represents the percent sign.
     * @param value The number literal that represents the value of the percentage.
     */
    PercentLiteral(compiler::Token token, NumberLiteral *value);
    
    /**
     * Destroys the PercentLiteral object.
     */
    virtual ~PercentLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the percent literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the percentage value.
     */
    NumberLiteral *getValue() const { return mValue; }

private:
    /**
     * The value of the percentage.
     */
    NumberLiteral *mValue;
};

} // namespace hydro::engine

#endif /* __h3o_engine_PercentLiteral__ */
