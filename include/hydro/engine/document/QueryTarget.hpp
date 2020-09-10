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

#ifndef __h3o_engine_QueryTarget__
#define __h3o_engine_QueryTarget__

#include "expression/Selector.hpp"

#include "Target.hpp"

namespace hydro::engine
{
/**
 * The QueryTarget class binds a selector expression to a query identity as required by a query entity in a Performance document.
 */
class QueryTarget final : public Target
{
public:
    /**
     * Creates a QueryTarget object
     * @param selector The selector expression that represents the query target.
     */
    QueryTarget(Selector *selector);
    
    /**
     * Destroys the QueryTarget object.
     */
    virtual ~QueryTarget();
    
    /**
     * Accepts a visitor allowing the visitor to visit the query target.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the selector that represents the query target.
     * @return Returns the Selector instance supplied in the QueryTarget constructor.
     */
    Selector *getSelector() const { return mSelector; }
    
private:
    /**
     * The selector that represents the query target.
     */
    Selector *mSelector;
};

} // namespace hydro::engine

#endif /* __h3o_engine_QueryTarget__ */
