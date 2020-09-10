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

#ifndef __h3o_Dictionary__
#define __h3o_Dictionary__

#include "HObject.hpp"
#include "HClass.hpp"
#include "../vm/hvalue.hpp"

namespace hydro
{

    class HDictionary final : public HObject
    {
        HVM_INTERNAL_CLASS()

    public:
        virtual ~HDictionary();
        bool strict() { return _strict; }
        uint32_t size() { return _size; }

    protected:
        HDictionary(HvmEnv *env, HClass *dictionaryClass);
        void construct();
        void reserve(uint32_t capacity);
        void resize(uint32_t size);
        virtual bool tryGetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, hvalue &value) override;
        virtual bool trySetIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, const hvalue &value) override;
        virtual bool tryCallIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index, std::list<hvalue> args, hvalue &result) override;
        virtual bool tryDeleteIndex(HvmEnv *env, VM *vm, HvmContext *threadContext, hvalue index) override;

    private:
        struct dict_entry
        {
            hvalue key;
            hvalue value;
        };

        uint32_t _size, _capacity;
        bool _strict;
        dict_entry **_entries;
    };

    typedef object_ptr<HDictionary> hdictionary;

    void hydro_system_Dictionary_constructor(hdictionary instance);

} // namespace hydro

#endif /* __h3o_Dictionary__ */
