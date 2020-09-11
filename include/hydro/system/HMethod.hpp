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

#ifndef __h3o_RuntimeMethod__
#define __h3o_RuntimeMethod__

#include "HClass.hpp"
#include "../vm/VM_Method.hpp"
#include "../vm/glue.hpp"

namespace hydro
{

    class HvmEnv;

    typedef object_ptr<class HMethod> hmethod;

    class HMethod : public HObject, public RuntimeContext
    {
        HVM_INTERNAL_CLASS()

    public:
        virtual ~HMethod();
        hvalue call(HvmEnv *env, VM *vm, HvmContext *threadContext, std::list<hvalue> &args, hvalue thisObject);
        virtual std::string ownerPackage() const override { return _ownerClass->ownerPackage(); }
        virtual uint16_t modifier() const override { return _vmethod->modifier; }
        virtual std::string assemblyName() const override { return _vmethod->name; }
        virtual runtime_context_type type() const override { return hvm_runtime_method; }

    private:
        const VM_Method *_vmethod;
        function_glue *_glue;

        HMethod(HvmEnv *env, HClass *methodClass, const VM_Method *vmethod, HClass *ownerClass, function_glue *glue);
    };

    typedef object_ptr<HMethod> hmethod;

} // namespace hydro

#endif /* __h3o_RuntimeMethod__ */
