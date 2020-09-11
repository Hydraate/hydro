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

#include "Group.hpp"

namespace hydro::engine
{
Group::Group()
{
}

Group::Group(const Group &group)
{
}

Group::Group(Group &&group)
{
}

Group::~Group()
{
}

void Group::appendMember(Instance *member)
{
    for (auto m : mMembers)
        if (m == member)
            return; // already included

    mMembers.push_back(member);
}

} // namespace hydro::engine
