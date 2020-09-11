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

#ifndef __h3o_engine_AdditionExpression__
#define __h3o_engine_AdditionExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The AdditionExpression class represents an addition expression in a Performance document.
 */
class AdditionExpression final : public BinaryExpression
{
public:
    
    /**
     * Creates an AdditionExpression object with a left expression and right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    AdditionExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys an AdditionExpression object.
     */
    virtual ~AdditionExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the addition expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_AdditionExpression__ */
