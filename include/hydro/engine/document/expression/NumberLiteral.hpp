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

#ifndef __h3o_engine_NumberLiteral__
#define __h3o_engine_NumberLiteral__

#include "Expression.hpp"

namespace hydro::engine
{
/**
 *
 */
class NumberLiteral final : public Expression
{
public:
    /**
     *
     */
    NumberLiteral(compiler::Token token);

    /**
     *
     */
    virtual ~NumberLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the number literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_NumberLiteral__ */
