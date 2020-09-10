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

#ifndef __h3o_VM_State__
#define __h3o_VM_State__

#include "VM_Object.hpp"
#include "Chunk.hpp"

class VM_State : public VM_Object
{
    VM_StateDomain *domain;
    Chunk *chunk;
    uint64_t startAddr, endAddr;
};

#endif /* __h3o_VM_State__ */
