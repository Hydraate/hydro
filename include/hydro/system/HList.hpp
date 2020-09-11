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

#ifndef __h3o_List__
#define __h3o_List__

#include <list>

#include "HClass.hpp"

namespace hydro
{

    typedef object_ptr<class HList> hlist;

    class HList final : public HObject
    {
        HVM_INTERNAL_CLASS()
        friend void hydro_system_List_constructor(hlist instance, hlist elements);

    public:
        virtual ~HList();
        void set(uint32_t index, hvalue element);
        hvalue get(uint32_t index) { return (index >= 0 && index < _len) ? mBuffer[index] : (hvalue)undefined; }
        uint32_t push(hvalue element);
        hvalue pop();
        void setLength(uint32_t value);
        uint32_t getLength()
        {
            return _len;
        }
        virtual std::string toString() override;
        object_ptr<HList> clone() const;

    protected:
        virtual bool tryGetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, hvalue &value) override;
        virtual bool trySetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, const hvalue &value) override;
        virtual bool tryCallIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, std::list<hvalue> args, hvalue &result) override;

        HList(HvmEnv *env, hclass vclass);
        void construct();

    private:
        hvalue *mBuffer;
        uint32_t _len; // the length
    };

    typedef object_ptr<HList> hlist;

    void hydro_system_List_constructor(hlist instance, hlist elements);

} // namespace hydro

#endif /* __h3o_List__ */
