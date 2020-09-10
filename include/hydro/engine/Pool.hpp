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

#ifndef __h3o_engine_Pool__
#define __h3o_engine_Pool__

#include "../system/HElement.hpp"
#include "Element.hpp"
#include "ID.hpp"

namespace hydro::engine
{
/**
 * The Pool class implements the Object Pool pattern to regulate the amount of elements that are allocated for a particular document performance. 
 */
class Pool final
{
public:
    /**
     * Creates a Pool object with an initial reserve and maximum capacity.
     */
    Pool(std::size_t initialReserve, std::size_t maxCapacity);

    /**
     * Destroys the Pool object.
     */
    ~Pool();

    /**
     * Creates a trackable element or pulls the element from the pull if it already exists.
     * @param id The unique identifier used to reference an entity.
     * @param descriptor The element entity from the parsed document that describes the element in which to create or reference.
     * @return Returns the newly created element or an existing element in the pool.
     */
    HElement *get(ID id, Element *descriptor);

    /**
     * Creates a trackable element or pulls the element from the pull if it already exists.
     * @param descriptor The element entity from the parsed document that describes the element in which to create or reference.
     * @return Returns the newly created element.
     */
    HElement *get(Element *descriptor);

    /**
     *
     */
    void release(ID id);

    /**
     * Releases an element from the pool causing the element to potentially be garbage collected. The element can no longer be referenced by the pool.
     * @param subject The element in which to release from the pool.
     */
    void release(helement subject);
    
    /**
     * Gets the current capacity of the pool. This is not synonymous with the size or maximum capacity with the pool.
     * @return Returns the current capacity that represents how much space has been allocated for potential entries inside the poo.
     */
    std::size_t capacity() const { return mCapacity; }
    
    /**
     * Gets teh maximum capacity of the pool.
     * @return
     */
    std::size_t maxCapacity() const { return mMaxCapacity; }
    
    /**
     * Gets the size of the pool.
     * @return Returns the current number of elements that are currently allocated and managed by the pool.
     */
    std::size_t size() const { return mSize; }
    
    /**
     *
     * @return
     */
    bool hasAvailableSpace() const { return mSize < mMaxCapacity; }

private:
    /**
     * The pool_data struct stores information about an pool element. Elements may be referenced via an unique ID. An element has zero or one ID references. An ID has one and only one element that it references.
     */
    struct pool_data
    {
        /**
         * The unique ID that is assigned to the element subject. If the ID is nil, the subject is anonymous in the engine's environment so all references to the element exists outside of the pool by either a query or some other structure.
         */
        ID id;
        
        /**
         * The element that belongs to the pool.
         */
        helement subject;
    };

    std::size_t mCapacity;
    
    std::size_t mMaxCapacity;
    
    std::size_t mSize;
    
    pool_data **mData;

    bool reserve(std::size_t capacity);
    
    
    bool resize(std::size_t newSize);
};

} // namespace hydro::engine

#endif /* __h3o_engine_Pool__ */
