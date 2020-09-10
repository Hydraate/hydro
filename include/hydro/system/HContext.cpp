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

#include "HContext.hpp"

namespace hydro
{

HContext::HContext(HvmEnv *env, HClass *contextClass, const VM_Context *vcontext) : HObject{env, contextClass}, _vcontext{vcontext} {}

HContext::~HContext() {}

void HContext::setup()
{
    // abstract
}

} // namespace hydro
