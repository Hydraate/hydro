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

#ifndef __h3o_terminal_format__
#define __h3o_terminal_format__

#include <iostream>

#include "../vm/detect.hpp"

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.

namespace hydro
{

class terminal_format
{
public:
    terminal_format() {}
    terminal_format(const char *value) : m_value{value} {}
    terminal_format(std::string value) : m_value{value} {}
    terminal_format(const terminal_format &format) : m_value{format.m_value} {}
    terminal_format(terminal_format &&format) : m_value{format.m_value} {}
    ~terminal_format() {}
    std::string value() const { return m_value; }
    bool empty() const { return m_value.empty(); }
    operator bool() const { return !m_value.empty(); }
    terminal_format &operator=(const terminal_format &rhs)
    {
        m_value = rhs.m_value;
        return (*this);
    }
    terminal_format &operator=(terminal_format &&rhs)
    {
        m_value = rhs.m_value;
        return (*this);
    }
    terminal_format operator+(const terminal_format &rhs) const
    {
        if(m_value == rhs.m_value)
            return rhs;
        return m_value + rhs.m_value;
    }
    static terminal_format txt256(uint8_t code) { return "\u001b[38;5;" + std::to_string(code) + "m"; }
    static terminal_format bg256(uint8_t code) { return "\u001b[48;5;" + std::to_string(code) + "m"; }

private:
    std::string m_value;

};

const terminal_format NIL_FORMAT;
const terminal_format RESET = "\033[0m";
const terminal_format BLACK = "\033[30m";
const terminal_format RED = "\033[31m";
const terminal_format GREEN = "\033[32m";
const terminal_format YELLOW = "\033[33m";
const terminal_format BLUE = "\033[34m";
const terminal_format MAGENTA = "\033[35m";
const terminal_format CYAN = "\033[36m";
const terminal_format WHITE = "\033[37m";
const terminal_format BOLD = "\u001b[1m";
const terminal_format UNDERLINE = "\u001b[4m";

std::ostream &operator<<(std::ostream &lhs, const terminal_format &rhs);

} // namespace hydro

#endif /* __h3o_terminal_format__ */
