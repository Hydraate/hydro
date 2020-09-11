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

#ifndef __h3o_engine_PositiveExpression__
#define __h3o_engine_PositiveExpression__

#include "UnaryExpression.hpp"

namespace hydro::engine
{

/**
 * The PositiveExpression class represents a positive expression in a Performance document.
 */
class PositiveExpression final : public UnaryExpression
{
public:
    /**
     * Creates a PositiveExpression object with a subject expression.
     * @param expression The subject expression of the positive operation.
     */
    PositiveExpression(Expression *expression);
    
    /**
     * Destroys the PositiveExpression object.
     */
    virtual ~PositiveExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the positive expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_PositiveExpression__ */
