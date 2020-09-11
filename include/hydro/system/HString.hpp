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

#ifndef __h3o_HString__
#define __h3o_HString__

#include <string>
#include <cstdlib>

#include "HObject.hpp"

namespace hydro
{

typedef object_ptr<class HString> hstring;

class HString final : public HObject
{
    HVM_INTERNAL_CLASS()

    public:
        virtual ~HString();
        hstring substr(uint32_t pos, int32_t length);
        uint32_t length() { return _len; }
        bool empty() { return _len == 0; }
        operator std::string() const
        {
            const unsigned n = _len + 1;
            char *buf = new char[n];

            for (uint32_t i = 0; i < _len; i++)
                buf[i] = mBuffer[i];

            buf[_len] = '\0';

            return std::string(buf);
        }
        operator const char *() const
        {
            char *copy = new char[_len];

            for (uint32_t i = 0; i < _len; i++)
                copy[i] = mBuffer[i];

            return copy;
        }
        operator char *() const
        {
            char *copy = new char[_len];

            for (uint32_t i = 0; i < _len; i++)
                copy[i] = mBuffer[i];

            return copy;
        }

        virtual std::string toString() override
        {
            std::string s = "";
            for (uint32_t i = 0; i < _len; i++)
                s += mBuffer[i];
            return s;
        }
        
        virtual bool equals(hvalue value) override
        {
            if(hstring s = value.tryCast<HString>())
            {
                HString *str = s;
                
                if(str->_len == _len)
                {
                    for(uint32_t i = 0; i < _len; i++)
                        if (str->mBuffer[i] != mBuffer[i])
                            return false; // fail
                    
                    // success!
                    return true;
                }
            }
            
            // not a string
            return false;
        }
        
        
    
private:
	char16_t *mBuffer;
	uint32_t _len;
	static unsigned strlen(const char16_t *);
    
	HString(hstring value);
	HString(const char *value);
	HString(const char16_t *value);
	HString(std::string value);
	HString(HvmEnv *env, HClass *vclass, hstring value);
	HString(HvmEnv *env, HClass *vclass, const char *value);
	HString(HvmEnv *env, HClass *vclass, const char16_t *value);
	HString(HvmEnv *env, HClass *vclass, std::string value);
    HString(HvmEnv *env, HClass *vclass);
    
    void construct(hvalue value);
    
    friend class hvalue;
    friend struct MakeService;
};

void hydro_system_String_constructor(hstring instance);

} // namespace hydro

#endif /* __h3o_HString__ */
