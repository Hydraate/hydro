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

#include "SnapshotReference.hpp"

namespace hydro::engine
{

SnapshotReference::SnapshotReference(SnapshotDomain *domain) : SimpleReference{ domain }
{
}

SnapshotReference::~SnapshotReference()
{
}

} // namespace hydro::engine
