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

#include "SourceID.hpp"

namespace hydro::compiler
{
/**
     *
     */
SourceID::SourceID() : mID{nullptr} {}

/**
 *
 */
SourceID::SourceID(uint32_t bufferID, std::string path) : mID{new src_id{bufferID, path}} {}

/**
     *
     */
SourceID::SourceID(const SourceID &source)
{
    mID = source.mID;
}

/**
     *
     */
SourceID::SourceID(SourceID &&source)
{
    mID = source.mID;
}

/**
     *
     */
SourceID::~SourceID() {}

/**
     *
     */
SourceID &SourceID::operator=(const SourceID &rhs)
{
    mID = rhs.mID;
    return (*this);
}

SourceID &SourceID::operator=(SourceID &&rhs)
{
    mID = rhs.mID;
    return (*this);
}

bool SourceID::operator==(const SourceID &rhs) const
{
    return mID == rhs.mID;
}

bool SourceID::operator!=(const SourceID &rhs) const
{
    return mID != rhs.mID;
}

} // namespace hydro::compiler
