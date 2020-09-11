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

#ifndef __h3o_reflect_TypeInfo__
#define __h3o_reflect_TypeInfo__

namespace hydro::reflect
{

/**
 *
 */
template <typename T>
struct TypeInfo
{
    /**
     *
     */
    const char *qualifiedName;
    
};

} // namespace hydro::reflect

#endif /* __h3o_reflect__TypeInfo__ */
