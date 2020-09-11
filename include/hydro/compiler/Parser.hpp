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

#ifndef __h3o_internal_Parser__
#define __h3o_internal_Parser__

#include <list>
#include <vector>
#include <stack>

#include "Lexer.hpp"

namespace hydro::compiler {

/**
 * The binary_assoc represents the typical associativity used by binary operators.
 */
enum binary_assoc
{
    op_left_assoc,
    op_right_assoc
};

/**
 * The abstract Parser class provides various methods to assist in grammar parsing.
 */
class Parser
{
protected:

    /**
     * Creates a Parser object that owns a lexer.
     */
    Parser(Lexer* lexer);

public:
    
    /**
     * Destroys the Parser object.
     */
    virtual ~Parser();

    /**
     * Invokes internal parsing using an input source buffer. The lexer is used to tokenize the input for parsing.
     * @param input The instance of the SourceBuffer that will be parsed.
     */
    virtual void parse(SourceBuffer* input);

    /**
     * Specifies whether or not the current token is ignored by this parser.
     * @param token The token in which to check.
     * @return Returns true if the token is ignorable. Otherwise returns false.
     */
    bool willIgnore(Token token) const;

    /**
     * Specifies whether or not the specified token type is ignored by this parser.
     * @param tokenType The token type in which to check.
     * @return Returns true if the token type is ignorable. Otherwise returns false.
     */
    bool willIgnore(int32_t tokenType) const;

    /**
     * Gets the error reporter for this parser.
     * @return Returns the ErrorReporter instance that the parser uses to report errors.
     */
    ErrorReporter* getErrorReporter() const { return mErrorReporter; }

    /**
     * Gets the lexer that this parser users to tokenize input streams.
     * @return Returns the Lexer instance associated with the Parser object.
     */
    Lexer* getLexer() const { return mLexer; }

protected:
    struct TokenBuffer
    {
        std::list<Token> tokens;
    };
    
    /**
     * The error reporter used by this parser.
     */
    ErrorReporter* mErrorReporter;

    /**
     * The lexer that is responsible for tokenizing input for this parser.
     */
    Lexer* mLexer;

    /**
     * Specifies whether or not the parser is active.
     */
    bool mParsing;

    /**
     * The current token that the parser is currently processing.
     */
    Token mCurrentToken;

    /**
     * A list of tokens that have been cached by the parser and have already been processed.
     */
    std::vector<Token> mTokens;

    /**
     * Aborts the parse operation.
     */
    void abort();

    /**
     * Resets the parser in order to ensure the parser's resuse. This method may be overriden.
     */
    virtual void reset();

    /**
     * Inserts a token into the token cache.
     */
    void insert(Token token);

    /**
     * Pops the front of the lookahead buffer.
     */
    Token popLookaheadFront();

    /**
     * Pushes a token onto the lookahead buffer.
     */
    void pushLookahead(Token token);

    /**
     * Advances the parser to the next token supplied by the lexer. Ignores token types supplied to the ignore() method.
     */
    void advance();

    /**
     * Advances the parser n times. Works just like advance().
     * @param n The number of times the advance() method should be invoked.
     */
    void advance(uint32_t n);

    /**
     * 
     */
    void advanceChar();

    /**
     * 
     */
    void advanceChar(uint32_t n);

    /**
     * An alias to the advance() method.
     */
    void consume();

    /**
     * Advances the token if the token matches a particular value. Otherwise aborts.
     * @param tokenValue The token value in which to expect.
     */
    void consume(std::string tokenValue);

    /**
     * Advances the token if the token matches a particular token type. Otherwise aborts.
     * @param tokenType The token type in which to expect.
     */
    void consume(int32_t tokenType);

    /**
     * Advances the token if the token matches a particular pattern. Otherwise aborts.
     */
    void consume(const std::regex& pattern);

    /**
     * Causes an error to occur relating to the current token. This method should be called if the current token is unexpectantly encountered.
     * @param fatal If true tells the parser that the error should not be recovered from. Otherwise the parser is not aborted. The default value is true.
     */
    void abrupt(bool fatal = true);

    /**
     * Causes an error to occur relating to a given token. This method should be called if the given token is unexpectantly encountered.
     * @param erroneousToken The error in which to associate the error with.
     * @param fatal If true tells the parser that the error should not be recovered from. Otherwise the parser is not aborted. The default value is true.
     */
    void abrupt(Token erroneousToken, bool fatal = true);

    /**
     *
     */
    void abruptNext();

    /**
     *
     */
    void reportError(std::string errorText);

    /**
     *
     */
    void reportError(std::string errorText, Token erroneousToken);

    /**
     *
     */
    void reportWarning(std::string warningText);

    /**
     *
     */
    void reportWarning(std::string warningText, Token erroneousToken);

    /**
     *
     */
    void skip();

    /**
     *
     */
    void skip(std::string tokenValue);

    /**
     * 
     */
    void skip(int32_t tokenType);

    /**
     * 
     */
    void skip(const std::regex& pattern);

    /**
     * 
     */
    void advanceSkip(std::string tokenValue);

    /**
     * 
     */
    void advanceSkip(int32_t tokenType);

    /**
     * 
     */
    void advanceSkip(const std::regex& pattern);

    /**
     * 
     */
    std::string tokenVal();

    /**
     * 
     */
    int32_t tokenType();

    /**
     * 
     */
    std::string tokenName();

    /**
     * 
     */
    std::string nextVal();

    /**
     * 
     */
    int32_t nextType();

    /**
     * 
     */
    Token la(int32_t k);

    /**
     * 
     */
    Token laChar(int32_t k);

    /**
     * 
     */
    std::string laVal(int32_t k);

    /**
     * 
     */
    int32_t laType(int32_t k);

    /**
     * 
     */
    uint32_t laLine(int32_t k);

    /**
     * 
     */
    int32_t laIndex(int32_t k);

    /**
     * 
     */
    SourcePosition laPos(int32_t k);

    /**
     * 
     */
    bool lineDidChange(uint32_t line);

    /**
     * 
     */
    bool tokenExists();

    /**
     * 
     */
    bool nextTokenExists();

    /**
     * 
     */
    bool isEof();

    /**
     * 
     */
    void clearBuffer() { mLookaheadBuffer.clear(); }

    /**
     * 
     */
    void ignore(int32_t tokenType);

    /**
     * 
     */
    bool match(std::string tokenValue, Token token);

    /**
     * 
     */
    bool match(std::string tokenValue, int32_t k);

    /**
     * 
     */
    bool match(std::string tokenValue);

    /**
     * 
     */
    bool match(int32_t tokenType, Token token);

    /**
     * 
     */
    bool match(int32_t tokenType, int32_t k);

    /**
     * 
     */
    bool match(int32_t tokenType);

    /**
     * 
     */
    bool match(const std::regex& pattern, std::string value);

    /**
     * 
     */
    bool match(const std::regex& pattern, Token token);

    /**
     * 
     */
    bool match(const std::regex& pattern, int32_t k);

    /**
     * 
     */
    bool match(const std::regex& pattern);

    /**
     * 
     */
    bool match(char ch, Token token);

    /**
     * 
     */
    bool match(char ch, int32_t k);

    /**
     * 
     */
    bool match(char ch);

    /**
     * 
     */
    bool matchNext(std::string tokenValue);

    /**
     * 
     */
    bool matchNext(int32_t tokenType);

    /**
     * 
     */
    bool matchNext(const std::regex& pattern);

    /**
     * 
     */
    bool matchNext(std::string tokenValue, std::string skipTokenValue);

    /**
     * 
     */
    bool matchNext(char ch);

    /**
     * 
     */
    bool matchNext(int32_t tokenType, std::string skipTokenValue);

    /**
     * 
     */
    bool matchNext(const std::regex& pattern, std::string skipTokenValue);

    /**
     * 
     */
    bool matchNext(std::string tokenValue, int32_t skipTokenType);

    /**
     * 
     */
    bool matchNext(int32_t tokenType, int32_t skipTokenType);

    /**
     * 
     */
    bool matchNext(const std::regex& pattern, int32_t skipTokenType);

    /**
     * 
     */
    bool matchNext(std::string tokenValue, const std::regex& skipTokenPattern);

    /**
     * 
     */
    bool matchNext(int32_t tokenType, const std::regex& skipTokenPattern);

    /**
     * 
     */
    bool matchNext(const std::regex& pattern, const std::regex& skipTokenPattern);

    /**
     * 
     */
    void validate(std::string tokenValue);

    /**
     * 
     */
    void validate(int32_t tokenType);
    
    /**
     * 
     */
    void validate(const std::regex& pattern);

    /**
     * 
     */
    void seek(int32_t k);

    /**
     * 
     */
    int32_t mark();

    /**
     * 
     */
    void release();

    /**
     * 
     */
    void memoize();

    /**
     * 
     */
    virtual void clearMemo();

    /**
     * 
     */
    void specStart();

    /**
     * 
     */
    bool specSuccess();

    /**
     * 
     */
    bool specFail();

    /**
     * 
     */
    bool specMatch(std::string tokenValue);

    /**
     * 
     */
    bool specMatch(int32_t tokenType);

    /**
     * 
     */
    bool specMatch(const std::regex& pattern);

    /**
     * 
     */
    bool specMatch(std::string tokenValue, std::string skipTokenValue);

    /**
     * 
     */
    bool specMatch(std::string tokenValue, int32_t skipTokenType);

    /**
     * 
     */
    bool specMatch(std::string tokenValue, const std::regex& skipPattern);

    /**
     * 
     */
    bool specMatch(char ch);

    /**
     * 
     */
    bool specExists();

    /**
     * 
     */
    void specUp();

    /**
     * 
     */
    void specDown();

    /**
     * 
     */
    std::string specVal();

    /**
     * 
     */
    int32_t specType();

    /**
     * 
     */
    Token specSkip(std::string tokenValue);

    /**
     * 
     */
    Token specSkip(int32_t tokenType);

    /**
     * 
     */
    Token specSkip(const std::regex& pattern);
    
    /**
     * 
     */
    int32_t specPos() const { return mSpecPos; }

    /**
     * 
     */
    Token currentToken() { return la(0); }

    /**
     * 
     */
    uint32_t currentLine() { return laLine(0); }

    /**
     * 
     */
    SourcePosition currentPosition() { return laPos(0); }

    /**
     * 
     */
    virtual void parseDidInit();

    /**
     * 
     */
    virtual void sourceDidParse();

    /**
     * 
     */
    virtual void parseDidFail();

    /**
     * 
     */
    virtual void parseFromCurrentToken() = 0;

    /**
     * 
     */
    bool isSpeculating() const { return !mMarkers.empty(); }

    /**
     * 
     */
    int32_t getCurrentTokenIndex() const { return mIndex; }

private:

    /**
     * 
     */
    struct bad_parse_abort
    {
    };

    /**
     * A list of markers saved by a predictive parser during speculation.
     */
    std::vector<int32_t> mMarkers;

    /**
     * A list of token types that the parser should ignore when advancing tokens.
     */
    std::vector<int32_t> mIgnoredTokenTypes;

    /**
     * A buffer of lookahead tokens.
     */
    std::list<Token> mLookaheadBuffer;

    /**
     * 
     */
    bool laCharActive{ false };

    /**
     * 
     */
    int32_t mIndex; // current token index (TODO remove)

    /**
     * 
     */
    int32_t mSpecPos;

    /**
     * 
     */
    void __parse();
};

} // namespace hydro::compiler

#endif /* __h3o_internal_Parser__ */

