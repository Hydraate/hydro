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

#ifndef __h3o_line_t__
#define __h3o_line_t__

#include <memory>
#include <string>

namespace hydro::compiler
{
/**
 *
 */
enum compilation_status : uint8_t
{
    normal_status,
    error_status,
    warning_status
};

/**
 *
 */
class Line final
{
public:
    /**
     *
     */
    Line();

    /**
     *
     */
    Line(uint32_t lineNumber, std::string lineContent, compilation_status status = normal_status);

    /**
     *
     */
    Line(const Line& line);

    /**
     *
     */
    Line(Line&& line);

    /**
     * Destroys the Line object.
     */
    ~Line();

    /**
     *
     */
    bool isNil() const { return mContent == nullptr; }

    /**
     *
     */
    uint32_t number() const { return mContent ? mContent->lineNumber : 0; }

    /**
     *
     */
    std::string content() const { return mContent ? mContent->lineContent : ""; }

    /**
     *
     */
    bool isError() const { return mContent ? mContent->status == error_status : false; }

    /**
     *
     */
    bool isWarning() const { return mContent ? mContent->status == warning_status : false; }

    /**
     *
     */
    bool lineIsEmpty() const
    {
        return mContent ? mContent->lineContent.empty() : true;
    }

    /**
     *
     */
    operator bool() const { return mContent != nullptr; }

    /**
     *
     */
    bool operator!() const { return mContent == nullptr; }

    /**
     *
     */
    Line& operator=(const Line& rhs);

    /**
     *
     */
    Line& operator=(Line&& rhs);

private:
    /**
     *
     */
    struct line_data
    {
        /**
         *
         */
        uint32_t lineNumber;

        /**
         *
         */
        std::string lineContent;

        /**
         *
         */
        compilation_status status;
    };

    /**
     *
     */
    std::shared_ptr<line_data> mContent;
};

} // namespace hydro::compiler

#endif /* __h3o_line_t__ */
