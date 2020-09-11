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

#include "ParseError.hpp"

namespace hydro
{

ParseError::ParseError(std::string what, std::string source, uint32_t line) : _what{what}, _source{source}, mLine{line} {}

ParseError::ParseError(std::string what) : _what{what}, _source{}, mLine{0} {}

ParseError::~ParseError() {}

std::string ParseError::message() const
{
	std::string msg = "ParseError";

	if (!_source.empty())
		msg += " in " + _source;

	if (mLine)
		msg += " at line " + std::to_string(mLine);

	msg += ": " + _what;

	return msg;
}

} // namespace hydro
