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

#ifndef __h3o_SourceBuffer__
#define __h3o_SourceBuffer__

#include <cstdlib>
#include <iostream>

#include "BufferCache.hpp"
#include "SourceID.hpp"

struct Source;

namespace hydro::compiler
{
/**
 * The SourceBuffer class implements a source buffer that reads characters from an input stream.
 */
class SourceBuffer
{
public:
    /**
     * Creates a SourceBuffer object with a source ID, buffer cache and input stream.
     * @param sourceID The source ID.
     * @param cache The buffer cache.
     * @param inputStream The input stream.
     */
    SourceBuffer(SourceID sourceID, BufferCache *cache, std::istream &inputStream);

    /**
     * Destroys the SourceBuffer object.
     */
    virtual ~SourceBuffer();

    /**
     * Reads the next character in the source buffer.
     */
    char nextChar();

    /**
     *
     */
    virtual bool willRead() const { return true; }

    /**
     * Specifies whether or not the source buffer will produce a result when calling the nextChar() method.
     * @return Returns true if the input stream does not at the end of file. Otherwise returns false.
     */
    bool hasNext() const { return !mInputStream.eof(); }

    /**
     * Specifies whether or not the source buffer has reached the end of the input stream.
     * @return Returns true if the input stream is at end of file. Otherwise returns false.
     */
    bool isEof() const { return mInputStream.eof(); }

    /**
     * Gets the source ID assigned to the source buffer.
     */
    SourceID getSourceID() const { return mID; }

    /**
     * Gets the buffer cache that is populated by the source buffer.
     */
    const BufferCache *getCache() const { return mCache; }
    
    /**
     * Reports the content within the cache.
     */
    std::string cache() const { return mCache->getContent(); }

protected:
    /**
     * The source ID.
     */
    SourceID mID;

    /**
     * The buffer cache.
     */
    BufferCache *mCache;

    /**
     * The input stream.
     */
    std::istream &mInputStream;
};

} // namespace hydro::compiler

#endif /* __h3o_SourceBuffer__ */
