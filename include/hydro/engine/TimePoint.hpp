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

#ifndef __h3o_engine_TimePoint__
#define __h3o_engine_TimePoint__

#include <chrono>
#include <cstdlib>

/**
 * The quantity of milliseconds in one second.
 */
#define SECOND_IN_MS 1000

/**
 * The quantity of milliseconds in one minute.
 */
#define MINUTE_IN_MS 60000

/**
 * The quantity of milliseconds in one hour.
 */
#define HOUR_IN_MS 3600000

/**
 * The quantity of milliseconds in one day.
 */
#define DAY_IN_MS 86400000

namespace hydro::engine
{
/**
 * The TimePoint class represents a point in time from zero
 */
class TimePoint final
{
public:
    /**
     * Creates a TimePoint object with a value of zero.
     */
    TimePoint();

    /**
     * Creates a TimePoint object from a millisecond value.
     */
    TimePoint(uint64_t ms);

    /**
     * Creates a TimePoint object by copying another Time object.
     */
    TimePoint(const TimePoint &time);

    /**
     * Creates a TimePoint object using move semantics.
     */
    TimePoint(TimePoint &&time);

    /**
     * Destroys the TimePoint object.
     */
    ~TimePoint();

    /**
     * Creates a TimePoint object using minutes, seconds, and milliseconds.
     */
    static TimePoint from(uint32_t hours, uint32_t minutes, uint32_t seconds, uint8_t milliseconds = 0) { return TimePoint{hours * HOUR_IN_MS + minutes * MINUTE_IN_MS + seconds * SECOND_IN_MS + milliseconds}; }

    /**
     * Creates a TimePoint object using minutes, seconds, and milliseconds.
     */
    static TimePoint from(uint32_t minutes, uint32_t seconds, uint8_t milliseconds = 0) { return from(0, minutes, seconds, milliseconds); }

    /**
     * Provides the total number of milliseconds that the TimePoint represents.
     * @return Returns the value of the TimePoint in milliseconds as an unsigned 64-bit integer.
     */
    uint64_t count() const { return (uint64_t)mMilliseconds.count(); }

    /**
     * Sets the TimePoint object equal to another TimePoint via copying.
     * @return Returns a reference to itself.
     */
    TimePoint &operator=(const TimePoint &rhs);

    /**
     * Sets the TimePoint object equal to another TimePoint using move semantics.
     * @return Returns a reference to itself.
     */
    TimePoint &operator=(TimePoint &&rhs);

    /**
     * Determines if the TimePoint object is equal to another.
     * @return Returns true if the value of the TimePoint objects are identical. Otherwise returns false.
     */
    bool operator==(const TimePoint &rhs) const;

    /**
     * Determines if the TimePoint object is not equal to another.
     * @return Returns false if the value of the TimePoint objects are identical. Otherwise returns true.
     */
    bool operator!=(const TimePoint &rhs) const;

    /**
     * Compares the TimePoint object to another to see if the TimePoint is greater than the other.
     * @return Trues true if this TimePoint is not equal to the TimePoint on the right-hand side of the comparison operator.
     */
    bool operator>(const TimePoint &rhs) const;

    /**
     * Compares the TimePoint object to another to determine if the TimePoint is greather than the other.
     * @return Trues true if this TimePoint is greater than the TimePoint on the right-hand side of the comparison operator.
     */
    bool operator>=(const TimePoint &rhs) const;

    /**
     *
     */
    bool operator<(const TimePoint &rhs) const;

    /**
     *
     */
    bool operator<=(const TimePoint &rhs) const;

    /**
     * Adds the TimePoint object with another to produce a new TimePoint object equal to the sum of both TimePoint objects.
     */
    TimePoint operator+(const TimePoint &rhs) const;

    /**
     * Subtracts the TimePoint object with another to produce a new TimePoint that represents the absolute value diffential between the two TimePoint objects.
     */
    TimePoint operator-(const TimePoint &rhs) const;

private:
    /**
     * The TimePoint represented as milliseconds.
     */
    std::chrono::milliseconds mMilliseconds;
};

} // namespace hydro::engine

#endif /* __h3o_engine_TimePoint__ */
