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

#ifndef __h3o_ParseError__
#define __h3o_ParseError__

#include <string>
#include <cstdlib>

#include "Token.hpp"

namespace hydro
{
class ParseError
{
private:
	std::string _what;
	std::string _source;
	uint32_t mLine;

public:
	ParseError(std::string what, std::string source, uint32_t line);
	explicit ParseError(std::string what);
	virtual ~ParseError();
	std::string what() const { return _what; }
	std::string source() const { return _source; }
	uint32_t line() const { return mLine; }
	std::string message() const;
};

} // namespace hydro

#endif /* __h3o_ParseError__ */
