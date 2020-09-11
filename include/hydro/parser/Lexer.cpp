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

#include "Lexer.hpp"

namespace hydro
{

Lexer::Lexer(Compiler *compiler) : mCompiler{compiler}, mTokenNames{}, mTokenPatterns{}, mCurrentToken{}, mEofToken{}, _source{}, mBuffer{}, mSpecPos{0}, mMarkers{}, trace{false}, mPos{-1}, mContent{""}, _currentChar{'\0'}, mLine{0}
{
	// common tokens by value
	registerTokenName(",", "comma");
	registerTokenName(":", "colon");
	registerTokenName(";", "semicolon");
	registerTokenName("(", "left parenthesises");
	registerTokenName(")", "right parenthesises");
	registerTokenName("{", "left curly bracket");
	registerTokenName("}", "right curly bracket");
	registerTokenName("[", "left square bracket");
	registerTokenName("]", "right square bracket");
	registerTokenName("$", "dollar sign");
	registerTokenName("!", "exclamation mark");
	registerTokenName("?", "question mark");
	registerTokenName("#", "hash symbol");
	registerTokenName("*", "asterisk");
	registerTokenName("%", "percent symbol");
	registerTokenName("+", "plus sign");
	registerTokenName("-", "minus sign");
	registerTokenName("/", "forward slash");
	registerTokenName("\\", "back slash");
	registerTokenName(".", "dot");
	registerTokenName("|", "pipe");
	registerTokenName("&", "ampersand");
	registerTokenName("'", "single quote");
	registerTokenName("\"", "double quote");
	registerTokenName("^", "caret");
	registerTokenName("@", "at sign");
	registerTokenName("`", "grave accent");
	registerTokenName("~", "tilde");
	registerTokenName(">", "greater than sign");
	registerTokenName("<", "less than sign");
	registerTokenName("=", "equal sign");
	registerTokenName("\n", "linefeed");
	registerTokenName("\t", "horizontal tab");
	registerTokenName("\r", "carriage return");
	registerTokenName("\f", "formfeed");

	// less common tokens
	registerTokenName("©", "copyright symbol");
	registerTokenName("£", "");
	registerTokenName("¢", "cent symbol");
	registerTokenName("®", "registered trademark symbol");
	registerTokenName("¡", "inverted exclamation mark");
	registerTokenName("™", "trademark symbol");
	registerTokenName("∞", "infinity symbol");
	registerTokenName("§", "section sign");
	registerTokenName("¶", "pilcrow");
	registerTokenName("•", "bullet");
	registerTokenName("ª", "feminine ordinal indicator");
	registerTokenName("º", "masculine ordinal indicator");
	registerTokenName("–", "en dash");
	registerTokenName("≠", "not equal sign");
	registerTokenName("∑", "sigma");
	registerTokenName("†", "dagger");
	registerTokenName("¥", "yen symbol");
	registerTokenName("π", "pi");
	registerTokenName("“", "left double quote");
	registerTokenName("‘", "");
	registerTokenName("«", "");
	registerTokenName("å", "");
	registerTokenName("ß", "theta");
	registerTokenName("∂", "");
	registerTokenName("ƒ", "");
	registerTokenName("˙", "");
	registerTokenName("∆", "delta");
	registerTokenName("˚", "");
	registerTokenName("¬", "");
	registerTokenName("…", "");
	registerTokenName("æ", "");
	registerTokenName("Ω", "omega");
	registerTokenName("≈", "");
	registerTokenName("ç", "");
	registerTokenName("√", "");
	registerTokenName("∫", "");
	registerTokenName("˜", "");
	registerTokenName("µ", "");
	registerTokenName("≤", "less than or equal sign");
	registerTokenName("≥", "greater than or equal sign");
	registerTokenName("÷", "division sign");
	registerTokenName("⁄", "");
	registerTokenName("€", "");
	registerTokenName("‹", "");
	registerTokenName("›", "");
	registerTokenName("ﬁ", "");
	registerTokenName("‡", "");
	registerTokenName("°", "");
	registerTokenName("·", "");

	// tokens by type
    registerTokenName(eof_tkn, "end of token stream");
    registerTokenName(ws_tkn, "whitespace");
    registerTokenName(ln_tkn, "linefeed");
    registerTokenName(scomment_tkn, "single-line comment");
    registerTokenName(mcomment_tkn, "multi-line comment");
    registerTokenName(id_tkn, "identifier");
    registerTokenName(float_tkn, "float literal");
    registerTokenName(double_tkn, "double literal");
    registerTokenName(oct_tkn, "octal literal");
    registerTokenName(uint_tkn, "unsigned integer literal");
    registerTokenName(int_tkn, "integer literal");
    registerTokenName(short_tkn, "short literal");
    registerTokenName(ushort_tkn, "unsigned short literal");
    registerTokenName(long_tkn, "long literal");
    registerTokenName(ulong_tkn, "unsigned long literal");
    registerTokenName(bin_tkn, "binary literal");
    registerTokenName(hex_tkn, "hexadecimal literal");
    registerTokenName(char_tkn, "character literal");
    registerTokenName(string_tkn, "string literal");
    registerTokenName(op_tkn, "operator");
    registerTokenName(regex_tkn, "regular expression literal");
    registerTokenName(directive_tkn, "directive");
    registerTokenName(token_tkn, "token");
}

Lexer::~Lexer()
{
	unload();

	for (TokenInfo *info : mTokenNames)
		delete info;

	for (TokenPattern *pttn : mTokenPatterns)
		delete pttn;
}

char Lexer::la(int32_t k)
{
    int32_t index = mPos + k;
    
    if(index < 0)
        return '\0'; // out of bounds
    
    if(k > 0 && index >= mContent.length())
    {
        while (k-- > 0 && _source->hasNext())
            readChar();
    }
    
    if(index < mContent.length())
        return mContent[index];
    
    // fail
    return '\0';
}

lex_token Lexer::flush(int32_t tokenType)
{
	lex_token token = new Token{_source, mBuffer, tokenType, mLine, mPos};
	mBuffer = ""; // clear buffer
	return token;
}

void Lexer::registerTokenName(std::string tokenValue, std::string tokenName)
{
	for (TokenInfo *info : mTokenNames)
	{
		if (info->value == tokenValue)
		{
			info->name = tokenName;
			return;
		}
	}

	mTokenNames.push_back(new Lexer::TokenInfo{tokenName, tokenValue});
}

void Lexer::registerTokenName(int32_t tokenType, std::string tokenName)
{
	for (TokenInfo *info : mTokenNames)
	{
		if (info->type == tokenType)
		{
			info->name = tokenName;
			return;
		}
	}
	mTokenNames.push_back(new Lexer::TokenInfo{tokenName, tokenType});
}

Lexer::TokenInfo *Lexer::findTokenName(std::string tokenValue) const
{
	for (TokenInfo *info : mTokenNames)
		if (info->value == tokenValue)
			return info; // success!

	// fail
	return nullptr;
}

Lexer::TokenInfo *Lexer::findTokenName(int32_t tokenType) const
{
	for (TokenInfo *info : mTokenNames)
		if (info->type == tokenType)
			return info; // success!

	// fail
	return nullptr;
}

void Lexer::registerTokenPattern(int32_t tokenType, std::string pattern)
{
	registerTokenPattern(tokenType, std::regex{pattern});
}

void Lexer::registerTokenPattern(int32_t tokenType, std::string pattern, char sentinel)
{
	registerTokenPattern(tokenType, std::regex{pattern}, sentinel);
}

void Lexer::registerTokenPattern(int32_t tokenType, std::regex pattern)
{
	for (TokenPattern *p : mTokenPatterns)
	{
		if (p->type == tokenType)
		{
			// override
			p->pattern = pattern;
			return;
		}
	}

	mTokenPatterns.push_back(new TokenPattern{tokenType, pattern});
}

void Lexer::registerTokenPattern(int32_t tokenType, std::regex pattern, char sentinel)
{
	for (TokenPattern *p : mTokenPatterns)
	{
		if (p->type == tokenType)
		{
			// override
			p->pattern = pattern;
			p->sentinel = sentinel;
			return;
		}
	}

	mTokenPatterns.push_back(new TokenPattern{tokenType, pattern, sentinel});
}

Lexer::TokenPattern *Lexer::findTokenPattern(int32_t tokenType) const
{
	for (TokenPattern *p : mTokenPatterns)
		if (p->type == tokenType)
			return p; // success!

	// fail
	return nullptr;
}

void Lexer::appendError(std::string errorTxt, uint32_t line, int32_t index)
{
	mCompiler->appendError(errorTxt, _source->location(), line, index);
}

bool Lexer::isEof(int32_t k)
{
	return la(k) == EOF;
}

bool Lexer::matchLa(char ch, int32_t k)
{
	return la(k) == ch;
}

bool Lexer::matchLa(const std::regex &pattern, int32_t k)
{
	std::string ch = "";
	ch += la(k);
	return std::regex_match(ch, pattern);
}

bool Lexer::matchLa(int32_t registeredTokenType, int32_t k)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchLa(pattern->pattern, k) : false;
}

bool Lexer::matchBuffer(const std::regex &pattern)
{
	std::string value = mBuffer;
	return value.length() > 0 ? std::regex_match(value, pattern) : false;
}

bool Lexer::matchBuffer(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchBuffer(pattern->pattern) : false;
}

bool Lexer::matchBufferWithCurrent(const std::regex &pattern)
{
	std::string value = bufferWithCurrent();
	return value.length() > 0 ? std::regex_match(value, pattern) : false;
}

bool Lexer::matchBufferWithCurrent(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchBufferWithCurrent(pattern->pattern) : false;
}

bool Lexer::matchBufferWithNext(const std::regex &pattern)
{
	std::string value = bufferWithNext();
	return value.length() > 0 ? std::regex_match(value, pattern) : false;
}

bool Lexer::matchBufferWithNext(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchBufferWithNext(pattern->pattern) : false;
}

bool Lexer::matchCurrent(char ch)
{
	return matchLa(ch, 0);
}

bool Lexer::matchCurrent(const std::regex &pattern)
{
	return matchLa(pattern, 0);
}

bool Lexer::matchCurrent(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchLa(pattern->pattern, 0) : false;
}

bool Lexer::matchPrev(char ch)
{
	return matchLa(ch, -1);
}

bool Lexer::matchPrev(const std::regex &pattern)
{
	return matchLa(pattern, -1);
}

bool Lexer::matchPrev(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchLa(pattern->pattern, -1) : false;
}

bool Lexer::matchNext(char ch)
{
	return matchLa(ch, 1);
}

bool Lexer::matchNext(const std::regex &pattern)
{
	return matchLa(pattern, 1);
}

bool Lexer::matchNext(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);
	return pattern ? matchLa(pattern->pattern, 1) : false;
}

bool Lexer::currentExists()
{
	return la(0);
}

bool Lexer::prevExists()
{
	return la(-1);
}

bool Lexer::nextExists()
{
	return la(1);
}

lex_token Lexer::devour(int32_t registeredTokenType)
{
	TokenPattern *pattern = findTokenPattern(registeredTokenType);

	// if pattern exists
	if (pattern)
	{
		if (matchBufferWithNext(pattern->pattern))
		{
			consume();     // eat
			int32_t k = 1; // lookahead

			while (la(k) && la(k) != pattern->sentinel &&
				 matchBufferWithNext(pattern->pattern))
			{
				consume();
				k++;
			}

			return flush(registeredTokenType);
		}
	}

	// fail
	return nullptr;
}

void Lexer::specStart()
{
	mark();
}

bool Lexer::specSuccess()
{
	mMarkers.pop_back();
	return true;
}

bool Lexer::specFail()
{
	release();
	return false;
}

void Lexer::mark()
{
	mMarkers.push_back(mSpecPos);
}

void Lexer::release()
{
	if (mMarkers.empty())
		return;

	int32_t m = mMarkers.back();
	mMarkers.pop_back();
	seek(m);
}

void Lexer::seek(int32_t k)
{
	mSpecPos = k;
}

int32_t Lexer::specPos() const
{
	return mSpecPos;
}

int32_t Lexer::specUp()
{
	return ++mSpecPos;
}

int32_t Lexer::specDown()
{
	return --mSpecPos;
}

bool Lexer::specMatch(char ch)
{
	specStart();

	if (matchLa(ch, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Lexer::specMatch(const std::regex &pattern)
{
	specStart();

	if (matchLa(pattern, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Lexer::specMatch(int32_t registeredTokenType)
{
	specStart();

	if (matchLa(registeredTokenType, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Lexer::specExists()
{
	return la(mSpecPos);
}

char Lexer::specCurrent()
{
	return la(mSpecPos);
}

char Lexer::specPrev()
{
	return la(mSpecPos - 1);
}

char Lexer::specNext()
{
	return la(mSpecPos + 1);
}

char Lexer::readChar()
{
    if(_source && _source->hasNext())
    {
        char ch = _source->nextChar();
        mContent += ch;
        return ch;
    }
    
    // fail
    return '\0';
}

void Lexer::advance()
{
    if(mPos + 1 < mContent.length())
    {
        mPos++;
        _currentChar = mContent[mPos];
    }
    else
    {
        mPos++;
        _currentChar = readChar();
    }
    
    if(_currentChar == '\n')
        mLine++;
	mSpecBuffer = "";
	mSpecPos = 1; // la(1)
	mMarkers.clear();
}

void Lexer::consume()
{
	if (!_source)
		return;

	advance();
    mBuffer += _currentChar;
}

void Lexer::skip()
{
	advance(); // skip any once
}

void Lexer::skipOnce(char ch)
{
	if (matchNext(ch))
		advance();
}

void Lexer::skipAll(char ch)
{
	while (matchNext(ch))
		advance();
}

void Lexer::skipOnce(const std::regex &pattern)
{
	if (matchNext(pattern))
		advance();
}

void Lexer::skipAll(const std::regex &pattern)
{
	while (matchNext(pattern))
		advance();
}

void Lexer::abrupt()
{
	if (la(0))
		throw std::runtime_error{"Encountered unexpected token '" + std::string{1, la(0)} + "'."};

	throw std::runtime_error{"Encountered unexpected end of token stream."};
}

void Lexer::unload()
{
	mCurrentToken = mEofToken = nullptr;
	mBuffer = mSpecBuffer = "";
	mSpecPos = 1; // la(1)
	mMarkers.clear();
	mPos = -1;
    _currentChar = '\0';
	delete _source;
	_source = nullptr;
    mContent = "";
    mLine = 1;
}

void Lexer::load(Source *src)
{
	unload();
	_source = src;
}

bool Lexer::hasNext() const
{
    return mPos + 1 < mContent.length() || _source->hasNext();
}

lex_token Lexer::nextToken()
{
	if (hasNext())
	{
		lex_token token = readNext();

		if (token)
		{
			if (trace)
			{
				std::string val = token->value();
				std::string name = getTokenName(token);
				std::cout << "{" << val << ":" << name << "}\n";
			}

			return token;
		}
	}

	return nullptr;
}

lex_token Lexer::nextToken(int32_t pos)
{
    mPos = pos;
	return nextToken();
}

lex_token Lexer::nextChar()
{
	if (hasNext())
	{
		consume(); // eat next character
        lex_token token = flush(token_tkn); // make token

		if (token)
		{
			if (trace)
			{
				std::string val = token->value();
				std::string name = getTokenName(token);
				std::cout << "{" << val << ":" << name << "}\n";
			}

			return token;
		}
	}

	return nullptr;
}

lex_token Lexer::nextChar(int32_t pos)
{
    mPos = pos;
    return nextChar();
}

lex_token Lexer::charAt(int32_t index)
{
    if (_source && mPos)
    {
        if(index < mContent.length())
            return new Token{_source, std::string{1, mContent[index]}, token_tkn, mLine, index};
    }
    
	// out of bounds
	return nullptr;
}

lex_token Lexer::lookChar(int32_t k)
{
    int32_t index = mPos + k;
    
    if (index >= 0 && index < mContent.length())
    {
        // using cache
        return new Token{_source, std::string{1, mContent[index]}, token_tkn, mLine, index};
    }
    else
    {
        // lookahead
        k = index - k;
        while (hasNext() && k-- > 0)
            readChar();
        
        if(k > 0)
            return new Token{_source, std::string{1, EOF}, token_tkn, mLine, index}; // out of bounds
        
        return new Token{_source, std::string{1, mContent[index]}, token_tkn, mLine, index};
    }
    
	// out of bounds
	return nullptr;
}

void Lexer::jump()
{
}

lex_token Lexer::tokenize()
{
	while (hasNext())
		nextToken();

	if (mCurrentToken)
	{
		lex_token token = mCurrentToken->begin();
		return token ? token : mCurrentToken;
	}

	// token does not exist
	return nullptr;
}

void Lexer::dump()
{
	if (mCurrentToken)
	{
		lex_token token = mCurrentToken->begin();

		if (!token)
			token = mCurrentToken;

		while (token)
		{
			std::string val = token->value();
			std::string name = getTokenName(token);
			std::cout << "{" << val << ":" << name << "}\n";
			token = token->next();
		}
	}
}

std::string Lexer::getTokenName(lex_token token)
{
	if (!token)
		return "nil token";

	TokenInfo *info = findTokenName(token->value());

	if (!info)
		info = findTokenName(token->type());

	return info ? info->name : "";
}

std::string Lexer::getTokenName(std::string tokenValue)
{
	TokenInfo *info = findTokenName(tokenValue);

	// ** note: if the token name does not exists the token's value is used
	return info ? info->name : tokenValue;
}

std::string Lexer::getTokenName(int32_t tokenType)
{
	TokenInfo *info = findTokenName(tokenType);
	return info ? info->name : "";
}

} // namespace hydro
