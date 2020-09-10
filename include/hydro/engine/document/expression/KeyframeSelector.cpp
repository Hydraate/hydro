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

#include "KeyframeSelector.hpp"

namespace hydro::engine
{

KeyframeSelector::KeyframeSelector(TimePointLiteral *time, SnapshotDomain *domain) : EntitySelector{ domain }
{
    mTime = time;
}

KeyframeSelector::~KeyframeSelector()
{
}

} // namespace hydro::engine
