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

#ifndef __h3o_engine_InequalityExpression__
#define __h3o_engine_InequalityExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The InequalityExpression class represents an inequality expression in a Performanece document.
 */
class InequalityExpression final : public BinaryExpression
{
public:
    /**
     * Creates an InequalityExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
    */
    InequalityExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the InequalityExpression object.
     */
    virtual ~InequalityExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the inequality expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};


} // namespace hydro::engine

#endif /* __h3o_engine_InequalityExpression__ */
