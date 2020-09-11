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

#include "ID.hpp"

namespace hydro::engine
{

const std::regex ID::ValidID{"^\\@?[a-zA-Z_][a-zA-Z0-9_]*$"};

ID::ID() {}

ID::ID(std::string value)
{
    // validate
    if (!std::regex_match(value, ValidID))
        throw invalid_id{};

    // omit @ if exists
    if (value[0] == '@')
        value = value.substr(1);

    mValue = value;
}

ID::ID(const ID &id)
{
    mValue = id.mValue;
}

ID::ID(ID &&id)
{
    mValue = std::move(id.mValue);
}

ID::~ID()
{
}

ID &
ID::operator=(const ID &rhs)
{
    mValue = rhs.mValue;
    return (*this);
}

ID &
ID::operator=(ID &rhs)
{
    mValue = std::move(rhs.mValue);
    return (*this);
}

bool ID::operator==(const ID &rhs) const
{
    return mValue == rhs.mValue;
}

bool ID::operator!=(const ID &rhs) const
{
    return mValue != rhs.mValue;
}

} // namespace hydro::engine
