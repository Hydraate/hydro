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

#include "SourceManager.hpp"

namespace hydro::compiler
{
SourceManager::SourceManager() {}

SourceManager::~SourceManager()
{
    for (auto data : mSources)
    {
        delete data->buffer;
        delete data->cache;
        delete data;
    }
}

SourceBuffer *SourceManager::initFileBuffer(std::string path)
{
    std::filesystem::path filepath = path;
    filepath = std::filesystem::absolute(path); // to absolute path
    std::fstream *file = new std::fstream{};
    file->open(filepath);
    if (file->is_open())
    {
        SourceID source{(uint32_t)mSources.size(), filepath};
        BufferCache *cache = new BufferCache{};
        SourceBuffer *buffer = new SourceBuffer{source, cache, *file};
        source_data *data = new source_data{source, buffer, cache};
        mSources.push_back(data);
        return data->buffer;
    }
    else
        delete file;
    return nullptr;
}

SourceBuffer *SourceManager::initMemoryBuffer(std::string path, std::string input)
{
    std::istringstream *memory = new std::istringstream{input};
    SourceID source{(uint32_t)mSources.size(), path};
    BufferCache *cache = new BufferCache{};
    SourceBuffer *buffer = new SourceBuffer{source, cache, *memory};
    source_data *data = new source_data{source, buffer, cache};
    mSources.push_back(data);
    return data->buffer;
}

std::string SourceManager::getCache(SourceID source) const
{
    for (auto data : mSources)
        if (data->source == source)
            return data->cache->getContent(); // return cached content

    // fail
    return "";
}

std::string SourceManager::getSourceContent(SourceID source) const
{
    for (auto data : mSources)
    {
        if (data->source == source)
        {
            while (data->buffer->hasNext())
                data->buffer->nextChar();  // read input into cache
            return data->cache->getContent(); // return cached content
        }
    }

    // fail
    return "";
}

std::string SourceManager::getLineFromSource(SourceID source, uint32_t lineNumber)
{
    for (auto data : mSources)
    {
        if (data->source == source)
        {
            SourceBuffer *buffer = data->buffer;
            while (buffer->hasNext())
                buffer->nextChar();
            std::string cache = data->cache->getContent();
            std::string line;
            uint32_t n = 1; // active line number

            for (char ch : cache)
                if (ch == '\n')
                    n++;
                else if (n == lineNumber)
                    line += ch;

            return line;
        }
    }

    // fail
    return "";
}

SourceID SourceManager::find(std::string path)
{
    for (source_data *data : mSources)
        if (data->source.path() == path)
            return data->source;
    // fail
    return SourceID{};
}

} // namespace hydro::compiler
