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

#ifndef __h3o_engine_BitwiseNOTExpression__
#define __h3o_engine_BitwiseNOTExpression__

#include "UnaryExpression.hpp"

namespace hydro::engine
{

/**
 * The BitwiseNOTExpression class represents a bitwise NOT expression in a Performance document.
 */
class BitwiseNOTExpression final : public UnaryExpression
{
public:
    /**
     * Creates a BitwiseNOTExpression object with a subject expression.
     * @param expression The expression that is the subject of the bitwise NOT operation.
     */
    BitwiseNOTExpression(Expression *expression);
    
    /**
     * Destroys the BitwsiseNOTExpression object.
     */
    virtual ~BitwiseNOTExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise NOT expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_BitwiseNOTExpression__ */
