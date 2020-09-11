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

#ifndef __h3o_VM_NilType__
#define __h3o_VM_NilType__

#include "VM_Type.hpp"

namespace hydro
{

class VM_NilType : public VM_Type
{
public:
	virtual bool typeCheck(const hvalue &value) override { return true; }
};

} // namespace hydro

#endif /* __h3o_VM_NilType__ */
