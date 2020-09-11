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

#ifndef __h3o_engine_AttributeObserver__
#define __h3o_engine_AttributeObserver__

#include "AttributeBinding.hpp"
#include "Space.hpp"

namespace hydro::engine
{
/**
 * 
 */
class AttributeObserver
{
public:
    /**
     * 
     */
    AttributeObserver(const AttributeBinding *attrBinding, Space *space);

    /**
     * 
     */
    virtual ~AttributeObserver();

    /**
     * 
     */
    void update();

    /**
     * 
     */
    const AttributeBinding *getBinding() const { return mAttrBinding; }

    /**
     * 
     * @return Returns the Space object that should be updated when the subject attribute changes.
     */
    Space *getSpace() const { return mSpace; }

protected:
    /**
     * 
     */
    const AttributeBinding *mAttrBinding;

    /**
     * 
     */
    Space *mSpace;
};

} // namespace hydro::engine

#endif /* __h3o_engine_AttributeObserver__ */
