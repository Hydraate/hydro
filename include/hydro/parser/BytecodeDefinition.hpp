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

#ifndef __h3o_BytecodeDefinition__
#define __h3o_BytecodeDefinition__

#include <string>
#include <cstdlib>

namespace hydro
{

struct BytecodeDefinition
{
    /**
     * The assembly name for the opcode.
     */
	std::string name;
    
    /**
     * The unsigned 8-bit opcode.
     */
	uint8_t opcode;
};

} // namespace hydro

#endif /* __h3o_BytecodeDefinition__ */
