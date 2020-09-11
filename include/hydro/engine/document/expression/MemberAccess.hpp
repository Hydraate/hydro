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

#ifndef __h3o_engine_MemberAccess__
#define __h3o_engine_MemberAccess__

#include "BinaryExpression.hpp"

namespace hydro::engine
{
/**
 * The MemberAccess class represents member access of a some value.
 */
class MemberAccess : public BinaryExpression
{
public:
    /**
     * Creates an AttributeAccess object.
     */
    MemberAccess(Expression *lhs, Expression *rhs);

    /**
     * Destroys the MemberAccess object.
     */
    virtual ~MemberAccess();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise AND expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_MemberAccess__ */
