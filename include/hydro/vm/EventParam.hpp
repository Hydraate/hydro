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

#ifndef __h3o_EventParam__
#define __h3o_EventParam__

#include "VM_Object.hpp"
#include "VM_Type.hpp"
#include "InstrGroup.hpp"

namespace hydro
{

struct EventParam : public VM_Object
{
    VM_Type *type;
    InstrGroup *defaultValue;
};

} // namespace hydro

#endif /* __h3o_EventParam__ */
