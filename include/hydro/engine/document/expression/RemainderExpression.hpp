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

#ifndef __h3o_engine_RemainderExpression__
#define __h3o_engine_RemainderExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The RemainderExpression represents a remainder (modulo) expression in a Performance document.
 */
class RemainderExpression final : public BinaryExpression
{
public:
    /**
     * Creates a RemainderExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
     */
    RemainderExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the RemainderExpression object.
     */
    virtual ~RemainderExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the remainder expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_RemainderExpression__ */
