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

#include "HElement.hpp"

namespace hydro
{

HElement::HElement(HvmEnv *env, HClass *ElementClass) : HObject{env, ElementClass} {}

HElement::~HElement() {}

void HElement::construct() {}

} // namespace hydro
