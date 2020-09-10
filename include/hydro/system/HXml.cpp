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

#include "HXml.hpp"

namespace hydro
{

    HXml::HXml(HvmEnv *env, HClass *xmlClass) : HObject{env, xmlClass} {}

    HXml::~HXml() {}

    void HXml::construct(hvalue arg0)
    {
    }

} // namespace hydro
