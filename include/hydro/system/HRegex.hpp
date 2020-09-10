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

#ifndef __h3o_Regex__
#define __h3o_Regex__

#include "HObject.hpp"

namespace hydro
{

    class HRegex : public HObject
    {
        HVM_INTERNAL_CLASS()

    public:
        HRegex(HvmEnv *env, HClass *regexClass);
        virtual ~HRegex();
        void construct(object_ptr<class HString> pattern);
        bool test(object_ptr<HString> value);
        std::string pattern() { return _pattern; }

    private:
        std::string _pattern;
        std::regex _value;
    };

    typedef object_ptr<HRegex> hregex;

} // namespace hydro

#endif /* __h3o_Regex__ */
