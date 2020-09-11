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

#ifndef __h3o_engine_ElementInstance__
#define __h3o_engine_ElementInstance__

#include "Element.hpp"
#include "Instance.hpp"

namespace hydro::engine
{
/**
 * The ElementInstance class represents an element instance. The ElementInstance class keeps track of instance data for a single HElement instance and proxies the HElement.
 */
class ElementInstance final : public Instance
{
public:
    /**
     * Creates an ElementInstance object.
     */
    ElementInstance(Element *element);

    /**
     * Destroys the ElementInstance object.
     */
    virtual ~ElementInstance();
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementInstance__ */
