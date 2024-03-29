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

#ifndef __h3o_HProperty__
#define __h3o_HProperty__

#include "HObject.hpp"
#include "HConstructor.hpp"
#include "HGetter.hpp"
#include "HSetter.hpp"
#include "../vm/VM_Property.hpp"

namespace hydro
{

class HProperty : public HObject, public RuntimeContext
{
    HVM_INTERNAL_CLASS()

public:
	~HProperty();
	bool get(HvmContext *threadContext, VM *vm, hvalue instance, hvalue &value);
	bool set(HvmContext *threadContext, VM *vm, hvalue instance, const hvalue &value);
    virtual std::string ownerPackage() const override { return _ownerClass->ownerPackage(); }
	virtual uint16_t modifier() const override { return _vprop->modifier; }
	virtual std::string assemblyName() const override { return _vprop->name; }
	HGetter *getter() const { return _getter; }
	HSetter *setter() const { return _setter; }
	bool readOnly() const { return _getter && !_setter; }
	bool writeOnly() const { return !_getter && _setter; }
    virtual runtime_context_type type() const override { return hvm_runtime_property; }
    
private:
    const VM_Property *_vprop;
    HGetter *_getter;
    HSetter *_setter;
    property_glue *_glue;
    HProperty(HvmEnv *env, HClass *propertyClass, const VM_Property *vprop, HClass *ownerClass, property_glue *glue = nullptr);
    
};

typedef object_ptr<HProperty> hproperty;

} // namespace hydro

#endif /* __h3o_HProperty__ */
