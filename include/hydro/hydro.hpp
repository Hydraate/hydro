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

#ifndef __HVM_CORE__
#define __HVM_CORE__

#include "vm/HvmEnv.hpp"
#include "hydro_native.hpp"

#ifndef HVM_VERSION
#   define HVM_VERSION "0.1.0"
#else
//#   error "HVM_VERSION macro is already defined."
#endif

namespace hydro
{

HvmEnv *hvm_setup()
{
    if(!HvmEnv::_instance)
    {
        HvmInitOptions *options = new HvmInitOptions{}; // will be removed once new parser is implemented
        options->sdkPath = options->srcPath = options->libPath = "./";
        HvmEnv *instance = new HvmEnv{};
        instance->setup(options);
        return instance;
    }
    return HvmEnv::_instance;
}

HvmEnv *hvm_get_instance() { return HvmEnv::_instance; }

}

#endif /* HVM_CORE */
