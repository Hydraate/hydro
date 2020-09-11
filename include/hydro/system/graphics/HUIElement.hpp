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

#ifndef __h3o_HUIElement__
#define __h3o_HUIElement__

#include "../HObject.hpp"
#include "../../vm/detect.hpp"

#if defined(__HVM_IOS__)
#include "ios/AppleiOS_UIAdapter.hpp"
#elif defined(__HVM_IOS_SIM__)
#include "ios/AppleiOS_UIAdapter.hpp"
#elif defined(__HVM_MACOS__)
//#include "mac/Mac_UIAdapter.hpp"
#elif defined(__HVM_WINDOWS__)
#include "windows/Windows_UIAdapter.hpp"
#elif defined(__HVM_LINUX__)
#include "linux/Linux_UIAdapter.hpp"
#elif defined(__HVM_ANDROID__)
#include "android/Android_UIAdapter.hpp"
#endif

namespace hydro
{

class HUIElement : public HObject
{
    HVM_CLASS()

public:
    virtual ~HUIElement() {}
    void draw();

private:
    HUIElement(HvmEnv *env, HClass *UIElementClass) : HObject{env, UIElementClass} {}
    void h3o_draw();
};

} // namespace hydro

#endif /* __h3o_HUIElement__ */
