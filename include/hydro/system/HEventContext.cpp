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

#include "HEventContext.hpp"
#include "HObjectContext.hpp"
#include "../vm/HvmEnv.hpp"

namespace hydro
{

    HEventContext::HEventContext(HvmEnv *env, HClass *eventContextClass, const VM_Event *vevent, HEventContext *superEvent) : HObject{env, eventContextClass}, _vevent{vevent}, _superEvent{superEvent}
    {
        mContext->ensureCapacity(mContext->_size + _vevent->netypes);
        uint16_t j = mContext->_size;

        for (uint16_t i = 0; i < _vevent->netypes; i++)
        {
            mContext->fields[j] = new HObjectContext::property_space{};
            mContext->fields[j]->key = _vevent->etypes[i]->name;
            mContext->fields[j]->dynamic = false;
            mContext->fields[j]->data = _vevent->etypes[i];
            mContext->fields[j++]->value = mEnv->createEtype(_vevent->etypes[i], this);
        }

        mContext->_size = j;
    }

    HEventContext::~HEventContext() {}

} // namespace hydro
