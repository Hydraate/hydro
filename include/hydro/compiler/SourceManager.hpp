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

#ifndef __h3o_SourceManager__
#define __h3o_SourceManager__

#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "SourceBuffer.hpp"
#include "SourceID.hpp"

namespace hydro::compiler
{
/**
 * The SourceManager class allocates and manages source buffers.
 */
class SourceManager
{
public:
    /**
     * Creates a SourceManager object.
     */
    SourceManager();

    /**
     * Destroys the SourceManager object.
     */
    virtual ~SourceManager();

    /**
     * Specifies if a particular source is contained within this source manager.
     * @param source The source ID of the source in which to check.
     * @return Returns true if and only if the specified source is managed by this source manager. Otherwise returns false.
     */
    bool contains(SourceID source);

    /**
     * Initializes a source buffer that will read a files stream.
     * @param path The relative path to the file.
     * @return Returns a new SourceBuffer instance that can be used to read input from the source. Input from the source buffer will automatically be cached.
     */
    SourceBuffer *initFileBuffer(std::string path);

    /**
     * Initializes a source buffer that will read a string stream.
     * @param id This could be a relative path or any unique string that can be used to index the source buffer.
     * @param data The data to be populated into the string stream.
     * @return Returns a new SourceBuffer instance that can be used to read input from the source. Input from the source buffer will automatically be cached.
     */
    SourceBuffer *initMemoryBuffer(std::string id, std::string data);

    /**
     * Locates the cache for a given source ID and returns the contents of the cache.
     * @param source The source ID of the cache in which to load.
     * @return Returns the cached content of the given source ID. Returns an empty string if the source is empty or cannot be located. In proper use an empty string will always mean that the cache is empty or the source was empty. To check for these cases use the contains() and isCacheAvailable() methods.
     */
    std::string getCache(SourceID source) const;

    /**
     * Locates the cache for a gien source ID and returns the contents of the cache after first ensuring that the entire source has been loaded into memory until end of file is reached.
     * @param source The source ID of the source in which to load.
     * @return Returns the source content of the given source ID. Returns an empty string if the source is empty or cannot be located. In proper use an empty string will always mean that the cache is empty or the source was empty. To check for these cases use the contains() and isCacheAvailable() methods.
     */
    std::string getSourceContent(SourceID source) const;

    /**
     * This helper method reads a particular line from a source buffer.
     * @param source The source ID of the source to read.
     * @param lineNumber The line number of the source file to read.
     */
    std::string getLineFromSource(SourceID source, uint32_t lineNumber);

    /**
     * Locates the source ID of a particular path. Pathes in the source manager must be unique so they are used as a primary index to a source buffer.
     * @param path The path to the source. In the case of a source buffer intiailized from memory, this will be identical to value passed to the "id" argument of the initMemoryBuffer() method.
     * @return Returns the source ID that is associated to the given path. If the source ID is nil, the SourceID object's empty() method will return true.
     */
    SourceID find(std::string path);

protected:
    struct source_data
    {
        SourceID source;
        SourceBuffer *buffer;
        BufferCache *cache;
    };

    std::list<source_data *> mSources;
};

} // namespace hydro::compiler

#endif /* __h3o_SourceManager__ */
