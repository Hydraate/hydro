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

#ifndef __h3o_enine_BitwiseRightShiftExpression__
#define __h3o_enine_BitwiseRightShiftExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseRightShiftExpression class represents a bitwise right shift expression in a Performance document.
 */
class BitwiseRightShiftExpression final : public BinaryExpression
{
public:
    /**
     * Creates a BitwiseORExpression object with a left expresssion and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    BitwiseRightShiftExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the BitwiseRightShiftExpression object.
     */
    virtual ~BitwiseRightShiftExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise right shift expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_enine_BitwiseRightShiftExpression__ */
