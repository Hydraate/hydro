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

#ifndef __h3o_internal_Source__
#define __h3o_internal_Source__

#include <iostream>
#include <memory>

#include "SourceID.hpp"

namespace hydro::compiler
{
/**
     * The SourceID class stores information about a source buffer initialized by a source manager.The SourceID object decouples references to a source buffer from classes that depend on the source buffer (i.e., Lexer, Parser, etc.).
     */
class SourceID final
{
public:
    /**
     * Creates a nil SourceID object.
     */
    SourceID();

    /**
     * Creates and initializes SourceID object.
     */
    explicit SourceID(uint32_t bufferID, std::string path);

    /**
     * Creates a copy of a SourceID using value semantics.
     */
    SourceID(const SourceID &source);

    /**
     * Creates a copy of a SourceID using move semantics.
     */
    SourceID(SourceID &&source);

    /**
     * Destroys the SourceID object.
     */
    ~SourceID();

    /**
     * Gets the ID property that is used to index the associated source buffer.
     * @return Returns an unsigned integer representing the unique ID of the source buffer as assigned by the source manager.
     */
    uint32_t id() const { return mID ? mID->bufferID : 0; }

    /**
     * Gets the path that represents the remote or local location that the source exists. Memory buffers may have a nil path.
     * @return Returns the path that is set for the SourceID object. Returns an empty string if nil or the path to the source buffer is unknown. This will be the case with memory buffers that have not be supplied a path upon initialization of the memory buffer.
     */
    std::string path() const { return mID ? mID->path : ""; }

    /**
     * Specifies whether or not the SourceID object has been initialized with a value or is nil.
     * Returns true if the internal data exists for the SourceID object. Otherwise returns false.
     */
    bool empty() const { return mID == nullptr; }

    /**
     * Specifies whether or not the SourceID is not nil.
     * @return Returns true if the SourceID is not nil. Otherwise returns false. The SourceID will not be nil if the internal data has been set.
     */
    operator bool() const { return mID != nullptr; }

    /**
     * Specifies whether nor not the SourceID is nil.
     * @return Returns true if the SourceID is nil. Otherwise returns false. The SourceID will be nil if the internal data has not been set.
     */
    bool operator!() const { return mID == nullptr; }

    /**
     * Sets this SourceID object equal to another SourceID object using value semantics.
     * @return Returns a reference to itself.
     */
    SourceID &operator=(const SourceID &rhs);

    /**
     * Sets this SourceID object equal to another SourceID object using move semantics.
     * @return Returns a reference to itself.
     */
    SourceID &operator=(SourceID &&rhs);

    /**
     *
     * @return Returns true if each SourceID object both reference the same source buffer. Otherwise returns false. Identical properties does not guarantee equality so this method is necessary to distinguish between similar SourceID objects that are owned by separate source managers.
     */
    bool operator==(const SourceID &rhs) const;

    /**
     * @return Returns true if each SourceID object does not reference the same source buffer. Otherwise returns false. Unidentical properties does not guarantee inequality so this method is necessary to distinguish between similar SourceID objects that are owned by separate source managers.
     */
    bool operator!=(const SourceID &rhs) const;

private:
    /**
     * The SourceID::src_id struct stores data for the SourceID object. A single instance may have at least one or many SourceID instances that reference it but each SourceID only references one and only one SourceID::src_id instance via a std::shared_ptr.
     */
    struct src_id
    {
        uint32_t bufferID;
        std::string path;
    };

    /**
     * The data for the SourceID. The std::shared_ptr automatically manages memory for the SourceID.
     */
    std::shared_ptr<src_id> mID;

    friend class SourceManager;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_Source__ */
