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

#ifndef __h3o_engine_MultiplicityLiteral__
#define __h3o_engine_MultiplicityLiteral__

#include "NumberLiteral.hpp"

namespace hydro::engine
{
/**
 * The MultiplicityLiteral class represents a multiplicity literal in a Performance document.
 */
class MultiplicityLiteral final : public Expression
{
public:
    /**
     * Creates a MultiplicityLiteral object with minimum and maximum cardinals.
     * @param min The minumum cardinal as a represented as a number literal.
     * @param max The maximum cardinal as a represented as a number literal.
     */
    MultiplicityLiteral(NumberLiteral *min, NumberLiteral *max);

    /**
     * Destroys the MultiplicityLiteral object.
     */
    virtual ~MultiplicityLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the multiplicity literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Gets the minumum cardinal.
     * @return Returns a NumberLiteral instance the represents the minimum cardinal.
     */
    NumberLiteral *getMin() const { return mMin; }

    /**
     * Gets the maximum cardinal.
     * @return Returns a NumberLiteral instance the represents the maximum cardinal.
     */
    NumberLiteral *getMax() const { return mMax; }

private:
    /**
     * The minimum cardinal.
     */
    NumberLiteral *mMin;

    /**
     * The maximum cardinal.
     */
    NumberLiteral *mMax;
};

} // namespace hydro::engine

#endif /* __h3o_engine_MultiplicityLiteral__ */
