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

#include "Line.hpp"

namespace hydro::compiler
{
/**
 *
 */
Line::Line()
{
}

/**
 *
 */
Line::Line(uint32_t lineNumber, std::string lineContent, compilation_status status) : mContent{new line_data{lineNumber, lineContent, status}}
{
}

/**
 *
 */
Line::Line(const Line& line) : mContent{line.mContent}
{
}

/**
 *
 */
Line::Line(Line&& line) : mContent{line.mContent}
{
}

/**
 *
 */
Line::~Line()
{
}

/**
 *
 */
Line& Line::operator=(const Line& rhs)
{
    mContent = rhs.mContent;
    return (*this);
}

/**
 *
 */
Line& Line::operator=(Line&& rhs)
{
    mContent = rhs.mContent;
    return (*this);
}

} // namespace hydro::compiler
