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

#ifndef __h3o_tposition_t__
#define __h3o_tposition_t__

#include <memory>

#include "SourceID.hpp"

namespace hydro::compiler
{
/**
     * The SourcePosition class stores information about a position in a source buffer.
     */
class SourcePosition
{
public:
    /**
     * Creates a SourcePosition object.
     */
    SourcePosition();

    /**
     * Creates a SourcePosition object with token information.
     * @param source The SourceID that links the source position to a source buffer.
     * @param indexOnLine The zero-based index of the position on the line that the position starts at.
     * @param indexInSource The zero-based index of the position of the index in the source buffer.
     * @param length The length of the position.
     */
    SourcePosition(SourceID source, int32_t indexOnLine, int32_t indexInSource, uint32_t line, uint32_t length);

    /**
     * Creates a copy of a SourcePosition object using value semantics.
     */
    SourcePosition(const SourcePosition &pos);

    /**
     * Creates a copy of a SourcePosition object using move semantics.
     */
    SourcePosition(SourcePosition &&pos);

    /**
     * Creates a SourcePosition object from null.
     */
    SourcePosition(std::nullptr_t);

    /**
     * Destroys a SourcePosition object.
     */
    ~SourcePosition();

    /**
     * Gets the source ID property.
     * @return Gets the SourceID object that references the source buffer in which the source position addresses.
     */
    SourceID source() const { return mPos ? mPos->source : SourceID{}; }

    /**
     *
     * @return
     */
    int32_t indexOnLine() const { return mPos ? mPos->indexOnLine : -1; }

    /**
     *
     * @return
     */
    int32_t indexInSource() const { return mPos ? mPos->indexInSource : -1; }

    /**
     *
     * @return
     */
    uint32_t line() const { return mPos ? mPos->line : 0; }

    /**
     *
     * @return
     */
    uint32_t length() const { return mPos ? mPos->length : 0; }

    /**
     *
     * @return
     */
    bool empty() const { return mPos == nullptr; }

    /**
     *
     * @return
     */
    operator bool() const { return mPos != nullptr; }

    /**
     *
     * @return
     */
    bool operator!() const { return mPos == nullptr; }

    /**
     *
     * @param rhs ...
     * @return ...
     */
    SourcePosition &operator=(const SourcePosition &rhs);

    /**
     *
     * @param rhs ...
     * @return ...
     */
    SourcePosition &operator=(SourcePosition &&rhs);

    /**
     *
     * @param rhs ...
     * @return ...
     */
    bool operator==(const SourcePosition &rhs) const;

    /**
     *
     * @param rhs ...
     * @return Returns true if the position to the left of the operator is not equal to this source position. Otherwise returns false.
     */
    bool operator!=(const SourcePosition &rhs) const;

    /**
     *
     * @param rhs ...
     * @return Returns the new source position.
     */
    SourcePosition operator+(const SourcePosition &rhs) const;

private:
    /**
     *
     */
    struct src_pos
    {
        /**
         *
         */
        SourceID source;

        /**
         *
         */
        int32_t indexOnLine;

        /**
         *
         */
        int32_t indexInSource;

        /**
         *
         */
        uint32_t line;

        /**
         *
         */
        uint32_t length;
    };

    /**
     *
     */
    std::shared_ptr<src_pos> mPos;
};

} // namespace hydro::compiler

#endif /* __h3o_tposition_t__ */
