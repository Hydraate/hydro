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

namespace hydro::compiler
{

Lexer::Lexer() : Lexer{nullptr}
{    
}

    Lexer::Lexer(ErrorReporter *errorReporter)
    {
        mErrorReporter = errorReporter;
        mInput = nullptr;

        // init
        unload();

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
        registerTokenName("£", "pound sign");
        registerTokenName("¢", "cent sign");
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
        registerTokenName("‘", "apostrophe");
        registerTokenName("‹", "left double pointing angle quotation mark");
        registerTokenName("›", "right double pointing angle quotation mark");
        registerTokenName("«", "left double pointing angle quotation mark");
        registerTokenName("»", "right double pointing angle quotation mark");
        registerTokenName("å", "å");
        registerTokenName("ß", "theta");
        registerTokenName("∂", "dabba (currly d)");
        registerTokenName("ƒ", "florin sign");
        registerTokenName("˙", "dot above");
        registerTokenName("∆", "delta");
        registerTokenName("˚", "ring above");
        registerTokenName("¬", "negation symbol");
        registerTokenName("…", "horizontal ellipsis");
        registerTokenName("æ", "æ");
        registerTokenName("Ω", "omega");
        registerTokenName("≈", "approximately symbol");
        registerTokenName("ç", "cedilla");
        registerTokenName("√", "square root");
        registerTokenName("∫", "integral sign");
        registerTokenName("˜", "small tilde");
        registerTokenName("µ", "mu");
        registerTokenName("≤", "less than or equal sign");
        registerTokenName("≥", "greater than or equal sign");
        registerTokenName("÷", "division sign");
        registerTokenName("⁄", "fraction slash");
        registerTokenName("€", "euro sign");
        registerTokenName("ﬁ", "ﬁ");
        registerTokenName("‡", "dagger");
        registerTokenName("°", "degree symbol");
        registerTokenName("·", "dot");

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
        registerTokenName(tab_tkn, "tab");
        registerTokenName(identity_tkn, "identity");
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

    void Lexer::load(SourceBuffer *input)
    {
        unload();
        mInput = input;
    }

    bool Lexer::hasNext() const
    {
        return mPos + 1 < mContent.length() || mInput->hasNext();
    }

    Token Lexer::nextToken()
    {
        if (hasNext())
        {
            Token token = readNext();

            if (token)
                return token;
        }

        return Token();
    }

    Token Lexer::nextToken(int32_t pos)
    {
        if (pos >= mContent.length())
            while (pos >= mContent.length() && hasNext())
                readChar();

        mPos = pos;
        mTokenPos = -1; // reset token position
        mBuffer = "";   // clear buffer
        specReset();
        mLine = computeLineNumberAtPosition(pos);
        return nextToken();
    }

    Token Lexer::nextChar()
    {
        // TODO deprecate nextChar when state transitions are added
        if (hasNext())
        {
            consume();               // eat next character
            mCurrentToken = flush(token_tkn); // make token
            return mCurrentToken;
        }

        return NilToken;
    }

    Token Lexer::nextChar(int32_t pos)
    {
        mPos = pos;
        return nextChar();
    }

    Token Lexer::charAt(int32_t index)
    {
        if (mPos >= 0)
        {
            SourcePosition pos{
                mInput->getSourceID(),
                index,
                mPos,
                mLine,
                1};
            if (index < mContent.length())
                return Token{pos, std::string{1, mContent[index]}, token_tkn};
        }

        // out of bounds
        return nullptr;
    }

    Token Lexer::lookChar(int32_t k)
    {
        int32_t index = mPos + k;

        if (index >= 0 && index < mContent.length())
        {
            // using cache
            return Token{generatePosition(index, 1), std::string{1, mContent[index]}, token_tkn};
        }
        else
        {
            // lookahead
            k = index - k;
            while (hasNext() && (k-- > 0))
                readChar(); // populate cache

            if (k == 0)
                return Token{generatePosition(index, 1), std::string{1, mContent[index]}, token_tkn};
        }

        // out of bounds
        return Token{generatePosition(index, 1), std::string{1, EOF}, eof_tkn};
    }

    std::string Lexer::getTokenName(Token token)
    {
        if (!token)
            return "nil token";

        TokenInfo *info = findTokenName(token.value());

        if (!info)
            info = findTokenName(token.type());

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

    char Lexer::la(int32_t k)
    {
        int32_t index = mPos + k;

        if (index < 0)
            return '\0'; // out of bounds

        if (k > 0 && index >= mContent.length())
        {
            while (k-- > 0 && mInput->hasNext())
                readChar();
        }

        if (index < mContent.length())
            return mContent[index];

        // fail
        return '\0';
    }

    Token Lexer::flush(int32_t tokenType)
    {
        Token token = Token{getCurrentPosition(), mBuffer, tokenType};
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

    void Lexer::reportError(std::string errorTxt)
    {
        if(mErrorReporter)mErrorReporter->reportError(errorTxt, getCurrentPosition());
    }

    void Lexer::reportWarning(std::string warningText)
    {
        if(mErrorReporter)
            mErrorReporter->reportWarning(warningText, getCurrentPosition());
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

    Token Lexer::devour(int32_t registeredTokenType)
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

    void Lexer::specReset()
    {
        mSpecBuffer = "";
        mSpecPos = 1; // la(1)
        mMarkers.clear();
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
        if (mInput && mInput->hasNext())
        {
            char ch = mInput->nextChar();
            mContent += ch;
            return ch;
        }

        // fail
        return '\0';
    }

    void Lexer::advance()
    {
        mPos++;
        mTokenPos++;
        if (currentChar() == '\n')
        {
            mLine++;
            mTokenPos = -1;
        }
        specReset();
    }

    void Lexer::advance(uint32_t n)
    {
        while (n-- > 0)
            advance();
    }

    void Lexer::consume()
    {
        if (!mInput)
            return;
        advance();
        mBuffer += currentChar();
    }

    void Lexer::consume(uint32_t n)
    {
        while (n-- > 0)
            consume();
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

    SourcePosition Lexer::getCurrentPosition()
    {
        if (mBuffer.empty())
            return nullptr;
        uint32_t len = (uint32_t)mBuffer.length();
        int32_t pos = mPos - len + 1;
        return SourcePosition{mInput->getSourceID(), computeIndexOnLineAtPosition(pos), pos, mLine, len};
    }

    SourcePosition Lexer::generatePosition(int32_t pos, uint32_t length)
    {
        return SourcePosition{
            mInput->getSourceID(),
            computeIndexOnLineAtPosition(pos),
            pos,
            computeLineNumberAtPosition(pos),
            length};
    }

    uint32_t Lexer::computeLineNumberAtPosition(int32_t index)
    {
        if (index >= mContent.length())
            return 0; // cannot be determined from cache

        uint32_t line = 1;

        for (char ch : mContent)
        {
            if (ch == '\n')
                line++;
            index--;
            if (index < 0)
                break;
        }

        return line;
    }

    int32_t Lexer::computeIndexOnLineAtPosition(int32_t pos)
    {
        if (pos >= mContent.length())
            return -1; // error! out of bounds
        int32_t lineIndex = -1;
        char ch;

        for (int32_t i = 0; i <= pos; i++)
        {
            ch = mContent[i];
            if (ch == '\n')
                lineIndex = -1;
            else
                lineIndex++;
        }

        return lineIndex;
    }

    void Lexer::unload()
    {
        mCurrentToken = mEofToken = nullptr;
        mBuffer = mSpecBuffer = "";
        mSpecPos = 1; // la(1)
        mMarkers.clear();
        mTokenPos = mPos = -1;
        delete mInput;
        mInput = nullptr;
        mContent = "";
        mLine = 1;
    }

} // namespace hydro::compiler
