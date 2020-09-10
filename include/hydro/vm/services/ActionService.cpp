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

#include "ActionService.hpp"
#include "../HvmEnv.hpp"

namespace hydro
{

hevent ActionService::context() const
{
    
    // not an action
    return nullptr;
}

} // namespace hydro
