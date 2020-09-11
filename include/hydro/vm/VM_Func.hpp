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

#ifndef __h3o_VM_Func__
#define __h3o_VM_Func__

#include <list>
#include <cstdlib>

#include "Chunk.hpp"
#include "FuncArg.hpp"
#include "VM_Object.hpp"
#include "MemorySpace.hpp"
#include "ErrorHandler.hpp"
#include "VM_Event.hpp"

namespace hydro
{

struct VM_Func : public VM_Object
{
	Chunk *chunk{nullptr};
	std::string package{};
	int32_t nargs{0}; // arity
	uint32_t nlocals{0};
	FuncArg **args;
	VM_Object **locals;
	uint32_t startAddr{0};
	uint32_t endAddr{0};
	uint32_t upvalues{0}; // upvalue count
    const VM_Event *context{nullptr}; // if exists
	VM_Type *returnType;
    uint16_t nhandlers;
    ErrorHandler **errorHandlers{nullptr};
	bool variadic{false};
    bool nativeBound{false};
	virtual ~VM_Func() {}
};

} // namespace hydro

#endif /* __h3o_VM_Func__ */
