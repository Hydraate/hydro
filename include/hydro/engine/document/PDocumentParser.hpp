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

#ifndef __h3o_engine_PDocumentParser__
#define __h3o_engine_PDocumentParser__

#include <stack>
#include <vector>

#include "../../compiler/Parser.hpp"

#include "Document.hpp"
#include "PDocumentLexer.hpp"
#include "Resolver.hpp"

namespace hydro::engine
{
/**
 * The PDocumentParser class parses documents that describe interactive content.
 */
class PDocumentParser : public compiler::Parser
{
public:
    /**
     * The PDocumentParser::node_stack_empty structure is thrown if an unexpected empty node stack is encountered.
     */
    struct node_stack_empty
    {
    };

    /**
     * Creates an PDocumentParser object that sends errors to an error reporter module.
     */
    PDocumentParser(compiler::ErrorReporter *errorReporter);

    /**
     * Destroys the PDocumentParser object.
     */
    virtual ~PDocumentParser();

    /**
     * Determines the opening delimiter of the given entity.
     * @param entity The given entity.
     * @return Returns the opening delimiter of the given entity as a string.
     */
    static std::string getEntityOpeningDelimiter(Entity *entity)
    {
        if(dynamic_cast<Element *>(entity))
            return "[";
        else if(dynamic_cast<Procedure *>(entity))
            return "<";
        else if(dynamic_cast<Snapshot *>(entity))
            return "{";
        else if(dynamic_cast<Action *>(entity))
            return "(";
        return "";
    }
    
    /**
     * Determines the clsoing delimiter of the given entity.
     * @param entity The given entity.
     * @return Returns the closing delimiter of the given entity as a string.
     */
    static std::string getEntityClosingDelimiter(Entity *entity)
    {
        if(dynamic_cast<Element *>(entity))
            return "]";
        else if(dynamic_cast<Procedure *>(entity))
            return ">";
        else if(dynamic_cast<Snapshot *>(entity))
            return "}";
        else if(dynamic_cast<Action *>(entity))
            return ")";
        return "";
    }
    
    /**
     * Gets the "ignoreExtraneousTabs" property.
     * @return Returns true if the parser ignore extraneous tabs. Otherwise returns false. The default value is false.
     */
    bool getIgnoreExtraneousTabs() const { return mIgnoreExtraneousTabs; }

    /**
     * Sets the "ignoreExtraneousTabs" property. If true the parser will not result in an error when extraneous tabs are encountered. If the error reporter exists, the parser will report the error as a warning only.
     * @param value The new value in which to set the "ignoreExtraneousTabs" property.
     */
    void getIgnoreExtraneousTabs(bool value) { mIgnoreExtraneousTabs = value; }

protected:
    /**
     * Parses an entity starting at the current token.
     */
    virtual void parseFromCurrentToken() override;

    /**
     * Initializes the resulting document. This method is called as a result of a call to the parse() method.
     */
    virtual void parseDidInit() override;
    
    /**
     * Commences semantic analysis upon the document.
     */
    virtual void sourceDidParse() override;

private:
    /**
     * A pattern to match an empty line.
     */
    static const std::regex EmptyLine;

    /**
     * A pattern to match hours and minutes from a numerical literal.
     */
    static const std::regex HoursAndMin;

    /**
     * A pattern to match seconds with optional milliseconds.
     */
    static const std::regex SecsWithMs;

    /**
     * The resulting document from the parse.
     */
    Document *mDocument;

    /**
     * The stack of entity nodes used to determine the tree structure of the document.
     */
    std::vector<Entity *> mNodeStack;

    /**
     * Specifies whether or not the parser should report a warning rather than an error when extraneous tabs are encountered.
     */
    bool mIgnoreExtraneousTabs;
    
    /**
     * Skips spaces and tabs during speculation. Excludes linefeeds.
     */
    void specSkipDocWs();

    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely a qualified name or simple name.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictName();

    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likey a qualified name or simple name. Will also conclude definitively if the next token is definitly and simple name.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeName();

    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely a set of relationship bindings.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictRelationships();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likey a relationship prefix for an identity.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeRelationships();

    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a procedure description.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeProcedure();

    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely an action declaration.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeAction();

    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an time point literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictTimePoint();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a time point literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeTimePoint();

    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a keyframe description.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeKeyframe();
    
    /**
     * Performs full speculation to determine if the next token is definitely a boolean literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictBool();
    
    /**
     * Performs full speculation to determine if the next token is definitely a string literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictString();
    
    /**
     * Performs full speculation to determine if the next token is definitely a number literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictNumber();
    
    /**
     * Performs full speculation to determine if the next token is definitely a color literal.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictColor();
    
    /**
     * Performs full speculation to determine if the next token is definitely an expression of null.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictNull();
    
    /**
     * Performs full speculation to determine if the next token is definitely an expression of undefined.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictUndefined();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely an operand.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeOperand();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an operand.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictOperand();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely the end of the current entity. This method should only be used when already parsing an entity especially when handing atribute expressions.
     * @param openingDelimeter The opening delimeter to the current entity.
     * @param closingDelimiter The closing delimiter to the current entity.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     * @see computeExpr()
     */
    bool predictEndOfEntity(std::string openingDelimeter, std::string closingDelimiter);
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely an element selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeElementSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an element selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictElementSelector();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a procedure selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeProcedureSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an procedure selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictProcedureSelector();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely an snapshot selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeSnapshotSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an snapshot selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictSnapshotSelector();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a keyframe selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeKeyframeSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an keyframe selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictKeyframeSelector();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely an action selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeActionSelector();
    
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an action selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictActionSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an invocation selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictInvocationSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely some kind of selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely a nested expression.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictNestedExpr();
    
    /**
     * Performs full speculation to determine if the next token is definitely a a binary operator for a binary expression.
     * @return Returns true if speculation succeeds. Otherwise returns false.
    */
    bool predictBinaryOperator();
    
    /**
     * Performs lazy speculation to determine if the next sequence of tokens is likely a binary expression.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool assumeBinaryExpression();

    /**
     * Skips all whitespace starting at the current token.
     */
    void skipWs();

    /**
     * Skips all tab tokens starting at the current token.
     */
    void skipTabs();

    /**
     * Determines the parent entity in which the entity at the current token index can be bound to as a child. The number of leading tabs in the token cache is used to assume the parent entity. The stack is popped until the determined parent is on the top of the stack. Extraneous tabs will cause an error if the "ignoreExtraneousTabs" property is false.
     * @return Returns the computed parent. Returns the document if the entity is defined at the document level.
     */
    Entity *computeParent();

    /**
     * Reports the top of the entity node stack.
     */
    Entity *top() const;

    /**
     * Pushes the entity node onto the entity node stack.
     */
    void push(Entity *node);

    /**
     * Pops the top of the entity node stack.
     */
    Entity *pop();
    
    /**
     * Defines a symbol in the current context.
     * @param symbol The symbol to define.
     */
    bool define(Symbol *symbol);

    /**
     * Parses any qualified entity.
     */
    void parseEntity();

    /**
     * Parses a simple name.
     * @return Returns the SimpleName instance that is generated by this method.
     */
    SimpleName *parseSimpleName();

    /**
     * Parses any name including simple names and qualified names.
     * @return Returns a SimpleName instance or QualifiedName instance depending on the token sequence.
     */
    Name *parseName();

    /**
     * Parses an optional entity ID. Assumes the next token is the entity ID. This method will never result in a direct error.
     * @return Returns an ID object. The object will be nil if the entity is not predicted.
     */
    ElementID *parseID();

    /**
     * Parses and entitie's identity name.
     * @param relationships The identity relationships list to automatically append relationships to.
     * @return Returns the parse simple name or qualified name.
     */
    Name *parseIdentityName(IdentityRelationshipsList *relationships);

    /**
     * Parses a time point literal.
     * @return Returns a TimePointLiteral instance.
     */
    TimePointLiteral *parseTimePoint();

    /**
     * Parses a multiplicity literal.
     * @return Returns a MultiplicityLiteral instance.
     */
    MultiplicityLiteral *parseMultiplicity();

    /**
     *
     * @return Returns a Target instance that represents a simple or compound target.
     */
    Reference *parseReference();
        
    /**
     * Parses a list of entity relationships.
     */
    IdentityRelationshipsList *parseRelationships();
    
    /**
     * Parses all attributes, bindings, constraints if they can be assumed through lazy speculation.
     */
    void parseAttributesAndBindings();

    /**
     * Parses an attribute.
     */
    void parseAttribute();
    
    /**
     * Parses a binding.
     */
    void parseBinding();

    /**
     * Parses an element entity or prototype entity.
     */
    void parseElementOrPrototype();

    /**
     * Parses a snapshot.
     */
    void parseSnapshot();

    /**
     * Parses a keyframe entity.
     */
    void parseKeyframe();

    /**
     * Parses an action entity.
     */
    void parseAction();

    /**
     * Parses a procedure entity.
     */
    void parseProcedure();

    /**
     * Parses an invocation entity.
     */
    void parseInvocation();
    
    /**
     * Parses a query entity.
     */
    void parseQuery();

    /**
     *
     */
    int binaryPrec(compiler::Token op);

    /**
     *
     */
    int binaryPrec(std::string op);

    /**
     *
     */
    int binaryAssoc(compiler::Token op);

    /**
     *
     */
    int binaryAssoc(std::string op);

    /**
     *
     */
    bool isBinaryOp(compiler::Token op);

    /**
     *
     */
    bool isBinaryOp(std::string op);

    /**
     *
     */
    int unaryPrec(compiler::Token op);

    /**
     *
     */
    int unaryPrec(std::string op);

    /*int postfixPrec(token_t op);
    int postfixPrec(std::string op);
    bool isPostfix(token_t op);
    bool isPostfix(std::string op);*/

    /**
     *
     */
    Expression *computeExpr();

    /**
     *
     */
    Expression *computeExpr(int minPrec);
    
    /**
     * Creates a binary expression or compound selector.
     */
    Expression *createBinaryExpr(Expression *lhs, const compiler::Token &token, Expression *rhs);

    /**
     *
     */
    StringLiteral *parseString();

    /**
     *
     */
    NumberLiteral *parseNumber();

    /**
     *
     */
    BooleanLiteral *parseBool();

    /**
     *
     */
    ColorLiteral *parseColor();
    
    /**
     *
     */
    Expression *parseOpnd();
    
    /**
     *
     */
    Selector *parseSelector();
    
    /**
     *
     */
    ElementSelector *parseElementSelector();
    
    /**
     *
     */
    AttributeSelector *parseAttributeSelector();
    
    /**
     *
     */
    SelfSelector *parseSelfSelector();
    
    /**
     *
     */
    ParentSelector *parseParentSelector();
    
    /**
     *
     */
    RootSelector *parseRootSelector();
    
    /**
     *
     */
    DocumentSelector *parseDocumentSelector();
    
    /**
     *
     */
    ProcedureSelector *parseProcedureSelector();
    
    /**
     *
     */
    SnapshotSelector *parseSnapshotSelector();
    
    /**
     *
     */
    KeyframeSelector *parseKeyframeSelector();
    
    /**
     *
     */
    ActionSelector *parseActionSelector();

    /**
     *
     */
    Value *parseValue();
};

} // namespace hydro::engine

#endif /* __h3o_engine_PDocumentParser__ */
