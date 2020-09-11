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

#ifndef __h3o_engine_LessThanOrEqualExpression__
#define __h3o_engine_LessThanOrEqualExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The LessThanOrEqualExpression represents a less than or equal expression in a Performance document.
 */
class LessThanOrEqualExpression final : public BinaryExpression
{
public:
    /**
     * Creates a LessThanOrEqualExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    LessThanOrEqualExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the LessThanOrEqualExpression object.
     */
    virtual ~LessThanOrEqualExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the less than or equal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_LessThanOrEqualExpression__ */
