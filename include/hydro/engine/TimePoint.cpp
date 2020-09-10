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

#include "TimePoint.hpp"

namespace hydro::engine
{
/**
 * Implements the default constructor of the TimePoint class.
 */
TimePoint::TimePoint()
{
    mMilliseconds = std::chrono::milliseconds{0};
}

/**
 * Implements the value constructor of the TimePoint class.
 */
TimePoint::TimePoint(uint64_t ms)
{
    mMilliseconds = std::chrono::milliseconds{ms};
}

/**
 * Implements the copy constructor of the TimePoint class.
 */
TimePoint::TimePoint(const TimePoint &time)
{
    mMilliseconds = time.mMilliseconds;
}

/**
 * Implements the move constructor of the TimePoint class.
 */
TimePoint::TimePoint(TimePoint &&time)
{
    mMilliseconds = std::move(time.mMilliseconds);
}

/**
 * Implements the destructor of the TimePoint class.
 */
TimePoint::~TimePoint()
{
}

/**
 *
 */
TimePoint &
TimePoint::operator=(const TimePoint &rhs)
{
    mMilliseconds = rhs.mMilliseconds;
    return (*this);
}

/**
 *
 */
TimePoint &
TimePoint::operator=(TimePoint &&rhs)
{
    mMilliseconds = std::move(rhs.mMilliseconds);
    return (*this);
}

/**
 *
 */
bool TimePoint::operator==(const TimePoint &rhs) const
{
    return mMilliseconds == rhs.mMilliseconds;
}

/**
 *
 */
bool TimePoint::operator!=(const TimePoint &rhs) const
{
    return mMilliseconds != rhs.mMilliseconds;
}

/**
 *
 */
bool TimePoint::operator>(const TimePoint &rhs) const
{
    return mMilliseconds > rhs.mMilliseconds;
}

/**
 *
 */
bool TimePoint::operator>=(const TimePoint &rhs) const
{
    return mMilliseconds >= rhs.mMilliseconds;
}

/**
 *
 */
bool TimePoint::operator<(const TimePoint &rhs) const
{
    return mMilliseconds < rhs.mMilliseconds;
}

/**
 *
 */
bool TimePoint::operator<=(const TimePoint &rhs) const
{
    return mMilliseconds <= rhs.mMilliseconds;
}

/**
 *
 */
TimePoint
TimePoint::operator+(const TimePoint &rhs) const
{
    return TimePoint{count() + rhs.count()};
}

/**
 *
 */
TimePoint
TimePoint::operator-(const TimePoint &rhs) const
{
    return (*this) > rhs ? TimePoint{count() - rhs.count()} : TimePoint{rhs.count() - count()};
}

} // namespace hydro::engine
