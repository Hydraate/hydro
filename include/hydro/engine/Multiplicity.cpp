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

#include "Multiplicity.hpp"

namespace hydro::engine
{
const Multiplicity Multiplicity::OneToOne{1, 1};

const Multiplicity Multiplicity::OneToMany{1, Many};

const Multiplicity Multiplicity::ManyToMany{Many, Many};

Multiplicity::Multiplicity()
{
    mMin = mMax = 0;
}

Multiplicity::Multiplicity(uint32_t left, uint32_t right)
{
    // make sure lowest value is always to the left
    if (left < right)
    {
        mMin = left;
        mMax = right;
    }
    else
    {
        mMin = right;
        mMax = left;
    }
}

Multiplicity::Multiplicity(const Multiplicity &mult)
{
    mMin = mult.mMin;
    mMax = mult.mMax;
}

Multiplicity::Multiplicity(Multiplicity &&mult)
{
    mMin = mult.mMin;
    mMax = mult.mMax;
}

Multiplicity::~Multiplicity()
{
}

Multiplicity &Multiplicity::operator=(const Multiplicity &rhs)
{
    mMin = rhs.mMin;
    mMax = rhs.mMax;
    return (*this);
}

Multiplicity &
Multiplicity::operator=(Multiplicity &&rhs)
{
    mMin = rhs.mMin;
    mMax = rhs.mMax;
    return (*this);
}

bool Multiplicity::operator==(const Multiplicity &rhs) const
{
    return mMin == rhs.mMin && mMax == rhs.mMax;
}

bool Multiplicity::operator!=(const Multiplicity &rhs) const
{
    return mMin != rhs.mMin || mMax != rhs.mMax;
}

} // namespace hydro::engine
