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

#ifndef __h3o_engine_Group__
#define __h3o_engine_Group__

#include <list>

#include "Instance.hpp"

namespace hydro::engine
{
/**
 * The Group class stores instances that be affected simeotaneously by performing operations upon the group.
 */
class Group final
{
public:
    /**
     * Creates a Group object.
     */
    Group();
    
    /**
     * Creates a copy of a Group using value copy semantics.
     * @param group The group in which to copy
     */
    Group(const Group &group);
    
    /**
     * Creates a copy of a Group object using move semantics.
     * @param group The group in which to copy.
     */
    Group(Group &&group);

    /**
     * Destroys the Group object.
     */
    ~Group();

    /**
     * Adds an instance to the group if and instance is not already a member.
     * @param member The instance in which to add as a member of the group.
     */
    void appendMember(Instance *member);
    
    /**
     * Gets the list of members that belong to the group.
     * @return Returns a constant reference to the list of group members.
     */
    const std::list<Instance *> &members() const { return mMembers; }

private:
    /**
     * A list of members contained with the group.
     */
    std::list<Instance *> mMembers;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Group__ */
