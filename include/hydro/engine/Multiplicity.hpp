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

#ifndef __h3o_engine_Multiplicity__
#define __h3o_engine_Multiplicity__

#include <cmath>
#include <cstdlib>
#include <limits>

namespace hydro::engine
{
/**
 * Many cardinal represented by infinity.
 */
const uint32_t Many = std::numeric_limits<uint32_t>::infinity();

/**
 * The Multiplicity class represents a multiplicity in a relationship between two entities.
 */
class Multiplicity final
{
public:
    /**
     * Creates a nil Multiplicity object. The participation and maximum cardinality are both zero.
     */
    Multiplicity();

    /**
     * Creates a Multiplicity object with a minimum and maximum cardinal.
     * @param min The minimum cardinal.
     * @param max The maximum cardinal.
     */
    Multiplicity(uint32_t min, uint32_t max);

    /**
     * Creates a copy of a Multiplicity object using value sementics.
     * @param mult The Multiplicity object in which to copy.
     */
    Multiplicity(const Multiplicity &mult);

    /**
     * Creates a copy of a Multiplicity object using move sementics.
     * @param mult The Multiplicity object in which to copy.
     */
    Multiplicity(Multiplicity &&mult);

    /**
     * Destroys the Multiplicity object.
     */
    ~Multiplicity();

    /**
     * A constant one-to-one multiplicity.
     */
    static const Multiplicity OneToOne;

    /**
     * A constant one-to-many multiplicity.
     */
    static const Multiplicity OneToMany;

    /**
     * A constant many-to-many multiplicity.
     */
    static const Multiplicity ManyToMany;

    /**
     * Specifies if the relationship is zero-to-zero which is supplied by the default constructor.
     * @return Returns true if both values of the Multiplicity are zero. Otherwise returns false.
     */
    bool isNil() const { return mMin == 0 && mMax == 0; }

    /**
     * Gets the minimum cardinal value which is also known as the participation.
     * @return Returns the minimum cardinal as an unsigned integer. Returns infinity to represent many.
     */
    uint32_t min() const { return mMin; }

    /**
     * Gets the maximum cardinal which is also known as the cardinality.
     * @return Returns the maximum cardinal as an unsigned integer. Returns infinity to represent many.
     */
    uint32_t max() const { return mMax; }

    /**
     * Determines if the Multiplicity is nil.
     * @return Returns true if the Multiplicity is nil. Otherwise returns false. This is an alias to the isNil() method providing boolean semantics.
     */
    operator bool() const { return isNil(); }

    /**
     * Sets the Multiplicity equal to another using value semantics.
     * @return Returns a reference to itself.
     */
    Multiplicity &operator=(const Multiplicity &rhs);

    /**
     * Sets the Multiplicity equal to another using move semantics.
     * @return Returns a reference to itself.
     */
    Multiplicity &operator=(Multiplicity &&rhs);

    /**
     * Specifies whether or not the Multiplicity is equal to another.
     * @return Returns true if all values are equal. Otherwise returns false.
     */
    bool operator==(const Multiplicity &rhs) const;

    /**
     * Specifies whether or not the Multiplicity is not equal to another.
     * @return Returns true if any values are not equal. Otherwise returns false.
     */
    bool operator!=(const Multiplicity &rhs) const;

private:
    /**
     * The minimum cardinal.
     */
    uint32_t mMin;

    /**
     * The maximum cardinal.
     */
    uint32_t mMax;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Multiplicity__ */
