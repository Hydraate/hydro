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

#ifndef __h3o_engine_BitwiseORExpression__
#define __h3o_engine_BitwiseORExpression__


#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseORExpression class represents a bitwise OR expression in a Performance document.
 */
class BitwiseORExpression final : public BinaryExpression
{
public:
    /**
     * Creates a BitwiseORExpression object with a left expresssion and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    BitwiseORExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the BitwsiseORExpression object.
     */
    virtual ~BitwiseORExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise OR expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BitwiseORExpression__ */
