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

#ifndef __h3o_engine_BitwiseANDExpression__
#define __h3o_engine_BitwiseANDExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseANDExpression class represents a bitwise AND expression in a Performance document.
 */
class BitwiseANDExpression : public BinaryExpression
{
public:
    /**
     * Creates a BitwiseANDExpression object with a left expression and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    BitwiseANDExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the BitwiseANDExpression object.
     */
    virtual ~BitwiseANDExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise AND expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BitwiseANDExpression__ */
