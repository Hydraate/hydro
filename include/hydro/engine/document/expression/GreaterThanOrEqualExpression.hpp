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

#ifndef __h3o_engine_GreaterThanOrEqualExpression__
#define __h3o_engine_GreaterThanOrEqualExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The GreaterThanOrEqualExpression represents a greater than or equal expression in a Performance document.
 */
class GreaterThanOrEqualExpression final : public BinaryExpression
{
public:
    /**
     * Creates a GreaterThanExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    GreaterThanOrEqualExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the GreaterThanExpression object.
     */
    virtual ~GreaterThanOrEqualExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the greater than or equal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_GreaterThanOrEqualExpression__ */
