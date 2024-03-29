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

#ifndef __h3o_VM_Class__
#define __h3o_VM_Class__

#include <string>
#include <cstdlib>

#include "VM_Object.hpp"
#include "Chunk.hpp"
#include "VM_Member.hpp"

namespace hydro
{

struct VM_Class : public VM_Object
{
    Chunk *chunk;
	const VM_Class *base{nullptr};
	uint16_t nfields;
    uint16_t nstatic;
	uint16_t ninstance;
	VM_Object **fields;
	struct VM_Constructor *construct;
	virtual ~VM_Class() {}
};

} // namespace hydro

#endif /* __h3o_VM_Class__ */
