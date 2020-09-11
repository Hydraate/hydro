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

#include "BufferCache.hpp"

namespace hydro::compiler
{
BufferCache::BufferCache() {}

BufferCache::~BufferCache() {}

void BufferCache::append(char ch)
{
    mContent += ch;
}

} // namespace hydro::compiler
