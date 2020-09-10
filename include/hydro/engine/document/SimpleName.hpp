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

#ifndef __h3o_engine_SimpleName__
#define __h3o_engine_SimpleName__

#include "Name.hpp"

namespace hydro::engine
{
class SimpleName final : public Name
{
public:
    /**
     * Creates a SimpleName object using a token.
     */
    SimpleName(compiler::Token token);

    /**
     * Destroys the SimpleName object.
     */
    virtual ~SimpleName();

    /**
     * Accepts a visitor allowing the visitor to visit the simple name.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the value of the simple name.
     */
    virtual std::string getValue() const override { return mValue; }

    /**
     * Specifies whether or not that the SimpleName object is a simple name.
     * @return Always returns true.
     */
    virtual bool isSimpleName() const override { return true; }

    /**
     * Specifies whether or not the SimpleName object is a qualified name.
     * @return Always returns false.
     */
    virtual bool isQualifiedName() const override { return false; }

private:
    /**
     *
     */
    std::string mValue;
};

} // namespace hydro::engine

#endif /* __h3o_engine_SimpleName__ */
