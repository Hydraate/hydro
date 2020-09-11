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

#ifndef __h3o_HXml__
#define __h3o_HXml__

#include "HObject.hpp"

namespace hydro
{

    class HXml : public HObject
    {
        HVM_INTERNAL_CLASS()
    
    public:
        virtual ~HXml();
        
    private:
        HXml(HvmEnv *env, HClass *xmlClass);
        void construct(hvalue arg0);

    };

    typedef object_ptr<HXml> hxml;

} // namespace hydro

#endif /* __h3o_HXml__ */
