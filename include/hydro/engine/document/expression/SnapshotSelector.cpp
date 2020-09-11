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

#include "SnapshotSelector.hpp"

namespace hydro::engine
{

SnapshotSelector::SnapshotSelector(SnapshotDomain *domain) : EntitySelector{ domain }
{
}

SnapshotSelector::~SnapshotSelector()
{
}

} // namespace hydro::engine
