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

#ifndef __h3o_engine_KeyframeReference__
#define __h3o_engine_KeyframeReference__

#include "expression/TimePointLiteral.hpp"

#include "SimpleReference.hpp"
#include "SnapshotDomain.hpp"

namespace hydro::engine
{

class KeyframeReference final : public SimpleReference
{
public:
    /**
     * Creates a KeyframeReference Obejct with a time point and a name.
     * @param time The time point of the referenced keyframe.
     * @param domain The snapshot context domain.
     */
    KeyframeReference(TimePointLiteral *time, SnapshotDomain *domain);

    /**
     * Destroys the KeyframeReference object.
     */
    virtual ~KeyframeReference();
    
    /**
     * Gets the time point of the referenced keyframe entity.
     */
    TimePointLiteral *getTime() const { return mTime; }
    
private:
    /**
     * The time point of the referenced keyframe entity.
     */
    TimePointLiteral *mTime;
};

} // namespace hydro::engine

#endif /* __h3o_engine_KeyframeReference__ */
