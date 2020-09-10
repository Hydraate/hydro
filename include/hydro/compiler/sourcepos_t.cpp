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

#include "srcpos_t.hpp"

namespace hydro::compiler
{
srcpos_t::srcpos_t() : mmPos{nullptr} {}

srcpos_t::srcpos_t(const srcpos_t &pos) : mmPos{pos.mmPos} {}

srcpos_t::srcpos_t(srcpos_t &&pos) : mmPos{pos.mmPos} {}

srcpos_t::srcpos_t(SourcePosition *pos) : mmPos{pos} {}

srcpos_t::srcpos_t(std::nullptr_t) : mmPos{nullptr} {}

srcpos_t::~srcpos_t() {}

srcpos_t &srcpos_t::operator=(const srcpos_t &rhs)
{
    mmPos = rhs.mmPos;
    return (*this);
}

srcpos_t &srcpos_t::operator=(srcpos_t &&rhs)
{
    mmPos = rhs.mmPos;
    return (*this);
}

bool srcpos_t::operator==(const srcpos_t &rhs) const
{
    return rhs.mmPos == mmPos;
}

bool srcpos_t::operator!=(const srcpos_t &rhs) const
{
    return rhs.mmPos != mmPos;
}

} // namespace hydro::compiler
