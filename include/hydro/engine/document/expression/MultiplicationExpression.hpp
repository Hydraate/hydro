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

#ifndef __h3o_engine_MultiplicationExpression__
#define __h3o_engine_MultiplicationExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The MultiplicationExpression represents a multiplication expression in a Performance document.
 */
class MultiplicationExpression final : public BinaryExpression
{
public:
    /**
     * Creates a MultiplicationExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    MultiplicationExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the MultiplicationExpression object.
     */
    virtual ~MultiplicationExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the multiplication expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine
#endif /* __h3o_engine_MultiplicationExpression__ */
