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

#ifndef __h3o_engine_LogicalANDExpression__
#define __h3o_engine_LogicalANDExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The LogicalANDExpression represents a logical AND expression in a Performance document.
 */
class LogicalANDExpression final : public BinaryExpression
{
public:
    /**
     * Creates a LogicalANDExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    LogicalANDExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the LessThanOrEqualExpression object.
     */
    virtual ~LogicalANDExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the logical AND expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_LogicalANDExpression__ */
