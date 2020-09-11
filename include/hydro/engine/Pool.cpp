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

#include "Pool.hpp"

namespace hydro::engine
{
/**
 *
 */
Pool::Pool(std::size_t initialReserve, std::size_t maxCapacity)
{
    mMaxCapacity = maxCapacity;
    reserve(initialReserve < mMaxCapacity ? initialReserve : mMaxCapacity);
}

Pool::~Pool()
{
    delete[] mData;
}

void create(ID id, helement subject)
{
}

bool Pool::reserve(std::size_t capacity)
{
    if (capacity > mMaxCapacity)
    {
        // TODO truncate
        return false;
    }

    auto tmp = new pool_data *[capacity];
    std::size_t i = 0;

    // copy
    for (; i < mSize; i++)
        tmp[i] = mData[i];

    // populate
    for (; i < capacity; i++)
        tmp[i] = new pool_data{};

    mCapacity = capacity;
    delete[] mData;
    mData = tmp;
    return true;
}

bool Pool::resize(std::size_t newSize)
{
    if (newSize > mCapacity)
        if (!reserve(newSize * 2))
            return false;
    return true;
}

} // namespace hydro::engine
