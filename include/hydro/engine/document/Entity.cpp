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

#include "Entity.hpp"

namespace hydro::engine
{
/**
 * Implements the constructor of the Entity class.
 */
Entity::Entity() : Node{}
{
    mIdentity = nullptr;
    mContext = new PDocumentContext{};
    mContext->mOwner = this;
    mParent = nullptr;
    mRoot = nullptr;
    mChildIndex = -1;
}

/**
 * Implements the constructor of the Entity class with initialization using an identity and a parent entity.
 */
Entity::Entity(Entity *parent, Identity *identity) : Node{}
{
    mIdentity = identity;
    mContext = new PDocumentContext{parent->mContext};
    mContext->mOwner = this;
    mParent = nullptr;
    mRoot = nullptr;
    mChildIndex = -1;
    if(parent)
        parent->appendChild(this);
}

Entity::~Entity()
{
}

void Entity::appendAttribute(Attribute *attr)
{
    mAttributes.push_back(attr);
}

void Entity::appendBinding(WhenBinding *binding)
{
    mBindings.push_back(binding);
}

void Entity::appendBinding(WhileBinding *binding)
{
    mBindings.push_back(binding);
}

void Entity::appendChild(Entity *child)
{
    if (!child || child == this || child->mParent)
        return; // cannot be a child of itself
    child->mParent = this;
    child->mChildIndex = (int32_t)mChildren.size();
    mChildren.push_back(child);
    computeRoot();
}

void Entity::computeRoot()
{
    if (!mParent)
    {
        // this is root
        mRoot = nullptr;
        return;
    }

    // the parent will be the root element if the parent does not have a root element (this will be set before children are instantiated)
    mRoot = mParent->mParent ? mParent->mRoot : mParent;
}

void Entity::computeRelationships()
{
    // clear and free memory
    for (auto binding : mRelationshipBindings)
        delete binding;
    mRelationshipBindings.clear();

    /*
    if(mParent && mIdentity)
    {
        // iterate relationships
        for(std::string rel : mIdentity->relationships)
        {
           // find closest relationship
            for(auto child : mParent->children())
            {
                
            }
        }
    }*/
}

} // namespace hydro::engine
