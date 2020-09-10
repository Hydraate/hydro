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

#ifndef __h3o_engine_NegativeExpression__
#define __h3o_engine_NegativeExpression__

#include "UnaryExpression.hpp"

namespace hydro::engine
{

/**
 * The NegationExpression class represents a negation expression in a Performance document.
 */
class NegationExpression final : public UnaryExpression
{
public:
    /**
     * Creates a NegationExpression object with a subject expression.
     * @param expression The subject expression of the negation operation.
     */
    NegationExpression(Expression *expression);
    
    /**
     * Destroys the NegationExpression object.
     */
    virtual ~NegationExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the negation expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_NegativeExpression__ */
