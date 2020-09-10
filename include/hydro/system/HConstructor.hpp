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

#ifndef __h3o_HContructor__
#define __h3o_HContructor__

#include "HObject.hpp"
#include "HClass.hpp"
#include "../vm/VM_Constructor.hpp"
#include "../vm/glue.hpp"
#include "../vm/HvmCallable.hpp"

namespace hydro
{

/**
 * 
 * 
 */
class HConstructor final : public HObject, public RuntimeContext, public HvmCallable
{
    HVM_INTERNAL_CLASS()

    public:
        HConstructor(HvmEnv *env, HClass *constructorClass, const VM_Constructor *vconstruct, HClass *ownerClass, function_glue *glue);
        hvalue call(HvmEnv *env, VM *vm, HvmContext *threadContext, RuntimeContext *callingContext, std::list<hvalue> &args, hvalue thisObject);
        virtual ~HConstructor();
        virtual hvalue call(HvmContext *threadContext, VM *vm, std::list<hvalue> &args, hvalue thisObject = nullptr) override;
        virtual hvalue call(HvmContext *threadContext, VM *vm, std::map<std::string, hvalue> &args, hvalue thisObject = nullptr) override;
        virtual uint16_t modifier() const override { return _vconstruct->modifier; }
        virtual std::string assemblyName() const override { return ""; }
        virtual runtime_context_type type() const override { return hvm_runtime_constructor; }
private:
	const VM_Constructor *_vconstruct;
    function_glue *_glue;
    
    friend class Call;
};

typedef object_ptr<HConstructor> hconstructor;

} // namespace hydro

#endif /* __h3o_HContructor__ */
