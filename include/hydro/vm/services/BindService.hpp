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

#ifndef __h3o_BindService__
#define __h3o_BindService__

#include "RuntimeService.hpp"
#include "../Closure.hpp"
#include "../../system/HClass.hpp"
#include "../../system/HFunction.hpp"
#include "../../system/HAction.hpp"
#include "../../system/HEventContext.hpp"
#include "../../system/HConstructor.hpp"
#include "../../system/HMethod.hpp"
#include "../../system/HProperty.hpp"
#include "../../system/HGetter.hpp"
#include "../../system/HSetter.hpp"

namespace hydro
{

struct BindService : RuntimeService
{
private:
    Closure *createClosure(const VM_Object *data) const;

public:
    BindService(HvmEnv *env) : RuntimeService{env} {}
    virtual ~BindService() {}
    hvalue ifNotExists(Runtime *runtime, const VM_Class *vclass) const;
    hvalue ifNotExists(Runtime *runtime, const VM_Func *vfunc) const;
    hvalue ifNotExists(Runtime *runtime, const VM_Action *vact) const;
    hvalue ifNotExists(Runtime *runtime, const VM_Event *vevent) const;
};

} // namespace hydro

#endif /* __h3o_BindService__ */
