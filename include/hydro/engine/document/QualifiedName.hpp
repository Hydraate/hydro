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

#ifndef __h3o_engine_QualifiedName__
#define __h3o_engine_QualifiedName__

#include "SimpleName.hpp"

namespace hydro::engine
{
/**
 * The QualifiedName class binds a name qualifier to a simple name to form a qualified name. A qualified name prefixes a simple name in order to make the simple name distinctive from similar names or to show that a name belongs to a particular domain such as "com.example.MyName".
 */
class QualifiedName final : public Name
{
public:
    /**
     * Creates a QualifiedName object.
     * @param qualifier The name qualifier in which to bind to a simple name.
     * @param token The token.
     * @param name The simple name that will be bound to the qualifer.
     */
    QualifiedName(Name *qualifier, compiler::Token token, SimpleName *name);

    /**
     * Destroys the QualifiedName object.
     */
    virtual ~QualifiedName();

    /**
     * Accepts a visitor allowing the visitor to visit the qualified name.
     * @param visitor The visitor to accept.
     */
    //virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Gets the value of the qualified name.
     * @return Returns the value of the qualified name as a string.
     */
    virtual std::string getValue() const override;

    /**
     * Specifies whether or not the QualifiedName object is a simple name.
     * @return Always returns false.
     */
    virtual bool isSimpleName() const override { return false; }

    /**
     * Specifies whether or not the QualifiedName object is a qualified name.
     * @return Always returns true.
     */
    virtual bool isQualifiedName() const override { return true; }

    /**
     * Gets the name qualifier for the qualified name.
     * @return Returns a simple name or qualified name.
     */
    Name *getQualifier() const { return mQualifier; }

    /**
     * Gets the name segment of the qualified name.
     * @return Returns a simple name.
     */
    SimpleName *getName() const { return mName; }

private:
    /**
     * The name qualifier in which to bind.
     */
    Name *mQualifier;

    /**
     * The simple name in which to bind a qualifier to.
     */
    SimpleName *mName;
};

} // namespace hydro::engine

#endif /* __h3o_engine_QualifiedName__ */
