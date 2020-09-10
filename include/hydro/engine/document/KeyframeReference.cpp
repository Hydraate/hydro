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

#include "KeyframeReference.hpp"

namespace hydro::engine
{

KeyframeReference::KeyframeReference(TimePointLiteral *time, SnapshotDomain *domain) : SimpleReference{ domain }
{
    mTime = time;
}

KeyframeReference::~KeyframeReference()
{
    delete mTime;
}

} // namespace hydro::engine
