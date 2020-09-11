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

#include "Mirror.hpp"

namespace hydro::engine
{
Mirror::Mirror(Name *name, Value *value) : Attribute{ name, value }
{
}

Mirror::~Mirror()
{
}

} // namespace hydro::engine
