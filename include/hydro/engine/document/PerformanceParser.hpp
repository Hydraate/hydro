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

#ifndef __h3o_engine_EngineParser__
#define __h3o_engine_EngineParser__

#include <stack>
#include <vector>

#include "../../compiler/Parser.hpp"

#include "expression/BinaryExpression.hpp"
#include "expression/BooleanLiteral.hpp"
#include "expression/ColorLiteral.hpp"
#include "expression/ElementSelector.hpp"
#include "expression/ProcedureSelector.hpp"
#include "expression/SnapshotSelector.hpp"
#include "expression/KeyframeSelector.hpp"
#include "expression/ActionSelector.hpp"
#include "expression/InvocationSelector.hpp"
#include "expression/ListInitializer.hpp"
#include "expression/MultiplicityLiteral.hpp"
#include "expression/NullExpression.hpp"
#include "expression/NumberLiteral.hpp"
#include "expression/ProcedureSelector.hpp"
#include "expression/StringLiteral.hpp"
#include "expression/TimePointLiteral.hpp"
#include "expression/UndefinedExpression.hpp"
#include "expression/ExponentiationExpression.hpp"
#include "expression/MultiplicationExpression.hpp"
#include "expression/DivisionExpression.hpp"
#include "expression/RemainderExpression.hpp"
#include "expression/AdditionExpression.hpp"
#include "expression/SubtractionExpression.hpp"
#include "expression/EqualityExpression.hpp"
#include "expression/InequalityExpression.hpp"
#include "expression/LogicalANDExpression.hpp"
#include "expression/LogicalORExpression.hpp"
#include "expression/LogicalNOTExpression.hpp"
#include "expression/GreaterThanExpression.hpp"
#include "expression/GreaterThanOrEqualExpression.hpp"
#include "expression/LessThanExpression.hpp"
#include "expression/LessThanOrEqualExpression.hpp"
#include "expression/BitwiseORExpression.hpp"
#include "expression/BitwiseANDExpression.hpp"
#include "expression/BitwiseORExpression.hpp"
#include "expression/BitwiseNOTExpression.hpp"
#include "expression/BitwiseLeftShiftExpression.hpp"
#include "expression/BitwiseRightShiftExpression.hpp"
#include "expression/BitwiseXORExpression.hpp"

#include "Action.hpp"
#include "Attribute.hpp"
#include "Document.hpp"
#include "Element.hpp"
#include "IdentityRelationshipsList.hpp"
#include "Invocation.hpp"
#include "Keyframe.hpp"
#include "Procedure.hpp"
#include "SimpleName.hpp"
#include "QualifiedName.hpp"
#include "Snapshot.hpp"
#include "ElementReference.hpp"
#include "Query.hpp"
#include "ProcedureReference.hpp"
#include "SnapshotReference.hpp"
#include "KeyframeReference.hpp"
#include "ActionReference.hpp"
#include "InvocationReference.hpp"

#include "PerformanceLexer.hpp"

namespace hydro::engine
{
/**
 * The EngineParser class parses documents that describe interactive content.
 */
class PDocumentParser : public compiler::Parser
{
public:
    /**
     * The node_stack_empty object is thrown if an unexpected empty node stack is encountered.
     */
    struct node_stack_empty
    {
    };

    /**
     * Creates an EngineParser object.
     */
    PDocumentParser();

    /**
     * Creates an EngineParser object that sends errors to an error reporter module.
     */
    PDocumentParser(compiler::ErrorReporter *errorReporter);

    /**
     * Destroys the EngineParser object.
     */
    virtual ~PDocumentParser();

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
     * Performs full speculation to determine if the next sequence of tokens is definitely an operand.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictOperand();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an element selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictElementSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an procedure selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictProcedureSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an snapshot selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictSnapshotSelector();
    
    /**
     * Performs full speculation to determine if the next sequence of tokens is definitely an keyframe selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
     */
    bool predictKeyframeSelector();
    
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
     * Performs full speculation to determine if the next token is definitely a a compound operator with a compound selector.
     * @return Returns true if speculation succeeds. Otherwise returns false.
    */
    bool predictCompoundOperator();
    
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
     * Returns the top of the entity node stack.
     */
    Entity *top() const;

    /**
     * Pushes the entity node onto the operand stack
     */
    void push(Entity *node);

    /**
     *
     */
    Entity *pop();

    /**
     *
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
    Target *parseTarget();

    /**
     */
    void parseAttributes();

    /**
     *
     */
    void parseElement();

    /**
     *
     */
    void parseSnapshot();

    /**
     *
     */
    void parseKeyframe();

    /**
     *
     */
    void parseAction();

    /**
     *
     */
    void parseProcedure();

    /**
     *
     */
    void parseInvocation();

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
    Expression *createBinaryExpression(Expression *lhs, const compiler::Token &token, Expression *rhs);

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
    Expression *parseOpnd();

    /**
     *
     */
    Expression *parseOpnd(int minPrec);

    /**
     *
     */
    Expression *parseBinaryExpr(Expression *lhs, compiler::Token operatorToken, Expression *rhs);

    /**
     *
     */
    Value *parseValue();
};

} // namespace hydro::engine

#endif /* __h3o_engine_EngineParser__ */
