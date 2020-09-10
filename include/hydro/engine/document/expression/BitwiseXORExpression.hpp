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

#ifndef __h3o_engine_BitwiseXORExpression__
#define __h3o_engine_BitwiseXORExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseXORExpression class represents a bitwise XOR expression in a Performance document.
 */
class BitwiseXORExpression final : public BinaryExpression
{
public:
    
    /**
     * Creates a BitwiseXORExpression object with a left expression and right expression.
     * @param lhs The left-hand side expression.
     * @param rhs The right-hand side expression.
     */
    BitwiseXORExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the BitwiseXORExpression.
     */
    virtual ~BitwiseXORExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise XOR expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BitwiseXORExpression__ */
