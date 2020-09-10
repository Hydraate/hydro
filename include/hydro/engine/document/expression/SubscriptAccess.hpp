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

#ifndef __h3o_engine_SubscriptAccess__
#define __h3o_engine_SubscriptAccess__

#include "BinaryExpression.hpp"

namespace hydro::engine
{
/**
 * The SubscriptAccess class represents an expression that is an access to an index within some object or value.
 */
class SubscriptAccess final : public BinaryExpression
{
public:
    /**
     * Creates an SubscriptAccess object.
     */
    SubscriptAccess(Expression *lhs, compiler::Token token, Expression *rhs);
    
    /**
     * Destroys the SubscriptAccess object.
     */
    virtual ~SubscriptAccess();
    
    /**
     * Accepts a visitor allowing the visitor to visit the subscript access expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_SubscriptAccess__ */
