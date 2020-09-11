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

#ifndef __h3o_HObject__
#define __h3o_HObject__

#include <list>
#include <string>

#include "../utility/classhelper.hpp"
#include "../memory/object_ptr.hpp"

#define HVM_CLASS()\
    friend class HvmEnv;\
    template <typename X>\
    friend class NativeClassAllocator;\

#define HVM_INTERNAL_CLASS()\
    HVM_CLASS()\
    friend class VM;

namespace hydro
{

class HvmEnv;
class VM;
class hvalue;
class HObjectContext;
struct VM_Class;
class HClass;
class HvmContext;
class hydro_property;
class HGetter;
class HSetter;
struct RuntimeService;

class HObject
{
    HVM_INTERNAL_CLASS()

public:
    static void hold(HObject *obj)
    {
        if (obj)
            obj->addRef();
    }

    static void release(HObject *obj)
    {
        if (obj)
            obj->removeRef();
    }

    HObject(HvmEnv *env, class HClass *clss);
    HObject(HvmEnv *env, HClass *clss, HClass *self);
    virtual ~HObject();
    std::string castString() { return "casting object to string"; }
    HvmEnv *env() const { return mEnv; }
    virtual std::string toString();
    HObjectContext *context() const { return mContext; }
    virtual bool equals(hvalue value);

protected:
	HvmEnv *mEnv;
    HClass *mClass;
    HObjectContext *mContext; // context for storing and accessing data within the HVE
    
	virtual bool tryGetProperty(HvmEnv *env, VM *vm, HvmContext *threadContext, std::string name, hvalue &value);
	virtual bool trySetProperty(HvmEnv *env, VM *vm, HvmContext *threadContext, std::string name, const hvalue &value);
	virtual bool tryGetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, hvalue &value);
	virtual bool trySetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, const hvalue &value);
	virtual bool tryCallProperty(HvmEnv *env, VM *vm, HvmContext *threadContext, std::string name, std::list<hvalue> args, hvalue &result);
	virtual bool tryCallIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, std::list<hvalue> args, hvalue &result);
	virtual bool tryDeleteProperty(HvmEnv *env, VM *vm, HvmContext *threadContext, std::string name);
	virtual bool tryDeleteIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index);
    
    void construct();
    
    void setup();
    void setup(HClass *rstatic);
    
private:
    uint64_t _nrefs;     // reference count
    
    void addRef();
    void removeRef();

    friend hvalue;
    template <typename T>
    friend class object_ptr;
    friend HObjectContext;
    friend hydro_property;
    friend HGetter;
    friend HSetter;
    friend HClass;
    friend RuntimeService;
};

typedef object_ptr<HObject> hobject;

void hydro_system_Object_constructor(object_ptr<HObject> instance);

} // namespace hydro

#endif /* __h3o_HObject__ */
