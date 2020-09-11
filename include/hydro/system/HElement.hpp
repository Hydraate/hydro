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

#ifndef __h3o_HElement__
#define __h3o_HElement__

#include "HObject.hpp"

namespace hydro
{

class HElement : public HObject
{
    HVM_CLASS()

protected:
    HElement(HvmEnv *env, HClass *ElementClass);

public:
    virtual ~HElement();
    
private:
    void construct();
};

typedef object_ptr<HElement> helement;

} // namespace hydro

#endif /* __h3o_HElement__ */
