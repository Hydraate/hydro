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

#ifndef __h3o_engine_WhileBinding__
#define __h3o_engine_WhileBinding__

#include "expression/Expression.hpp"

#include "Binding.hpp"

namespace hydro::engine
{
/**
 * The WhileBinding class represents a while binding. While bindings activate elements while a condition is met.
 */
class WhileBinding final : public Binding
{
public:
    /**
     * Creates a WhileBinding object with a token and a condition expression.
     * @param token The token.
     * @param condition The condition expression.
     */
    WhileBinding(compiler::Token token, Expression *condition);
    
    /**
     * Destroys the WhileBinding object.
     */
    virtual ~WhileBinding();
    
    /**
     * Accepts a visitor allowing the visitor to visit the while binding.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the condition expression.
     */
    Expression *getCondition() const { return mCondition; }
    
private:
    /**
     * The condition expression.
     */
    Expression *mCondition;
};

} // namespace hydro::engine

#endif /* __h3o_engine_WhileBinding__ */
