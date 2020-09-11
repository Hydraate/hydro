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

#ifndef __h3o_engine_LessThanExpression__
#define __h3o_engine_LessThanExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The LessThanExpression represents a less than expression in a Performance document.
 */
class LessThanExpression final : public BinaryExpression
{
public:
    /**
     * Creates a LessThanExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    LessThanExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the LessThanExpression object.
     */
    virtual ~LessThanExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the less than expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_LessThanExpression__ */
