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

#ifndef __h3omBufferCache__
#define __h3omBufferCache__

#include <string>

namespace hydro::compiler
{
/**
 * The BufferCache class stores a cache of content loaded by a source buffer. The source buffer is resposible for populating the cache.
 */
class BufferCache
{
public:
    /**
     * Creates a BufferCache object.
     */
    BufferCache();

    /**
     * Destroys the BufferCache object.
     */
    virtual ~BufferCache();

    /**
     * Gets the cache's content.
     */
    std::string getContent() const { return mContent; }
    
    /**
     * Reports the size of the cache.
     */
    std::size_t size() const { return mContent.length(); }

private:
    /**
     * The content of the cache.
     */
    std::string mContent;

    /**
     * The SourceBuffer object that owns the SourceCache instance calls this method to formally populate the cache.
     */
    void append(char ch);

    friend class SourceBuffer;
};

} // namespace hydro::compiler

#endif /* __h3omBufferCache__ */
