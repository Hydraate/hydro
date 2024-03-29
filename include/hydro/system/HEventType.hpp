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

#ifndef __h3o_EventType__
#define __h3o_EventType__

#include "HObject.hpp"
#include "../vm/VM_Etype.hpp"

namespace hydro
{

class HEventType : public HObject
{
    HVM_INTERNAL_CLASS()
        
public:
        virtual ~HEventType();
        HEventContext *owner() const { return _owner; }
        virtual std::string toString() override { return "[etype " + _value + "]"; }

private:
    const VM_Etype *_vetype;
    class HEventContext *_owner;
    std::string _value;
    HEventType(HvmEnv *env, HClass *eventTypeClass, const VM_Etype *vetype, HEventContext *owner);
};

typedef object_ptr<HEventType> hetype;

} // namespace hydro

#endif /* __h3o_EventType__ */
