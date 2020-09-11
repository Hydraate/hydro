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

#include "SourcePrinter.hpp"

namespace hydro::compiler
{
static std::string removeTabs(std::string value)
{
    std::string cpy;

    for (char ch : value)
        if (ch == '\t')
            cpy += "    ";
        else
            cpy += ch;

    return cpy;
}

static uint32_t deduct(uint32_t a, uint32_t b)
{
    if (a > b)
        return a - b;
    return b - a;
}

SourcePrinter::SourcePrinter(SourceID source, Compiler *compiler, std::ostream &outputStream, bool consoleMode, uint32_t maxLineLength) : mSource{source}, mCompiler{compiler}, m_outputStream{outputStream}, m_consoleMode{consoleMode}, m_selectedLine{0}
{
    // init options
    showLineNumbers = true;
    useTerminalFormatting = true;
    maxErrorsPerLine = 0;
    useWordWrap = false;
    showErrors = true;
    showWarnings = true;
    underlineErrors = true;
    enableBreakpoints = false;
    showSourcePath = true;

    // padding and line length
    lineNumberPaddingLeft = 1;
    lineNumberPaddingRight = 1;
    contentPaddingLeft = 2;
    contentPaddingRight = 1;
    paddingTop = 1;
    paddingBottom = 1;
    lineLength = 120;
    messageSpacing = 3;
    startLine = endLine = 0;

    // normal formatting
    lineNumberFormat = terminal_format::txt256(245) + terminal_format::bg256(253);
    lineNumberSelectedFormat = terminal_format::txt256(238) + terminal_format::bg256(249);
    contentFormat = terminal_format::txt256(237) + terminal_format::bg256(15);
    contentSelectedFormat = terminal_format::txt256(232) + terminal_format::bg256(251);
    sourceFormat = terminal_format::txt256(250) + terminal_format::bg256(15);

    // warning formatting
    lineNumberWarningFormat = WHITE + terminal_format::bg256(220);
    contentWarningFormat = WHITE + terminal_format::bg256(220);

    // error formatting
    lineNumberErrorFormat = terminal_format::txt256(167) + terminal_format::bg256(217);
    contentErrorFormat = RED + terminal_format::bg256(224); //WHITE + terminal_format::bg256(1);

    // highlighted formatting

    // token formatting
    errorTokenFormat = BOLD + terminal_format::txt256(9) + terminal_format::bg256(210);
    warningTokenFormat = BOLD + WHITE + terminal_format::bg256(11);

    // message formatting
    errorMessageFormat = WHITE + terminal_format::bg256(9);

    // characters
    errorUnderline = '~';
    warningUnderline = '~';
    breakpoint = "•"[0];

    m_sourceInput = removeTabs(mCompiler->sourceManager()->getSourceContent(mSource));
    //m_maxLineLength = maxLineLength > 0 ? maxLineLength : getMaxLineLength(m_sourceInput);
    uint32_t nlines = countLines(m_sourceInput);

    // get all lines
    for (uint32_t line = 1; line <= nlines; line++)
        m_allLines.push_back(getLine(line));

    m_maxLineLength = computeMaxLineLength(m_allLines);

    ErrorReporter *errorReporter = mCompiler->errorReporter();
    uint32_t nerrors = mCompiler->errorReporter()->numErrors();

    // populate errors and warnings
    for (uint32_t i = 0; i < nerrors; i++)
    {
        if (errorReporter->position(i).source() == mSource)
        {
            if (errorReporter->isWarning(i))
                m_warnings.push_back(i); // is warning
            else
                mErrors.push_back(i); // is error
        }
    }

    m_ndigits = countDigits((uint32_t)m_allLines.size());
}

SourcePrinter::~SourcePrinter() {}

void SourcePrinter::write(std::string value)
{
    for (std::string x : {value})
    {
        m_output << x;
        //mmContents += x;
    }
}

void SourcePrinter::write(terminal_format format, std::string value)
{
    if (useTerminalFormatting && format)
        m_output << format;

    for (std::string x : {value})
    {
        m_output << x;
        //mmContents += x;
    }

    if (useTerminalFormatting && format)
        m_output << RESET;
}

void SourcePrinter::writeln(std::string value)
{
    for (std::string x : {value})
    {
        m_output << x;
        //mmContents += x;
    }

    m_output << std::endl;
}

void SourcePrinter::writeln(terminal_format format, std::string value)
{
    if (useTerminalFormatting && format)
        m_output << format;

    for (std::string x : {value})
    {
        m_output << x;
        //mmContents += x;
    }

    if (useTerminalFormatting && format)
        m_output << RESET;

    m_output << std::endl;
}

void SourcePrinter::writeSource()
{
    writeLines(m_allLines);
}

void SourcePrinter::writeSource(uint32_t startLine, uint32_t endLine)
{
    std::list<Line> lines;

    for (Line line : m_allLines)
    {
        if (
            ((startLine == 0) || (line.number() >= startLine)) &&
            ((endLine == 0) || (line.number() <= endLine)))
            lines.push_back(line);
    }

    writeLines(lines);
}

void SourcePrinter::writeSource(uint32_t lineNumber, uint32_t linesBefore, uint32_t linesAfter)
{
    std::list<Line> lines;

    if (lineNumber > 0 && lineNumber <= m_allLines.size())
    {
        int before = lineNumber - linesBefore, after = lineNumber + linesAfter;

        if (before < 1)
            before = 1;
        if (after > m_allLines.size())
            after = (int)m_allLines.size();

        for (Line line : m_allLines)
        {
            if (line.number() >= before && line.number() <= after)
                lines.push_back(line);
        }
    }

    writeLines(lines);
}

void SourcePrinter::highlight(uint32_t line)
{
    Line l = getLine(line);
    if (line)
        m_highlights.push_back(l);
}

void SourcePrinter::clearHighlight(uint32_t line)
{
}

void SourcePrinter::clearConsole()
{
    if (!m_consoleMode || mmContents.empty())
        return;

    m_outputStream << "\u001b[1000D\u001b[" << std::to_string(mmContents.length()) + "A";
    m_outputStream << fill((uint32_t)mmContents.length(), ' ');

    mmContents = ""; // clear
}

void SourcePrinter::updateConsole()
{
    if (!m_consoleMode)
        return;
}

void SourcePrinter::terminate()
{
    if (!m_consoleMode)
        return;
}

void SourcePrinter::print()
{
    flush();
}

void SourcePrinter::selectNextLine()
{
    if (m_selectedLine + 1 <= m_allLines.size())
        m_selectedLine++;
    else
        m_selectedLine = 0; // nullify
}

void SourcePrinter::selectNextLine(bool loop)
{
    if (m_selectedLine + 1 <= m_allLines.size())
        m_selectedLine++;
    else if (loop && !m_allLines.empty())
        m_selectedLine = 1; // reset
    else
        m_selectedLine = 0; // nullify
}

void SourcePrinter::selectPrevLine()
{
    if (m_selectedLine > 0 && m_selectedLine - 1 > 0)
        m_selectedLine--;
    else
        m_selectedLine = 0; // nullify
}

void SourcePrinter::selectPrevLine(bool loop)
{
    if (m_selectedLine > 0 && m_selectedLine - 1 > 0)
        m_selectedLine--;
    else if (loop && !m_allLines.empty())
        m_selectedLine = (uint32_t)m_allLines.size(); // start back
    else
        m_selectedLine = 0; // nullify
}

void SourcePrinter::flush()
{
    mmContents = m_output.str();
    m_outputStream << mmContents;
    m_output = std::stringstream{}; // reset
}

bool SourcePrinter::hasHighlight(const Line &line)
{
    for (Line h : m_highlights)
        if (h == line)
            return true;
    return false;
}

bool SourcePrinter::hasError(const Line &line)
{
    ErrorReporter *errorReporter = mCompiler->errorReporter();
    for (uint32_t index : mErrors)
        if (errorReporter->position(index).line() == line.number())
            return errorReporter->isError(index);
    return false;
}

bool SourcePrinter::hasWarning(const Line &line)
{
    ErrorReporter *errorReporter = mCompiler->errorReporter();
    for (uint32_t index : mErrors)
        if (errorReporter->position(index).line() == line.number())
            return errorReporter->isWarning(index);
    return false;
}

std::size_t SourcePrinter::getErrorAndWarningPositions(const Line &line, std::list<SourcePosition> &positions)
{
    ErrorReporter *errorReporter = mCompiler->errorReporter();
    std::size_t nerrors = 0;

    // get errors first
    for (int i : mErrors)
    {
        SourcePosition pos = errorReporter->position(i);
        if (pos.line() == line.number())
        {
            positions.push_back(pos);
            nerrors++;
        }
    }

    // get warnings last
    for (int i : m_warnings)
    {
        SourcePosition pos = errorReporter->position(i);
        if (pos.line() == line.number())
            positions.push_back(pos);
    }

    return nerrors;
}

void SourcePrinter::writeLines(std::list<Line> &lines)
{
    uint32_t maxLineLength = computeMaxLineLength(lines);

    if (showSourcePath)
        writeSourcePath(maxLineLength);

    // top padding
    for (int i = showSourcePath ? 1 : 0; i < paddingTop; i++)
        writeBlankLine(maxLineLength);

    // content
    for (Line line : lines)
    {
        writeLineNumber(line);
        writeContent(line, maxLineLength);
    }

    // bottom padding
    for (int i = 0; i < paddingBottom; i++)
        writeBlankLine(maxLineLength);
}

std::string SourcePrinter::padLineNumber(const Line &line)
{
    return fill(lineNumberPaddingLeft) + fill(m_ndigits - countDigits(line.number())) + std::to_string(line.number()) + fill(lineNumberPaddingRight);
}

std::string SourcePrinter::padContent(const Line &line, uint32_t maxLineLength)
{
    std::string content = line.content();
    return fill(contentPaddingLeft) + content + fill(deduct(maxLineLength, (uint32_t)content.length())) + fill(contentPaddingRight);
}

void SourcePrinter::writeSourcePath(uint32_t maxLineLength)
{
    std::string path = mSource.path();
    if (path.length() > maxLineLength)
    {
        // truncate path front
        auto amt = path.length() - maxLineLength + 3; // minus 3 for ellipsis
        path = "..." + path.substr(amt < path.length() ? amt : path.length() - 1);
    }

    writeLineNumber();
    writeln(sourceFormat ? sourceFormat : contentFormat, fill(contentPaddingLeft) + path + fill(deduct(maxLineLength, (uint32_t)path.length())) + fill(contentPaddingRight));
}

void SourcePrinter::writeBlankLine(uint32_t maxLineLength)
{
    writeLineNumber();
    writeln(contentFormat, fill(contentPaddingLeft + maxLineLength + contentPaddingRight));
}

void SourcePrinter::writeLineNumber()
{
    write(lineNumberFormat, fill(lineNumberPaddingRight + m_ndigits + lineNumberPaddingRight));
}

void SourcePrinter::writeLineNumber(const Line &line)
{
    if (!showLineNumbers)
        return;
    write(getLineNumberFormat(line), padLineNumber(line));
}

void SourcePrinter::writeContent(const Line &line, uint32_t maxLineLength)
{
    //ErrorReporter *errorReporter = mCompiler->errorReporter();
    terminal_format mainFormat = getContentFormat(line);

    if ((showErrors && hasError(line)) || (showWarnings && hasWarning(line)))
    {
        // write erroneous line
        write(mainFormat, fill(contentPaddingLeft));
        std::list<SourcePosition> positions;
        std::size_t nerrors = getErrorAndWarningPositions(line, positions);
        std::string buffer;
        std::size_t n = line.content().length();
        auto it = positions.begin();
        terminal_format tokenFormat, errorFormat = getErrorTokenFormat(line), warningFormat = getWarningTokenFormat(line);
        if (!errorFormat)
            errorFormat = mainFormat;
        if (!warningFormat)
            warningFormat = mainFormat;
        for (std::size_t i = 0; i < n; i++)
        {
            char ch = line.content()[i];

            if (it != positions.end())
            {
                // write buffer for tokens
                if (i >= it->indexOnLine() && i < it->indexOnLine() + it->length())
                {
                    if (i == it->indexOnLine())
                    {
                        // is starting index so init format
                        if (nerrors > 0)
                            tokenFormat = errorFormat;
                        else
                            tokenFormat = warningFormat;

                        if (!buffer.empty())
                        {
                            // flush buffer
                            write(mainFormat, buffer);
                            buffer = "";
                        }
                    }

                    buffer += ch;

                    // if is last index of token
                    if (i == it->indexOnLine() + it->length() - 1)
                    {
                        it++;
                        if (nerrors > 0)
                            nerrors--;

                        // flush buffer
                        write(tokenFormat, buffer);
                        buffer = "";
                    }
                }
                else
                {
                    // write buffer for all other content
                    buffer += ch;
                }
            }
            else // write buffer for content that trails erroneous tokens
                buffer += ch;
        }

        if (!buffer.empty())
        {
            // flush buffer
            write(mainFormat, buffer);
        }

        write(mainFormat, fill(deduct(maxLineLength, (uint32_t)line.content().length()) + contentPaddingRight));
        writeln(""); //writeln(errorMessageFormat, errorReporter->errorText(positions.front()));

        buffer = "";
    }
    else
        writeln(mainFormat, padContent(line, maxLineLength));
}

Line SourcePrinter::getLine(uint32_t lineNumber)
{
    return Line{lineNumber, removeTabs(mCompiler->sourceManager()->getLineFromSource(mSource, lineNumber))};
}

terminal_format SourcePrinter::getLineNumberFormat(const Line &line)
{
    if (line.number() == m_selectedLine)
        return lineNumberSelectedFormat;
    else if (hasHighlight(line))
        return lineNumberHighlightFormat;
    else if (hasError(line))
        return lineNumberErrorFormat;
    else if (hasWarning(line))
        return lineNumberWarningFormat;
    return lineNumberFormat;
}

terminal_format SourcePrinter::getContentFormat(const Line &line)
{
    if (line.number() == m_selectedLine)
    {
        if (hasHighlight(line))
            return contentSelectedHightlightFormat;
        else if (hasError(line))
            return contentSelectedErrorFormat;
        else if (hasWarning(line))
            return contentSelectedWarningFormat;
        return contentSelectedFormat;
    }
    else if (hasHighlight(line))
        return contentHighlightFormat;
    else if (hasError(line))
        return contentErrorFormat;
    else if (hasWarning(line))
        return contentWarningFormat;
    return contentFormat;
}

terminal_format SourcePrinter::getErrorTokenFormat(const Line &line)
{
    if (line.number() == m_selectedLine)
    {
        if (hasHighlight(line))
            ;
        else if (hasError(line))
            ;
        else if (hasWarning(line))
            ;
        return errorTokenSelectedFormat;
    }
    else if (hasHighlight(line))
        ;
    else if (hasError(line))
        ;
    else if (hasWarning(line))
        ;
    return errorTokenFormat;
}

terminal_format SourcePrinter::getWarningTokenFormat(const Line &line)
{
    if (line.number() == m_selectedLine)
    {
        if (hasHighlight(line))
            ;
        else if (hasError(line))
            ;
        else if (hasWarning(line))
            ;
        return warningTokenSelectedFormat;
    }
    else if (hasHighlight(line))
        ;
    else if (hasError(line))
        ;
    else if (hasWarning(line))
        ;
    return warningTokenFormat;
}

uint32_t SourcePrinter::computeMaxLineLength(std::list<Line> &lines)
{
    //ErrorReporter *errorReporter = mCompiler->errorReporter();
    uint32_t max = 0, len = 0;

    for (Line line : lines)
    {
        //std::list<tposition_t> positions;
        //std::size_t nerrors = getErrorAndWarningPositions(line, positions);
        /*
        if(nerrors > 0 || showWarnings)
        {
            // length is the length of content on the line plus the first error message
            std::string lineContentWithMessage = line.content() + fill(messageSpacing) + errorReporter->errorText(positions.front());
            len = (uint32_t)lineContentWithMessage.length();
        }
        else
        {*/
        // length is equal to length of content on the line
        len = (uint32_t)line.content().length();
        //}

        // compare
        if (len > max)
            max = len;
    }

    if (max < SRC_PRINTER_MINmLine_LENGTH)
        max = SRC_PRINTER_MINmLine_LENGTH;

    return max;
}

std::string SourcePrinter::fill(uint32_t size, char pad)
{
    std::string result;
    for (uint32_t i = 0; i < size; i++)
        result += pad;
    return result;
}

uint32_t SourcePrinter::countDigits(uint32_t n)
{
    uint32_t count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

uint32_t SourcePrinter::countLines(std::string value)
{
    uint32_t lines = 1;

    for (char ch : value)
        if (ch == '\n')
            lines++;

    return lines;
}

} // namespace hydro::compiler
