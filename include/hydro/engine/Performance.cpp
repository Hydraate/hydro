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

#include "Performance.hpp"

namespace hydro::engine
{
Performance::Performance(Engine *engine, Document *document)
{
    mEngine = engine;
    mDocument = document;
}

Performance::~Performance()
{
}

} // namespace hydro::engine
