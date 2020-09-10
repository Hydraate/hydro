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

#include "../SnapshotDomain.hpp"

#include "EntitySelector.hpp"
#include "TimePointLiteral.hpp"

#ifndef __h3o_engine_KeyframeSelector__
#define __h3o_engine_KeyframeSelector__

namespace hydro::engine
{

/**
 * The KeyframeSelector class represents a keyframe selector in a Performance document.
 */
class KeyframeSelector final : public EntitySelector
{
public:
    /**
     * Creates a KeyframeSelector object with a time point and snapshot domain.
     * @param time The keyframe time point.
     * @param domain The snapshot domain.
     */
    KeyframeSelector(TimePointLiteral *time, SnapshotDomain *domain);
    
    /**
     * Destroys the KeyframeSelector object.
     */
    virtual ~KeyframeSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the keyframe selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the time point of the referenced keyframe.
     */
    TimePointLiteral *getTime() const { return mTime; }
    
private:
    /**
     * The keyframe time point.
     */
    TimePointLiteral *mTime;
};

} // namespace hydro::engine

#endif /* __h3o_engine_KeyframeSelector__ */
