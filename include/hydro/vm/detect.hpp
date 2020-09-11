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

#ifndef __HVM_OS__

/**
 * Detect operating system
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    // Windows
#define __HVM_WINDOWS__
    #ifdef _WIN64
        // for Windows 64-bit
        #define __HVM_WIN64__
        #define __HVM_OS__ "Windows 64-bit"
   #else
        // Windows 32-bit
        #define __HVM_WIN32__
        #define __HVM_OS__ "Windows 32-bit"
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
        #define __HVM_IOS__
        #define __HVM_IOS_SIM__
        #define __HVM_OS__ "Apple iOS"
    #elif TARGET_OS_IPHONE
        // iOS device
        #define __HVM_IOS__
        #define __HVM_OS__ "Apple iOS"
    #elif TARGET_OS_MAC
        // MacOS
        #define __HVM_MACOS__
        #define __HVM_OS__ "MacOS"
    #else
        // unknown Apple platform
        #error "Compilation on an unsupported Apple platform"
    #endif
#elif __linux__
    // Linux
    #define __HVM_LINUX__
    #define __HVM_OS__ "Linux"
#elif __unix__ // all unices not caught above
    // Unix
    #warning "UNIX is not officially supported"
    #define __HVM_OS__ "UNIX"
#elif defined(mPosIX_VERSION)
    // POSIX
    #warning "POSIX is not officially supported"
    #define __HVM_OS__ "POSIX"
#else
    #warning "Failed to detect compiler"
    #define __HVM_OS__ "undetected"
#endif

#endif /* __HVM_OS__ */
