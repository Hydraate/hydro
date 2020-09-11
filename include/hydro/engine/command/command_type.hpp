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

#ifndef __h3o_engine_command_type__
#define __h3o_engine_command_type__

#include <cstdlib>

namespace hydro::engine
{
enum command_type : uint16_t
{
    // element allocation
    alloc_cmd,

    // string
    str_cmd,

    // number
    num_cmd,

    // list
    list_cmd,

    // load identity
    loadid_cmd,

    // store identity
    storeid_cmd,

    // exponential
    exp_cmd,

    // multiplication
    mul_cmd,

    // division
    div_cmd,

    // modulo instruction
    mod_cmd,

    // addition
    add_cmd,

    // substraction
    sub_cmd,

    // logical equality
    eq_cmd,

    // logical inequality
    ieq_cmd,

    // pointer (points to the next command in the chain)
    ptr_cmd,

    // jump
    jmp_cmd,

    // branch if true
    brt_cmd,

    // branch if false
    brf_cmd,

    // invocation
    inv_cmd,

    // fire event
    fire_cmd,
};

} // namespace hydro::engine

#endif /* __h3o_engine_command_type__ */
