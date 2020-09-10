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

#ifndef __h3o_engine_BitwiseLeftShiftExpression__
#define __h3o_engine_BitwiseLeftShiftExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseLeftShiftExpression class represents a bitwise left shift expression in a Performance document.
 */
class BitwiseLeftShiftExpression final : public BinaryExpression
{
public:
    /**
     * Creates a BitwiseLeftShiftExpression object with a left expression and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    BitwiseLeftShiftExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the BitwiseLeftShiftExpression object.
     */
    virtual ~BitwiseLeftShiftExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise left shift expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BitwiseLeftShiftExpression__ */
