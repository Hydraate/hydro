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

#ifndef __h3o_Closure__
#define __h3o_Closure__

#include "VM_Func.hpp"
#include "Upvalue.hpp"
#include "MemorySpace.hpp"

namespace hydro
{

struct Closure
{
	const Closure *parent;
	const VM_Object *data;
	//Upvalue **upvalues;
    MemorySpace *locals;
	uint8_t nups; // number of upvalues
};

} // namespace hydro

#endif /* __h3o_Closure__ */
