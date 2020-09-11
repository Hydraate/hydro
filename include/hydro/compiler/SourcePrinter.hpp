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

#ifndef __h3o_SourceOutput__
#define __h3o_SourceOutput__

#define SRC_PRINTER_MINmLine_LENGTH 32

#include <iostream>
#include <list>
#include <sstream>

#include "../utility/terminal_format.hpp"
#include "Compiler.hpp"
#include "Line.hpp"

namespace hydro::compiler
{
class SourcePrinter
{
public:
    bool
        showLineNumbers,
        useTerminalFormatting,
        useWordWrap,
        showErrors,
        showWarnings,
        underlineErrors,
        underlineWarnings,
        enableBreakpoints,
        showSourcePath;
    uint32_t
        maxErrorsPerLine,
        lineNumberPaddingLeft,
        lineNumberPaddingRight,
        contentPaddingLeft,
        contentPaddingRight,
        paddingTop,
        paddingBottom,
        lineLength,
        messageSpacing,
        startLine,
        endLine;
    terminal_format
        lineNumberFormat,
        lineNumberWarningFormat,
        lineNumberErrorFormat,
        lineNumberHighlightFormat,
        lineNumberSelectedFormat,
        lineNumberSelectedWarningFormat,
        lineNumberSelectedErrorFormat,
        lineNumberSelectedHighlightFormat,
        contentFormat,
        contentWarningFormat,
        contentErrorFormat,
        contentHighlightFormat,
        contentSelectedFormat,
        contentSelectedWarningFormat,
        contentSelectedErrorFormat,
        contentSelectedHightlightFormat,
        errorTokenFormat,
        errorTokenSelectedFormat,
        warningTokenFormat,
        warningTokenSelectedFormat,
        sourceFormat,
        errorMessageFormat,
        warningMessageFormat;
    char32_t
        errorUnderline,
        warningUnderline,
        breakpoint;
    SourcePrinter(SourceID source, Compiler *compiler, std::ostream &outputStream, bool consoleMode = false, uint32_t maxLineLength = 0);
    virtual ~SourcePrinter();
    void write(std::string value);
    void write(terminal_format format, std::string value);
    void writeln(std::string value);
    void writeln(terminal_format format, std::string value);
    void writeSource();
    void writeSource(uint32_t startLine, uint32_t endLine);
    void writeSource(uint32_t lineNumber, uint32_t linesBefore, uint32_t linesAfter);
    void highlight(uint32_t line);
    void clearHighlight(uint32_t line);
    void clearConsole();
    void updateConsole();
    void terminate();
    void print();
    void selectNextLine();
    void selectNextLine(bool loop);
    void selectPrevLine();
    void selectPrevLine(bool loop);
    uint32_t numLinesInSource() const { return (uint32_t)m_allLines.size(); }
    uint32_t numLinesInOutput() const { return countLines(m_output.str()); }
    SourceID source() const { return mSource; }
    Compiler *getCompiler() const { return mCompiler; }
    std::string contents() const { return mmContents; }
    bool consoleMode() const { return m_consoleMode; }
    uint32_t selectedLine() const { return m_selectedLine; }
    void selectedLine(uint32_t lineNumber) { m_selectedLine = lineNumber; }
    uint32_t maxLineLength() const { return m_maxLineLength; }
    std::string content() const { return m_sourceInput; }

protected:
    SourceID mSource;
    Compiler *mCompiler;
    std::ostream &m_outputStream;
    std::stringstream m_output;
    std::string m_sourceInput, mmContents;
    std::list<Line> m_allLines;
    std::list<Line> m_highlights;
    std::list<Line> m_breakPoints;
    std::list<uint32_t> mErrors;
    std::list<uint32_t> m_warnings;
    uint32_t m_ndigits, m_maxLineLength, m_selectedLine;
    bool m_consoleMode;

    void flush();
    bool hasHighlight(const Line &line);
    bool hasError(const Line &line);
    bool hasWarning(const Line &line);
    std::size_t getErrorAndWarningPositions(const Line &line, std::list<SourcePosition> &positions);
    void writeLines(std::list<Line> &lines);
    std::string padLineNumber(const Line &line);
    std::string padContent(const Line &line, uint32_t maxLineLength);
    void writeSourcePath(uint32_t maxLineLength);
    void writeBlankLine(uint32_t maxLineLength);
    void writeLineNumber();
    void writeLineNumber(const Line &line);
    void writeContent(const Line &line, uint32_t maxLineLength);
    Line getLine(uint32_t lineNumber);
    terminal_format getLineNumberFormat(const Line &line);
    terminal_format getContentFormat(const Line &line);
    terminal_format getErrorTokenFormat(const Line &line);
    terminal_format getWarningTokenFormat(const Line &line);
    uint32_t computeMaxLineLength(std::list<Line> &lines);

    static std::string fill(uint32_t size, char pad = ' ');
    static uint32_t countDigits(uint32_t n);
    static uint32_t countLines(std::string value);
    static std::string fillContent(std::string content, uint32_t maxLength);
};

} // namespace hydro::compiler

#endif /* __h3o_SourceOutput__ */
