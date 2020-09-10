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

#ifndef __h3o_engine_AttributeAccess__
#define __h3o_engine_AttributeAccess__

#include "BinaryExpression.hpp"

namespace hydro::engine
{
/**
 * The AttributeAccess class represents a accessor of an attribute within an entity.
 */
class MemberAccess : public BinaryExpression
{
public:
    /**
     * Creates an AttributeAccess object.
     */
    MemberAccess(Expression *lhs, compiler::Token token, Expression *rhs);

    virtual ~MemberAccess();
};

} // namespace hydro::engine

#endif /* __h3o_engine_AttributeAccess__ */
