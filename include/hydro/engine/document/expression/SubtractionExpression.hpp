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

#ifndef __h3o_engine_SubtractionExpression__
#define __h3o_engine_SubtractionExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The SubtractionExpression represents a subtraction expression in a Performance document.
 */
class SubtractionExpression final : public BinaryExpression
{
public:
    /**
     * Creates a SubtractExpression object with a left expression and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    SubtractionExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the RemainderExpression object.
     */
    virtual ~SubtractionExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the substraction expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};


} // namespace hydro::engine

#endif /* __h3o_engine_SubtractionExpression__ */
