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

#ifndef __h3o_Object__
#define __h3o_Object__

#define HCLASS()\
    HCLASS_0()

#define HCLASS_0()\
friend class HvmEnv;\
template <typename X>\
friend class NativeClassAllocator;\

#define HCLASS_1()\

#define HCLASS_2()\

#define HCORE()\
    friend class VM;

//

namespace hydro
{

class HvmEnv;

class _Class;

class Object
{
    HCLASS()
    HCORE()

public:
    
    Object();

    virtual ~Object();

private:
    
};

} // namespace hydro

#endif /* __h3o_Object__ */
