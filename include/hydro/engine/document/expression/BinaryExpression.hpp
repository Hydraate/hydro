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

#ifndef __h3o_engine_BinaryExpression__
#define __h3o_engine_BinaryExpression__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The BinaryExpression class represents an expression that requires two and only two operands.
 */
class BinaryExpression : public Expression
{
protected:
    /**
     * Creates a BinaryExpression object with a left expression and a right expression.
     * @param lhs The expression of the left-hand side of the binary expression.
     * @param rhs The expression on the right-hand side of the binary expression.
     */
    BinaryExpression(Expression *lhs, Expression *rhs);

    /**
     * Creates a BinaryExpression object with a left expression and a right expression.
     * @param lhs The expression of the left-hand side of the binary expression.
     * @param token The token that represents the binary operator.
     * @param rhs The expression on the right-hand side of the binary expression.
     */
    BinaryExpression(Expression *lhs, compiler::Token token, Expression *rhs);

public:
    /**
     * Destroys the BinaryExpression object.
     */
    virtual ~BinaryExpression();

    /**
     * Gets the expression to the left-hand side.
     * @return Returns the Expression object to the left hand side of the binary expression.
     */
    Expression *getLhs() const { return mLhs; }

    /**
     * Gets the expression to the right-hand side.
     * @return Returns the Expression object to the right hand side of the binary expression.
     */
    Expression *getRhs() const { return mRhs; }

private:
    /**
     * The left-hand side of the expression;
     */
    Expression *mLhs;

    /**
     * The right-hand side of the expression.
     */
    Expression *mRhs;
};

} // namespace hydro::engine

#endif /* __h3o_engine_BinaryExpression__ */
