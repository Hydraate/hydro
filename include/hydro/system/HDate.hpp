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

#ifndef __h3o_HDate__
#define __h3o_HDate__

#include "HObject.hpp"

namespace hydro
{

    class HDate final : public HObject
    {
    public:
        virtual ~HDate();

    private:
        HDate(HvmEnv *env, HClass *dateClass);
        void construct(hvalue value);

        HVM_CLASS()
    };

    typedef object_ptr<HDate> hdate;

} // namespace hydro

#endif /* __h3o_Date__ */
