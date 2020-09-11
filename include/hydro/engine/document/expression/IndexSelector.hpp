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

#ifndef __h3o_engine_IndexSelector__
#define __h3o_engine_IndexSelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The IndexSelector class represents a selector t
 */
class IndexSelector final : public Selector
{
public:
    /**
     * Creates an IndexSelector with some subject selector and an index expression.
     */
    IndexSelector(Selector *subject, Expression *index);
    
    /**
     * Destroys the IndexSelector object.
     */
    virtual ~IndexSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the bitwise AND expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the subject selector.
     * @return Returns the subject selector in which to index.
     */
    Selector *getSubject() const { return mSubject; }
    
    /**
     * Gets the index expression.
     * @return Returns the expression that will be used to pull the index from the subject.
     */
    Expression *getIndex() const { return mIndex; }
    
private:
    /**
     * The subject selector.
     */
    Selector *mSubject;
    
    /**
     * The index expression.
     */
    Expression *mIndex;
};

} // namespace hydro::engine

#endif /* __h3o_engine_IndexSelector__ */
