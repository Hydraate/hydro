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

#ifndef __h3o_VM_StateContext__
#define __h3o_VM_StateContext__

#include "VM_State.hpp"

namespace hydro
{

struct VM_StateContext : public VM_Object
{
    Chunk *chunk;
    uint16_t nstates;
    VM_State **states;
};

} // namespace hydro

#endif /* __h3o_VM_StateContext__ */
