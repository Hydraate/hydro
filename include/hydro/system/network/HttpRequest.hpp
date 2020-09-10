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

#ifndef __h3o_HttpRequest__
#define __h3o_HttpRequest__

#include "../HObject.hpp"
#include "Url.hpp"

namespace hydro
{

class HttpRequest : public HObject
{
    friend class HvmEnv;
    template <typename X>
    friend class NativeClassAllocator;
    
private:
    hurl _url;
    
    HttpRequest(HvmEnv *env, HClass *httpRequestClass);
    void construct(hurl url);
    
public:
    virtual ~HttpRequest();
};

} // namespace hydro

#endif /* __h3o_HttpRequest__ */
