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

#include "SourceBuffer.hpp"

namespace hydro::compiler
{
SourceBuffer::SourceBuffer(SourceID sourceID, BufferCache *cache, std::istream &inputStream) : mID{sourceID}, mCache{cache}, mInputStream{inputStream} {}

SourceBuffer::~SourceBuffer() { delete &mInputStream; }

char SourceBuffer::nextChar()
{
    if (mInputStream.eof())
        return EOF;

    char ch;
    if ((ch = mInputStream.get()) != EOF)
        mCache->append(ch);
    return ch;
}

} // namespace hydro::compiler
