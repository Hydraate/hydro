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

#include "SourcePosition.hpp"

namespace hydro::compiler
{
SourcePosition::SourcePosition() : mPos{nullptr} {}

SourcePosition::SourcePosition(SourceID source, int32_t indexOnLine, int32_t indexInSource, uint32_t line, uint32_t length) : mPos{new src_pos{source, indexOnLine, indexInSource, line, length}}
{
}

SourcePosition::SourcePosition(const SourcePosition &pos) : mPos{pos.mPos} {}

SourcePosition::SourcePosition(SourcePosition &&pos) : mPos{pos.mPos} {}

SourcePosition::SourcePosition(std::nullptr_t) : mPos{nullptr} {}

SourcePosition::~SourcePosition() {}

SourcePosition &SourcePosition::operator=(const SourcePosition &rhs)
{
    mPos = rhs.mPos;
    return (*this);
}

SourcePosition &SourcePosition::operator=(SourcePosition &&rhs)
{
    mPos = rhs.mPos;
    return (*this);
}

bool SourcePosition::operator==(const SourcePosition &rhs) const
{
    return rhs.mPos == mPos;
}

bool SourcePosition::operator!=(const SourcePosition &rhs) const
{
    return rhs.mPos != mPos;
}

SourcePosition SourcePosition::operator+(const SourcePosition &rhs) const
{
    if (mPos->source == rhs.mPos->source)
    {
        if (mPos->indexInSource < rhs.mPos->indexInSource)
            return SourcePosition{mPos->source, mPos->indexOnLine, mPos->indexInSource, mPos->line, rhs.mPos->indexInSource + rhs.mPos->length};
        else
            return rhs + (*this); // reverse
    }

    // nil
    return SourcePosition{};
}

} // namespace hydro::compiler
