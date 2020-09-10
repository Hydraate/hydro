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

#ifndef __h3o_engine_UndefinedExpression__
#define __h3o_engine_UndefinedExpression__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The UndefinedExpression class represents an undefined literal in a Performance document.
 */
class UndefinedExpression final : public Expression
{
public:
    /**
     * Creates an UndefinedExpression object with a token.
     * @param token The identifier token that represents the undefined literal.
     */
    UndefinedExpression(compiler::Token token);

    /**
     * Destroys the UndefinedExpression object.
     */
    virtual ~UndefinedExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the undefined expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_UndefinedExpression__ */
