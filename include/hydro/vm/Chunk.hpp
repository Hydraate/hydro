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

#ifndef __h3o_Chunk__
#define __h3o_Chunk__

#include "hvalue.hpp"
#include "bytearray.hpp"

namespace hydro
{

/**
 * The Chunk class stores information about a Hydro program include the bytecode sequence of the program, constants, names, and other information.
 */
struct Chunk
{
	uint32_t size;
    bytearray bytes;
	std::string *names{nullptr};
	hvalue *constPool{nullptr};
	//class MemorySpace *globals{nullptr};
	class Runtime *runtime{nullptr};
	class VM_Func *main{nullptr};
#ifdef HVM_DEBUG
	uint32_t *lines{nullptr};
#endif /* HVM_DEBUG */
};

} // namespace hydro

#endif /* __h3o_Chunk__ */
