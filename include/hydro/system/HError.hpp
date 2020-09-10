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

#ifndef __h3o_HError__
#define __h3o_HError__

#include <string>

#include "HObject.hpp"

namespace hydro
{

class HError : public HObject
{
    HVM_INTERNAL_CLASS()

public:
    virtual ~HError();
    std::string message() { return _message; }
    int32_t code() { return _code; }
    std::string getStackTrace();
    

    private:
        std::string _message;
        int32_t _code;
        HError(HvmEnv *env, HClass *errorClass);
        void construct(std::string text, int32_t code);
        
};

typedef object_ptr<HError> herror;

} // namespace hydro

#endif /* __h3o_HError__ */
