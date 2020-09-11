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

#include "ActionSelector.hpp"

namespace hydro::engine
{

ActionSelector::ActionSelector(EventClass *_class) : EntitySelector{ _class }
{
}

ActionSelector::~ActionSelector()
{
}

} // namespace hydro::engine
