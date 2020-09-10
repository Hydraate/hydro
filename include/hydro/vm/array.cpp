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

#include "array.hpp"

namespace hydro
{

array::array() : mLength{ 0 }
{
    // default
}

array::array(const array &arr) : mLength{arr.mLength}
{
    // copy
}

array::array(array &&arr) : mLength{arr.mLength}
{
    // move
}

array::array(uint64_t length) : mLength{ length }
{
    // initialize
}

} // namespace hydro
