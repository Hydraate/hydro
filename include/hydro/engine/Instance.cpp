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

#include "Instance.hpp"

namespace hydro::engine
{
Instance::Instance() noexcept
{
    mParent = nullptr;
    mEngine = nullptr;
}

Instance::~Instance() noexcept
{
    for (auto attr : mAttributes)
        delete attr;
}

void Instance::appendChild(Instance *child) noexcept
{
    if (child == this)
        return;
    if (child->mParent)
        child->mParent->removeChild(child);
    child->mParent = this;
    mChildren.push_back(child);
}

void Instance::removeChild(Instance *child) noexcept
{
    if (child->mParent != this)
        return;
    mChildren.remove(this);
}

int32_t Instance::getChildIndex() const noexcept
{
    if (!mParent)
        return -1;
    int32_t index = 0;

    for (auto child : mParent->mChildren)
        if (child == this)
            return index;
        else
            index++;

    return index;
}

void Instance::setChildIndex(int32_t index) noexcept
{
    if (!mParent || index < 0 || index >= mParent->mChildren.size())
        return; // out of bounds

    // TODO append child at index
}

void Instance::setAttribute(const std::string &name, Any value) noexcept
{
    if (auto attr = lookupAttribute(name))
        // write
        attr->value = value;
    else
        // define
        mAttributes.push_back(new Space{name, value});
}

Any Instance::getAttribute(const std::string &name) const noexcept
{
    if (auto attr = lookupAttribute(name))
        return attr->value;
    return undefined;
}

bool Instance::hasAttribute(const std::string &name) const noexcept
{
    return lookupAttribute(name) != nullptr;
}

Space *
Instance::lookupAttribute(const std::string &name) const
{
    for (auto attr : mAttributes)
        if (attr->name == name)
            return attr;
    return nullptr;
}

} // namespace hydro::engine
