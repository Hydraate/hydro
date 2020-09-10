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

#ifndef __h3o_engine_Keyframe__
#define __h3o_engine_Keyframe__

#include "expression/TimePointLiteral.hpp"

#include "Snapshot.hpp"

namespace hydro::engine
{

/**
 * The Keyframe class represents a keyframe entity in a Performance document. Since keyframes are a type of snapshot the Keyframe class inherits Snapshot.
 */
class Keyframe : public Snapshot
{
public:
    /**
     * Creates a Keyframe object with some parent entity and an identity.
     * @param parent The parent entity.
     * @param time The keyframe's time point.
     * @param identity The keyframe identity.
     */
    Keyframe(Entity *parent, TimePointLiteral *time, SnapshotIdentity *identity);
    
    /**
     * Destroys the Keyframe object.
     */
    virtual ~Keyframe();
    
    /**
     * Accepts a visitor allowing the visitor to visit the keyframe entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     * Gets the time point is which the time exists.
     * @return Returns the TimePointLiteral instance that was passed as a constructur argument.
     */
    TimePointLiteral *getTime() const { return mTime; }
    
private:
    /**
     * The time point that the keyframe occurs at.
     */
    TimePointLiteral *mTime;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Keyframe__ */
