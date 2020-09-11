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

#include "Keyframe.hpp"

namespace hydro::engine
{

Keyframe::Keyframe(Entity *parent, TimePointLiteral *time, SnapshotIdentity *identity) : Snapshot{ parent, identity }
{
    mTime = time;
}

Keyframe::~Keyframe()
{
    delete mTime;
}

} // namespace hydro::engine
