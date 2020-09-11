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

#ifndef __h3o_engine_NullExpression__
#define __h3o_engine_NullExpression__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 * The NullExpression class represents a null expression in a Performance document.
 */
class NullExpression : public Expression
{
public:
    /**
     *
     */
    NullExpression(compiler::Token token);

    /**
     *
     */
    virtual ~NullExpression();
    
    /**
     * Accepts a visitor allowing the visitor to visit the null expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_NullExpression__ */
