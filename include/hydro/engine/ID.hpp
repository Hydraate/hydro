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

#ifndef __h3o_engine_ID__
#define __h3o_engine_ID__

#include <regex>
#include <string>

namespace hydro::engine
{
/**
 * The ID class represents a unique ID that is used to differentiate between element descriptions that reference the same element instance versus anonymous elements that reference the only one instance.
 */
class ID final
{
public:
    /**
     * Creates a nil ID object.
     */
    ID();

    /**
     * Explicitly creates an ID object using a value.
     * @param value The value in which to give the ID. This value is evaluated. If invalid, an invalid_id object is thrown.
     */
    explicit ID(std::string value);

    /**
     * Creates a copy of an ID object using value semantics.
     * @param id The ID in which to copy.
     */
    ID(const ID &id);

    /**
     * Creates a copy of an ID object using move semantics.
     * @param id The ID in which to copy.
     */
    ID(ID &&id);

    /**
     * Destroys the ID object.
     */
    virtual ~ID();

    /**
     * The ID::invalid_id struct is thrown when an invalid ID value is passed as a constructor argument to create a new ID.
     */
    struct invalid_id
    {
    };

    /**
     * Specifies whether or not the entity ID has a value.
     * @return Returns true if the ID's value property is set. Otherwise returns false.
     */
    bool isNil() const { return mValue.empty(); }

    /**
     * Gets the value of this ID.
     * @return Returns a valid entity identifier without the at sign (@). May return an empty string if the ID is nil.
     */
    std::string getValue() const { return mValue; }

    /**
     * Evaluates the ID object as truthy.
     * @return Returns true if the ID object is not nil. Otherwise returns false.
     */
    operator bool() const { return mValue.empty(); }

    /**
     * Evaluates the ID object as not false.
     * @return Returns true if the ID object is nil. Otherwise returns false.
     */
    bool operator!() const { return !mValue.empty(); }

    /**
     * Sets the ID object equal to another using value sematics.
     * @param rhs The id to the right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    ID &operator=(const ID &rhs);

    /**
     * Sets the ID object equal to another using move sematics.
     * @param rhs The id to the right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    ID &operator=(ID &rhs);

    /**
     * Compares the ID object to another using equality.
     * @return Returns true if the ID objects are not equal. Otherwise return false.
     */
    bool operator==(const ID &rhs) const;

    /**
     * Compares the ID object to another using inequality.
     * @return Returns true if the ID objects are not equal. Otherwise return false.
     */
    bool operator!=(const ID &rhs) const;

private:
    /**
     * The regular expression used to validate the value of the ID when initialzing the ID object.
     */
    static const std::regex ValidID;
    
    /**
     * The value of the ID.
     */
    std::string mValue;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ID__ */
