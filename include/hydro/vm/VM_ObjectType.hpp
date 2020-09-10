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

#ifndef __h3o_VM_ObjectType__
#define __h3o_VM_ObjectType__

#include "VM_Type.hpp"

namespace hydro
{
   
class VM_ObjectType : public VM_Type
{
public:
    void *nativeClass;
    virtual bool typeCheck(const hvalue &value) override
    {
        
        
        // fail
        return false;
    }
};
    
} // namespace hydro

#endif /* __h3o_VM_ObjectType__ */
