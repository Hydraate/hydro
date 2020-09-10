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

#ifndef __h3o_engine_ConditionalExpression__
#define __h3o_engine_ConditionalExpression__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The ConditionalExpression class represents a conditional ternary expression in a Performance document.
 */
class ConditionalExpression final : public Expression
{
public:
    
    /**
     * Creates a ConditionalExpression object with a condition expression, true expression, and false expression.
     * @param condition The condition expression.
     * @param trueExpression The true expression.
     * @param falseExpression The false expression.
     */
    ConditionalExpression(Expression *condition, Expression *trueExpression, Expression *falseExpression);
    
    /**
     * Destroys the ConditionalExpression object.
     */
    virtual ~ConditionalExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the conditional expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the condition expression.
     * @return Returns an Expression object that represents the condition expression.
     */
    Expression *getCondition() const { return mCondition; }
    
    /**
     * Gets the true expression.
     * @return Returns an Expression object that represents the true expression.
     */
    Expression *getTrueExpression() const { return mTrueExpression; }
    
    /**
     * Gets the false expression.
     * @return Returns an Expression object that represents the false expression.
     */
    Expression *getFalseExpression() const { return mFalseExpression; }
    
private:
    /**
     * The condition expression.
     */
    Expression *mCondition;
    
    /**
     * The true expression.
     */
    Expression *mTrueExpression;
    
    /**
     * The false expression.
     */
    Expression *mFalseExpression;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ConditionalExpression__ */
