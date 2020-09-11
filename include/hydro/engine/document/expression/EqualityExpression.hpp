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

#ifndef __h3o_engine_EqualityExpression__
#define __h3o_engine_EqualityExpression__

#include "BinaryExpression.hpp"

namespace hydro::engine
{

/**
 * The EqualityExpression class represents an equality expression in a Performanece document.
 */
class EqualityExpression final : public BinaryExpression
{
public:
    /**
     * Creates an EqualityExpression object with a left expression and a right expression.
     * @param lhs The left expression.
     * @param rhs The right expression.
    */
    EqualityExpression(Expression *lhs, Expression *rhs);
    
    /**
     * Destroys the EqualityExpression object.
     */
    virtual ~EqualityExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the equality expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_EqualityExpression__ */
