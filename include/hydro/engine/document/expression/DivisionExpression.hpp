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

#ifndef __h3o_engine_DivisionExpression__
#define __h3o_engine_DivisionExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The DivisionExpression represents a division expression in a Performance document.
 */
class DivisionExpression final : public BinaryExpression
{
public:
    /**
     * Creates a DivisionExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    DivisionExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the DivisionExpression object.
     */
    virtual ~DivisionExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the division expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_DivisionExpression__ */
