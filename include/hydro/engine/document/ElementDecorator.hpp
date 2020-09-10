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

#ifndef __h3o_engine_ElementDecorator__
#define __h3o_engine_ElementDecorator__

#include "Element.hpp"
#include "ElementInstance.hpp"
#include "InstanceDecorator.hpp"

namespace hydro::engine
{
/**
 * The ElementDecorator class is responsible for emitting instructions that decorate an element instance. The ElementDecorator does not update the actual proxied element. The burden of this responsibility lies upon the ElementInstance class.
 */
class ElementDecorator : public InstanceDecorator
{
public:
    /**
     * Creates an ElementDecorator object with an element instance an element entity.
     * @param instance The element instance that the decorator will manipulate.
     * @param element The element entity that the decorator will implement.
     */
    ElementDecorator(ElementInstance *instance, Element *element);

    /**
     * Destroys the ElementDectorator object.
     */
    virtual ~ElementDecorator();
};

} // namespace hydro::engine

#endif /* __h3o_engine_ElementDecorator__ */
