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

#ifndef __h3o_engine_NestedExpression__
#define __h3o_engine_NestedExpression__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The NestedExpression class represents a nested expression in a Performance document.
 */
class NestedExpression final : public Expression
{
public:
    /**
     *
     */
    NestedExpression(compiler::Token token, Expression *expression);

    /**
     *
     */
    virtual ~NestedExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the nested expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     *
     */
    Expression *getExpression() const { return mExpression; }

private:
    /**
     *
     */
    Expression *mExpression;
};

} // namespace hydro::engine

#endif /* __h3o_engine_NestedExpression__ */
