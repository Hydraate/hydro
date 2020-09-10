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

#ifndef __h3o_engine_Node__
#define __h3o_engine_Node__

#include <list>

#include "../../compiler/Token.hpp"

#include "DocumentVisitor.hpp"

namespace hydro::engine
{

class Document;

/**
 * The abstract Node class is the base class of all nodes.
 */
class Node
{
protected:
    /**
     * Creates a Node object that is a root node.
     */
    Node();

    /**
     * Creates a Node object with a token that is uniquely assigned to the node.
     */
    Node(compiler::Token token);

public:
    /**
     * Destroys the Node object.
     */
    virtual ~Node();
    
    /**
     * Accepts a visitor allowing the visitor to visit this node.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) {}

    /**
     * Gets the token bound to this node.
     * @return Returns the token property. The token will be nil if not explicitly set.
     */
    compiler::Token getToken() const { return mToken; }
    
    /**
     * Binds a token to this node.
     * @param token The token to bind to the node.
     */
    void setToken(compiler::Token token) { mToken = token; }
    
    /**
     * Gets the source position for this node.
     */
    virtual compiler::SourcePosition getSourcePosition() const { return !mToken.isNil() ? mToken.pos() : compiler::SourcePosition{}; }
    
    /**
     * Gets the document that created and owns this node.
     * @return Returns the Document instance that owns this node.
     */
    Document *getDocument() const { return mDocument; }

protected:
    /**
     * The token that is assigned to this node. Normally a node will have zero or one token and a token will be assigned to one and only one node.
     */
    compiler::Token mToken;
    
    /**
     * The document that owns this node.
     */
    Document *mDocument;
    
    friend class Document;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Node__ */
