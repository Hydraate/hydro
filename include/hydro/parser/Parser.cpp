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

#include "Parser.hpp"

namespace hydro
{

Parser::Parser(Lexer *lexer) : mLexer{lexer}, mTokens{nullptr}, mCurrentToken{nullptr}, _currentScope{nullptr}, mMarkers{}, mIgnoredTokenTypes{}, mLookaheadBuffer{}, mSpecPos{0}, mIndex{-1}, mParsing{false}
{
	mCompiler = lexer->getCompiler();
}

Parser::~Parser()
{
	//if (mCurrentToken)
		//delete mCurrentToken->top();
}

void Parser::__parse()
{
	if (mParsing)
		return;

	mParsing = true;

	while (mParsing && mLexer->hasNext())
	{
		advance();
		if (isEof())
			break; // end of file

		parseNext();
	}

	mParsing = false;
}

void Parser::abort()
{
	mParsing = false;
	throw bad_parse_abort{};
}

void Parser::reset()
{
	mParsing = false;
	_currentScope = nullptr;
	mTokens = mCurrentToken = nullptr; // clear token pointer and token tree
	mMarkers.clear();
	mIndex = -1;
	mSpecPos = 0;
	mLookaheadBuffer.clear();
}

void Parser::insert(lex_token token)
{
	if (!token)
		return;

	// insert token into token tree or create tree
	if (mTokens)
		mTokens->insert(token);

	mTokens = token;
}

lex_token Parser::laPopFront()
{
	if (mLookaheadBuffer.empty())
		return nullptr; // empty
	lex_token front = mLookaheadBuffer.front();
	mLookaheadBuffer.pop_front();
	return front;
}

void Parser::pushLaToken(lex_token token)
{
	mLookaheadBuffer.push_back(token);
}
/*
void Parser::advance()
{
	mMarkers.clear();
	mSpecPos = 0;
	clearMemo();
    
	if (mCurrentToken && mCurrentToken->next())
	{
		// lookahead token exists
		do
        {
			mCurrentToken = mCurrentToken->next();
            insert(mCurrentToken);
        }
		while (mCurrentToken && willIgnore(mCurrentToken->type()));
        
	}
	else if (mLexer->hasNext())
	{
		do
		{
			// load token
			mCurrentToken = mLexer->nextToken();
            //insert(mCurrentToken);
			// mCurrentToken->dump();
		} while (mCurrentToken && willIgnore(mCurrentToken->type()));
	}
}*/

void Parser::advance()
{
	// reset speculation
	mMarkers.clear();
	mSpecPos = 0;
	clearMemo();

	// insert current token into token tree (if exists)
	if (mCurrentToken)
		insert(mCurrentToken);

	// advance to next recognizable token
	lex_token token;

	do
	{
		// try to get lookahead token
		token = laPopFront();

		if (token)
		{
			// use lookahead token
			mCurrentToken = token;
		}
		else
		{
			// read next token
			mCurrentToken = mLexer->nextToken();
		}
	} while (willIgnore(mCurrentToken));
}

void Parser::advanceChar()
{
	mMarkers.clear();
	mSpecPos = 0;
	clearMemo();

	// insert current token into token tree (if exists)
	//if(mCurrentToken)
	//    insert(mCurrentToken);

	// advance to next recognizable token
	// read next char
	mCurrentToken = mLexer->nextChar();
}

void Parser::consume()
{
	advance(); // alias
}

void Parser::consume(std::string tokenValue)
{
	validate(tokenValue);
	advance();
}

void Parser::consume(int32_t tokenType)
{
	validate(tokenType);
	advance();
}

void Parser::consume(const std::regex &pattern)
{
	validate(pattern);
	advance();
}

void Parser::abrupt()
{
	std::string val = mCurrentToken ? " (" + mCurrentToken->value() + ")" : "";

	// error
	appendError("Encountered unexpected " + mLexer->getTokenName(mCurrentToken) + ".", mCurrentToken);
	abort();
}

void Parser::abrupt(lex_token erroneousToken)
{
	std::string name;
	if (!erroneousToken)
		name = "nil token";
	else
		name = mLexer->getTokenName(erroneousToken);

	appendError("Encountered unexpected token " + name + ".", erroneousToken);
	abort();
}

void Parser::appendError(std::string errorTxt, lex_token erroneousToken)
{
	mCompiler->appendError(errorTxt, erroneousToken);
}

void Parser::skip()
{
	consume();
}

void Parser::skip(std::string tokenValue)
{
	while (match(tokenValue))
		advance();
}

void Parser::skip(int32_t tokenType)
{
	while (match(tokenType))
		advance();
}

void Parser::skip(const std::regex &pattern)
{
	while (match(pattern))
		advance();
}

void Parser::advanceSkip(std::string tokenValue)
{
	advance(); // next
	skip(tokenValue);
}

void Parser::advanceSkip(int32_t tokenType)
{
	advance(); // next
	skip(tokenType);
}

void Parser::advanceSkip(const std::regex &pattern)
{
	advance(); // next
	skip(pattern);
}

void Parser::nextSkip(std::string tokenValue)
{
	advanceSkip(tokenValue); // alias
}

void Parser::nextSkip(int32_t tokenType)
{
	advanceSkip(tokenType);
}

void Parser::nextSkip(const std::regex &pattern)
{
	advanceSkip(pattern);
}

std::string Parser::tokenVal()
{
	return laVal(0); // current
}

int32_t Parser::tokenType()
{
	return laType(0); // current
}

std::string Parser::nextVal()
{
	return laVal(1); // next
}

int32_t Parser::nextType()
{
	return laType(1); // next
}

lex_token Parser::la(int32_t k)
{
	lex_token token = mCurrentToken;

	if (k < 0)
	{
		// find previous token
		token = mCurrentToken;

		while (token && k < 0)
		{
			token = token->prev(); // rewind

			if (token)
			{
				if (willIgnore(token->type()))
					continue; // skip

				k++;
			}
		}
	}
	else if (k > 0)
	{
		// find lookahead token la(k)
		if (k - 1 < mLookaheadBuffer.size())
		{
			int32_t i = 0;

			// lookahead already exists at zero based index
			for (lex_token tkn : mLookaheadBuffer)
				if (i++ == k - 1)
					return tkn;

			// fail
			return nullptr;
		}
		else
		{
			token = nullptr;				// default
			k = k - (int32_t)mLookaheadBuffer.size(); // deduct previously loaded tokens

			// populate lookhead buffer until la(k)
			while (k > 0 && mLexer->hasNext())
			{
				token = mLexer->nextToken();

				if (willIgnore(token))
					continue; // skip

				mLookaheadBuffer.push_back(token);
				k--;
			}
		}

		if (k > 0)
			token = nullptr; // fail
	}
	else
	{
		// k = 0
		return mCurrentToken;
	}

	return token;
}

lex_token Parser::laChar(int32_t k)
{
	return mLexer->lookChar(k);
}

std::string Parser::laVal(int32_t k)
{
	lex_token token = la(k);
	if (token)
		return token->value();
	return ""; // fail
}

int32_t Parser::laType(int32_t k)
{
	lex_token token = la(k);
	if (token)
		return token->type();
    return eof_tkn; // fail
}

bool Parser::tokenExists()
{
	return mCurrentToken != nullptr;
}

bool Parser::nextTokenExists()
{
	return la(1);
}

bool Parser::isEof()
{
    return mCurrentToken && mCurrentToken->type() == eof_tkn;
}

void Parser::ignore(int32_t tokenType)
{
	mIgnoredTokenTypes.push_back(tokenType);
}

bool Parser::match(std::string tokenValue, lex_token token)
{
	return token && token->value() == tokenValue;
}

bool Parser::match(std::string tokenValue, int32_t k)
{
	return match(tokenValue, la(k));
}

bool Parser::match(std::string tokenValue)
{
	return match(tokenValue, mCurrentToken);
}

bool Parser::match(int32_t tokenType, lex_token token)
{
	return token && token->type() == tokenType;
}

bool Parser::match(int32_t tokenType, int32_t k)
{
	return match(tokenType, la(k));
}

bool Parser::match(int32_t tokenType)
{
	return match(tokenType, mCurrentToken);
}

bool Parser::match(const std::regex &pattern, std::string value)
{
	return std::regex_match(value, pattern);
}

bool Parser::match(const std::regex &pattern, lex_token token)
{
	return token && std::regex_match(token->value(), pattern);
}

bool Parser::match(const std::regex &pattern, int32_t k)
{
	return match(pattern, la(k));
}

bool Parser::match(const std::regex &pattern)
{
	return match(pattern, mCurrentToken);
}

bool Parser::match(char ch, lex_token token)
{
	return match(std::string{1, ch}, token);
}

bool Parser::match(char ch, int32_t k)
{
	return match(ch, laChar(k));
}

bool Parser::match(char ch)
{
	return match(ch, laChar(0));
}

bool Parser::matchNext(std::string tokenValue)
{
	return match(tokenValue, 1);
}

bool Parser::matchNext(int32_t tokenType)
{
	return match(tokenType, 1);
}

bool Parser::matchNext(const std::regex &pattern)
{
	return match(pattern, 1);
}

bool Parser::matchNext(char ch)
{
	return match(ch, 1);
}

bool Parser::matchNext(std::string tokenValue, std::string skipTokenValue)
{
	int32_t k = 1; // next token
	while (match(skipTokenValue, k))
		k++;
	return match(tokenValue, k);
}

bool Parser::matchNext(int32_t tokenType, std::string skipTokenValue)
{
	int32_t k = 1; // next token
	while (match(skipTokenValue, k))
		k++;
	return match(tokenType, k);
}

bool Parser::matchNext(const std::regex &pattern, std::string skipTokenValue)
{
	int32_t k = 1; // next token
	while (match(skipTokenValue, k))
		k++;
	return match(pattern, k);
}

bool Parser::matchNext(std::string tokenValue, int32_t skipTokenType)
{
	int32_t k = 1; // next token
	while (match(skipTokenType, k))
		k++;
	return match(tokenValue, k);
}

bool Parser::matchNext(int32_t tokenType, int32_t skipTokenType)
{
	int32_t k = 1; // next token
	while (match(skipTokenType, k))
		k++;
	return match(tokenType, k);
}

bool Parser::matchNext(const std::regex &pattern, int32_t skipTokenType)
{
	int32_t k = 1; // next token
	while (match(skipTokenType, k))
		k++;
	return match(pattern, k);
}

bool Parser::matchNext(std::string tokenValue, const std::regex &skipTokenPattern)
{
	int32_t k = 1; // next token
	while (match(skipTokenPattern, k))
		k++;
	return match(tokenValue, k);
}

bool Parser::matchNext(int32_t tokenType, const std::regex &skipTokenPattern)
{
	int32_t k = 1; // next token
	while (match(skipTokenPattern, k))
		k++;
	return match(tokenType, k);
}

bool Parser::matchNext(const std::regex &pattern, const std::regex &skipTokenPattern)
{
	int32_t k = 1; // next token
	while (match(pattern, k))
		k++;
	return match(pattern, k);
}

void Parser::validate(std::string tokenValue)
{
	if (!match(tokenValue))
	{
		appendError("Expecting " + tokenValue + " but received " + mLexer->getTokenName(mCurrentToken), mCurrentToken);
		abort();
	}
}

void Parser::validate(int32_t tokenType)
{
	if (!match(tokenType))
	{
		appendError("Expecting " + mLexer->getTokenName(tokenType) + " but received " + mLexer->getTokenName(mCurrentToken), mCurrentToken);
		abort();
	}
}

void Parser::validate(const std::regex &pattern)
{
	if (!match(pattern))
	{
		appendError("Encountered unexpected " + mLexer->getTokenName(mCurrentToken) + ".", mCurrentToken);
		abort();
	}
}

void Parser::seek(int32_t k)
{
	mSpecPos = k;
}

int32_t Parser::mark()
{
	mMarkers.push_back(mSpecPos);
	return mSpecPos;
}

void Parser::release()
{
	if (!mMarkers.empty())
	{
		int32_t m = mMarkers.back();
		mMarkers.pop_back();
		seek(m);
	}
}

void Parser::memoize()
{
}

void Parser::clearMemo()
{
	// abstract
}

void Parser::specStart()
{
	mark();
}

bool Parser::specSuccess()
{
	mMarkers.pop_back(); // don't restore position to original 'k'
	return true;
}

bool Parser::specFail()
{
	release(); // restores original 'k'
	return false;
}

bool Parser::specMatch(std::string tokenValue)
{
	specStart();

	if (match(tokenValue, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Parser::specMatch(int32_t tokenType)
{
	specStart();

	if (match(tokenType, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Parser::specMatch(const std::regex &pattern)
{
	specStart();

	if (match(pattern, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Parser::specMatch(std::string tokenValue, std::string skipTokenValue)
{
	specSkip(skipTokenValue);
	return specMatch(tokenValue);
}

bool Parser::specMatch(std::string tokenValue, int32_t skipTokenType)
{
	specSkip(skipTokenType);
	return specMatch(tokenValue);
}

bool Parser::specMatch(std::string tokenValue, const std::regex &skipPattern)
{
	specSkip(skipPattern);
	return specMatch(tokenValue);
}

bool Parser::specMatch(char ch)
{
	specStart();

	if (match(ch, mSpecPos))
	{
		mSpecPos++;
		return specSuccess();
	}

	return specFail();
}

bool Parser::specExists()
{
	return la(mSpecPos) != nullptr;
}

void Parser::specUp()
{
	mSpecPos++;
}

void Parser::specDown()
{
	mSpecPos--;
}

std::string Parser::specVal()
{
	return laVal(mSpecPos);
}

int32_t Parser::specType()
{
	return laType(mSpecPos);
}

lex_token Parser::specSkip(std::string tokenValue)
{
	while (specMatch(tokenValue))
		;
	return la(mSpecPos);
}

lex_token Parser::specSkip(int32_t tokenType)
{
	while (specMatch(tokenType))
		;
	return la(mSpecPos);
}

lex_token Parser::specSkip(const std::regex &pattern)
{
	while (specMatch(pattern))
		;
	return la(mSpecPos);
}

void Parser::define(ast_symbol symbol)
{
	if (!_currentScope)
	{
		appendError("Attempted definition of symbol '" + symbol->name()->value() + "' outside of scope.", mCurrentToken);
		return;
	}
    
	_currentScope->define(symbol);
}

ast_symbol Parser::resolve(std::string name, ast_scope scopeToUse)
{
	if (!scopeToUse)
		scopeToUse = _currentScope;

	if (scopeToUse)
		return scopeToUse->resolve(name);

	return nullptr;
}

ast_scope Parser::pushScope(ast_scope scope)
{
	if (_currentScope)
		_currentScope->adopt(scope);

	_currentScope = scope;
	return scope;
}

ast_scope Parser::popScope()
{
	if (_currentScope)
	{
		ast_scope back = _currentScope->enclosingScope();
		_currentScope = back; // pop
		return back;
	}

	return nullptr;
}

void Parser::onParseInit()
{
	// abstract
}

void Parser::onParseComplete()
{
	// abstract
}

void Parser::onParseFailure()
{
	// abstract
}

void Parser::parse(Source *src)
{
	mLexer->load(src);
	reset();
	onParseInit();
	try
	{
		// parse until fatal error
		__parse();
	}
	catch (bad_parse_abort)
	{
		onParseFailure();
		return;
	}
	onParseComplete();
}

bool Parser::willIgnore(lex_token token) const
{
	return token ? willIgnore(token->type()) : false;
}

bool Parser::willIgnore(int32_t tokenType) const
{
	if (tokenType == eof_tkn)
		return false; // next ignore eof

	for (int32_t type : mIgnoredTokenTypes)
		if (tokenType == type)
			return true;

	return false;
}

} // namespace hydro
