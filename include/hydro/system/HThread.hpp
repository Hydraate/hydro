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

#ifndef __h3o_HThread__
#define __h3o_HThread__

#include "HObject.hpp"

namespace hydro
{

    class HThread : public HObject
    {
        HVM_INTERNAL_CLASS()
    
    public:
        virtual ~HThread();
        
    protected:
        HThread(HvmEnv *env, HClass *threadClass);

        void construct();
    };

} // namespace hydro

#endif /* __h3o_HThread__ */
