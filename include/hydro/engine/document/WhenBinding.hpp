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

#ifndef __h3o_engine_WhenBinding__
#define __h3o_engine_WhenBinding__

#include "expression/Expression.hpp"

#include "Binding.hpp"

namespace hydro::engine
{
/**
 * The WhenBinding class represents a when binding. When bindings activate elements when a condition occurs such as when an event is fired.
 */
class WhenBinding final : public Binding
{
public:
    /**
     * Creates a WhenBinding object with a token and a condition expression.
     * @param token The token.
     * @param condition The condition expression.
     */
    WhenBinding(compiler::Token token, Expression *condition);
    
    /**
     * Destroys the WhenBinding object.
     */
    virtual ~WhenBinding();
    
    /**
     * Accepts a visitor allowing the visitor to visit the when binding.
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

#endif /* __h3o_engine_WhenBinding__ */
