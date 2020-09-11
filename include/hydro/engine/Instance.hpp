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

#ifndef __h3o_engine_Instance__
#define __h3o_engine_Instance__

#include <list>

#include "Entity.hpp"
#include "Space.hpp"

namespace hydro::engine
{
class Engine;

/**
 * The abstract Instance class is the base class for entity instance classes.
 */
class Instance
{
protected:
    /**
     * Creates an Instance object that is a root instance.
     */
    Instance() noexcept;

public:
    /**
     * Frees attributes from memory.
     */
    virtual ~Instance() noexcept;

    /**
     * Appends another instance as a child of this instance.
     * @param child The instance in which to append as a child.
     */
    void appendChild(Instance *child) noexcept;

    /**
     * Removes an instance that is a child of this instance.
     * @param child The child instance in which to remove.
     */
    void removeChild(Instance *child) noexcept;

    /**
     * Computes the child index relative to the parent of this node.
     * @return Returns the zero based index of this node in the child list of its parent. Returns -1 if this node does not contain a parent.
     */
    int32_t getChildIndex() const noexcept;

    /**
     * Repositions the node in its parent such that the child will rest at a given index.
     * @param index The new index in which to set. If the index is out of bounds this method does nothing.
     */
    void setChildIndex(int32_t index) noexcept;

    /**
     * Sets an attribute value. Defines the attribute if it does not exist.
     */
    void setAttribute(const std::string &name, Any value) noexcept;

    /**
     * Gets an attribute value.
     * @return Returns the value if it exists. Otherwise returns undefined. To get a value exists and determine if the value also exists, use the tryGetAttribute() method.
     * @see tryGetAttribute
     */
    Any getAttribute(const std::string &name) const noexcept;

    /**
     * Attempts to get an attribute value of a particular name.
     * @param name The name of the attribute in which to set.
     * @param value The value in which to read. The value is passed by reference and is set in response to such.
     * @return Returns true if the attribute exists and thus the value was retrieved. Otherwise returns false and the value argument will not be supplied a reference.
     */
    bool tryGetAttribute(const std::string &name, Any &value) noexcept;

    /**
     * Specifies whether or not an attribute of a particular name exists within the Instance.
     */
    bool hasAttribute(const std::string &name) const noexcept;

    /**
     * Provides a list of attributes contained within the Instance.
     * @return Returns a constant reference to the list of atributes contained within the Instance. This property is set by the Performance object which is an instance factory.
     */
    const std::list<Space *> &attributes() const noexcept { return mAttributes; }

    /**
     * Gets engine that owns the instance.
     * @return Returns the Engine instance that owns this Instance object.
     */
    Engine *getEngine() const noexcept { return mEngine; }

protected:
    // The Engine instance that owns this Instance.
    Engine *mEngine;

    /**
     * A list of attributes contained within this instance.
     */
    std::list<Space *> mAttributes;

    /**
     * Locates an attribute. Returns the attribute upon success or null on failure.
     */
    Space *lookupAttribute(const std::string &name) const;

private:
    /**
     * The parent to this instance.
     */
    Instance *mParent;

    /**
     *
     */
    std::list<Instance *> mChildren;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Instance__ */
