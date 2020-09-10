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

#ifndef __h3o_engine_QueryIdentity__
#define __h3o_engine_QueryIdentity__

#include "Identity.hpp"
#include "QueryTarget.hpp"

namespace hydro::engine
{
/**
 * The QueryIdentity class stores information about the identity of a query entity in a performance document.
 */
class QueryIdentity final : public Identity
{
public:
    /**
     * Creates a QueryIdentity object with a query target.
     * @param target The query target.
     */
    QueryIdentity(QueryTarget *target);

    /**
     * Destroys the QueryIdentity object.
     */
    virtual ~QueryIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the query identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the query target. This is the same as the identity's subject.
     */
    QueryTarget *getTarget() const { return mTarget; }
    
private:
    /**
     * The query target.
     */
    QueryTarget *mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_QueryIdentity__ */
