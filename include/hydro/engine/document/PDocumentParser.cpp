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

#include "PDocumentParser.hpp"

namespace hydro::engine
{
/**
 *
 */
const std::regex PDocumentParser::EmptyLine{"^[\\s\\n]+$"};

/**
 *
 */
const std::regex PDocumentParser::HoursAndMin{"^[0-9]{1,2}$"};

/**
 *
 */
const std::regex PDocumentParser::SecsWithMs{"^[0-9]{2}\\.[0-9]{3}$"}; // strict

PDocumentParser::PDocumentParser(compiler::ErrorReporter *errorReporter)
    : Parser{new PDocumentLexer{errorReporter}}
{
    mDocument = Document::create();
    mIgnoreExtraneousTabs = false;

    // ignore comments
    ignore(mcomment_tkn);
}

PDocumentParser::~PDocumentParser()
{
}

void PDocumentParser::parseFromCurrentToken()
{
    // skip empty lines
    while (match(ln_tkn) || match(compiler::lexer_whitespace) || match(tab_tkn))
        skip();

    // parse entities until the end of the token stream
    if (!isEof())
        parseEntity();
}

void PDocumentParser::parseDidInit()
{
    // clear stack
    while (!mNodeStack.empty())
        mNodeStack.pop_back();

    mNodeStack.push_back(mDocument);
}

void PDocumentParser::sourceDidParse()
{
    Resolver resolver{ getErrorReporter() };
    resolver.resolve(mDocument);
}

void PDocumentParser::specSkipDocWs()
{
    while (specMatch(ws_tkn) || specMatch(tab_tkn));
}

bool PDocumentParser::predictName()
{
    specStart();

    if (specMatch(id_tkn))
    {
        while (specMatch("."))
        {
            if (specMatch(id_tkn))
                continue;
            else
                return specFail();
        }
        
        return specSuccess();
    }

    return specFail();
}

bool PDocumentParser::assumeName()
{
    return specMatch(id_tkn);
}

bool PDocumentParser::predictRelationships()
{
    specStart();

    while (specExists())
    {
        if (predictName())
        {
            if (specMatch("|"))
                continue;
            else if (specMatch(":"))
                return specSuccess();
            else
                break; // fail
        }
        else
            break; // fail
    }

    return specFail();
}

bool PDocumentParser::assumeRelationships()
{
    specStart();

    if(predictName())
        if(specMatch("|") || specMatch(":"))
            return specSuccess();

    return specFail();
}

bool PDocumentParser::predictTimePoint()
{
    specStart();

    if (specMatch(double_tkn))
    {
        if (specMatch(":"))
        {
            if (specMatch(double_tkn))
            {
                if(specMatch(":"))
                    if(!specMatch(double_tkn))
                        return specFail();
                return specSuccess();
            }
        }
    }

    return specFail();
}


bool PDocumentParser::assumeTimePoint()
{
    specStart();
    if (specMatch(double_tkn))
        if (specMatch(":"))
            if (specMatch(double_tkn))
                return specSuccess();
    return specFail();
}

bool PDocumentParser::assumeKeyframe()
{
    specStart();

    if (specMatch("("))
        return assumeTimePoint();

    return specFail();
}

bool PDocumentParser::predictBool()
{
    return specMatch(bool_tkn);
}

bool PDocumentParser::predictString()
{
    return specMatch(string_tkn);
}

bool PDocumentParser::predictNumber()
{
    specStart();
    
    if(specMatch(double_tkn) || specMatch("Infinity") || specMatch("NaN"))
        return specSuccess();
    
    return specFail();
}

bool PDocumentParser::predictColor()
{
    return specMatch(color_tkn);
}

bool PDocumentParser::predictNull()
{
    return specMatch("null");
}

bool PDocumentParser::predictUndefined()
{
    return specMatch("undefined");
}

bool PDocumentParser::assumeOperand()
{
    specStart();

    // try to predict literal expressions
    if(predictBool() || predictString() || predictNumber() || predictColor() || predictNull() || predictUndefined())
        return specSuccess();
    
    // try to predict simple selectors
    if(specMatch(id_tkn) || specMatch("[") || specMatch("<") || specMatch("{") || specMatch("("))
        return specSuccess();

    return specFail();
}

bool PDocumentParser::predictOperand()
{
    specStart();
    
    // try to predict literal expressions
    if(predictBool() || predictString() || predictNumber() || predictColor() || predictNull() || predictUndefined())
        return specSuccess();
    
    // try to predict simple selectors
    if(predictElementSelector() || predictProcedureSelector() || predictSnapshotSelector() || predictKeyframeSelector() || predictActionSelector())
        return specSuccess();

    return specFail();
}

bool PDocumentParser::predictEndOfEntity(std::string openingDelimeter, std::string closingDelimiter)
{
    specStart();
    
    specSkipDocWs();
    
    if (specMatch(closingDelimiter))
    {
        specSkipDocWs();
        
        if(specMatch(ln_tkn))
            return specSuccess();
    }
    
    return specFail();
}

bool PDocumentParser::assumeElementSelector()
{
    specStart();
    
    if(specMatch("["))
        if(specMatch(id_tkn) || specMatch(identity_tkn))
            return specSuccess();
    
    return specFail();
}

bool PDocumentParser::predictElementSelector()
{
    specStart();
    
    if(specMatch("["))
    {
        if(predictName())
            specMatch(identity_tkn);
        else if(!specMatch(identity_tkn))
            return specFail();
    
        if(specMatch("]"))
            return specSuccess();
    }
    
    return specFail();
}

bool PDocumentParser::assumeProcedureSelector()
{
    specStart();
    
    if(specMatch("<"))
        if(specMatch(id_tkn))
            return specSuccess();
    
    return specFail();
}

bool PDocumentParser::predictProcedureSelector()
{
    specStart();
    
    if(specMatch("<") && predictName() && specMatch(">"))
        return specSuccess();
    
    return specFail();
}

bool PDocumentParser::assumeSnapshotSelector()
{
    specStart();
    
    if(specMatch("{"))
        if(specMatch(id_tkn))
            return specSuccess();
    
    return specFail();
}

bool PDocumentParser::predictSnapshotSelector()
{
    specStart();
    
    if(specMatch("{") && predictName() && specMatch("}"))
        return specSuccess();
    
    return specFail();
}

bool PDocumentParser::assumeKeyframeSelector()
{
    specStart();
    
    if(assumeKeyframe())
        return specSuccess();

    return specFail();
}

bool PDocumentParser::predictKeyframeSelector()
{
    specStart();
    
    if (specMatch("(") && predictTimePoint() && specMatch(")"))
    {
        specSkipDocWs();

        if(specMatch("{") && predictName() && specMatch("}"))
            return specSuccess();
    }
    
    return specFail();
}

bool PDocumentParser::assumeActionSelector()
{
    specStart();
    
    if(specMatch("("))
        if(specMatch(id_tkn))
            return specSuccess();
    
    return specFail();
}


bool PDocumentParser::predictActionSelector()
{
    specStart();
    
    if(specMatch("(") && predictName() && specMatch(")"))
        return specSuccess();
    
    return specFail();
}

bool PDocumentParser::predictInvocationSelector()
{
    specStart();
    
    return specFail();
}

bool PDocumentParser::predictBinaryOperator()
{
    specStart();
    specSkipDocWs();

    if(specMatch("[") || specMatch(".") || specMatch("..") || specMatch("**") || specMatch("*") || specMatch("/") || specMatch("%") || specMatch("+") || specMatch("-") || specMatch("==") || specMatch("!=") || specMatch(">") || specMatch(">=") || specMatch("<") || specMatch("<=") || specMatch("?") || specMatch("&&") || specMatch("&") || specMatch("!") || specMatch("||") || specMatch("|") || specMatch("^") || specMatch(">>") || specMatch(">>>") || specMatch("<<") || specMatch("~"))
        return specSuccess();
    
    return specFail();
}

bool PDocumentParser::assumeBinaryExpression()
{
    specStart();
    specUp();
    specSkipDocWs();

    if(predictBinaryOperator())
    {
        // skip whitespace (excludes linefeeds)
        specSkipDocWs();

        // if the next token is a line feed or an attribute it cannot be a binary operator
        if (assumeOperand())
            return specSuccess(); // operand is also assumed
    }

    return specFail();
}

void PDocumentParser::skipWs()
{
    skip(compiler::lexer_whitespace);
}

void PDocumentParser::skipTabs()
{
    skip(tab_tkn);
}

Entity *PDocumentParser::computeParent()
{
    std::list<compiler::Token> tabs;

    // find tabs until start of line
    for (int i = (int)mTokens.size() - 1; i >= 0; i--)
    {
        int k = (int)mTokens.size() - i;
        compiler::Token token = la(-k);

        if (match(tab_tkn, token))
            tabs.push_back(token);
        else if (match(ln_tkn, token) || i == 0)
            break;
        else if (token)
            abrupt(token);
        else
        {
            reportError("An unexpected implementation error occurred in parser.");
            abort();
        }
    }

    // validate tab count to retrieve parent
    auto maxTabs = mNodeStack.size() - 1; // minus one to exclude document level nodes
    auto ntabs = tabs.size();

    if (ntabs == maxTabs)
        ; // do nothing
    else if (ntabs < maxTabs)
    {
        while (ntabs < maxTabs)
        {
            pop();
            maxTabs = mNodeStack.size() - 1; // exclude document level nodes
        }
    }
    else
        // out of bounds
        reportError("Tab count is too high.", tabs.front());

    return top();
}

Entity *
PDocumentParser::top() const
{
    if (!mNodeStack.empty())
        return mNodeStack.back();

    // empty
    return nullptr;
}

void PDocumentParser::push(Entity *node)
{
    mNodeStack.push_back(node);
}

bool PDocumentParser::define(Symbol *symbol)
{
    auto context = top()->getContext();
    
    if(context->contains(symbol))
        return false;
    
    context->define(symbol);
    return true;
}

Entity *
PDocumentParser::pop()
{
    if (mNodeStack.empty())
        throw node_stack_empty{};

    Entity *topNode = top();
    mNodeStack.pop_back();
    return topNode;
}

void PDocumentParser::parseEntity()
{
    skipTabs();
    
    if (match("["))
    {
        // element or prototype
        parseElementOrPrototype();
    }
    else if (assumeKeyframe())
    {
        // keyframe (snapshot)
        release();
        parseKeyframe();
    }
    else if (match("{"))
    {
        // snapshot
        parseSnapshot();
    }
    else if (match("("))
    {
        if(matchNext("("))
        {
            // query
            parseQuery();
        }
        else
        {
            // action
            parseAction();
        }
    }
    else if (match("<"))
    {
        if (!matchNext(id_tkn))
        {
            // invocation
            parseInvocation();
        }
        else
        {
            // procedure
            parseProcedure();
        }
    }
    else if(!isEof())
        abrupt();
    
    advance();
    
    while (match(ws_tkn) || match(tab_tkn))
        skip();

    if (!match(ln_tkn) && !isEof())
        abrupt();
}

SimpleName *PDocumentParser::parseSimpleName()
{
    validate(id_tkn);
    return mDocument->createSimpleName(currentToken());
}

Name *PDocumentParser::parseName()
{
    validate(id_tkn);
    Name *result = nullptr;

    if (matchNext("."))
    {
        Name *lhs;
        SimpleName *rhs;

        // qualified name
        result = parseSimpleName(); // will be lhs

        // qualified
        // com.example.MyClass
        while (matchNext("."))
        {
            advance();
            validate(".");
            auto token = currentToken();
            lhs = result;            // qualifier
            advance();               // to expected name
            rhs = parseSimpleName(); // name
            result = mDocument->createQualifiedName(lhs, token, rhs);
        }
    }
    else
    {
        // simple name
        result = parseSimpleName();
    }

    return result;
}

ElementID *
PDocumentParser::parseID()
{
    if (matchNext(identity_tkn))
    {
        advance();
        return mDocument->createElementID( currentToken() );
    }

    return nullptr;
}

Name *PDocumentParser::parseIdentityName(IdentityRelationshipsList *relationships)
{
    if(matchNext("|") || matchNext(":"))
    {
        // entity has relationship(s)
        Name *name = parseName();
        relationships->append(mDocument->createRelationship(name));
        
        while (matchNext("|"))
        {
            advance(); // to |
            advance(); // to expected name
            name = parseName();
            relationships->append(mDocument->createRelationship(name));
        }
        
        advance(); // to expected :
        validate(":");
        advance(); // to expected name
    }
    
    Name *name = parseName();
    return name;
}


TimePointLiteral *
PDocumentParser::parseTimePoint()
{
    NumberLiteral *a = parseNumber();
    advance(); // to expected :
    validate(":");
    advance(); // to expected number
    NumberLiteral *b = parseNumber();
    NumberLiteral *c = nullptr;

    if (matchNext(":"))
    {
        advance(2);
        c = parseNumber();
    }

    NumberLiteral *hrs = nullptr;
    NumberLiteral *min; // will be initialized
    NumberLiteral *sec; // will be initialized
    NumberLiteral *ms = nullptr;
    TimePointLiteral *time;

    if (c)
    {
        //includes hours 00:00:00...
        hrs = a;
        min = b;
        sec = c;
        time = mDocument->createTimePoint(hrs, min, sec, ms);
    }
    else
    {
        // minutes and seconds only 00:00
        min = a;
        sec = b;
        time = mDocument->createTimePoint(min, sec, ms);
    }

    /*
    if (hrs) {
        // validate hours
        if (!match(hoursAndMin, hrs->token().value()))
            reportError("Hours must be a two digit integer.", a->token());
        else if (hrs->token().value().length() == 1)
            reportWarning("Single digit hours.", hrs->token());
    }

    // validate minutes
    if (!match(hoursAndMin, min->token().value()))
        reportError("Minutes must be a two digit integer.", min->token());
    else if (min->token().value().length() == 1)
        reportWarning("Single digit minutes.", min->token());

    // validate seconds
    if (!match(hoursAndMin)) {
        if (match(lexer_int))
            reportError("Seconds must be a two digit integer.", sec->token());
        else if (!match(secsWithMs))
            reportError("Milliseconds must be a 3 digit integer after dot.", sec->token());
    }
     */

    return time;
}

Reference *PDocumentParser::parseReference()
{
    SimpleReference *reference = nullptr;
    Reference *result = nullptr;
    auto token = currentToken();
    
    do {
        if (match("["))
        {
            // element
            ElementClass *elementClass = nullptr;
            ElementID *id = nullptr;
            if(matchNext(id_tkn))
            {
                advance();
                Name *name = parseName();
                elementClass = mDocument->createElementClass(name);
            }
            
            id = parseID();
            
            if(!elementClass && !id)
                // illegal
                reportError("Assumed element reference requires an element ID and/or and element class name.", token);

            advance();
            validate("]");
            reference = mDocument->createElementReference(elementClass, id);
        }
        else if (match("{"))
        {
            // snapshot
            advance();
            Name *name = parseName();
            SnapshotDomain *snapshotDomain = mDocument->createSnapshotDomain( name );
            advance();
            validate("}");
            reference = mDocument->createSnapshotReference( snapshotDomain );
        }
        else if (match("<") && matchNext(id_tkn))
        {
            // procedure
            advance();
            Name *name = parseName();
            ProcedureClass *procedureClass = mDocument->createProcedureClass( name );
            advance();
            validate(">");
            reference = mDocument->createProcedureReference( procedureClass );
        }
        else if (match("<"))
        {
            // invocation
            advance();
            InvocationTarget *target = mDocument->createInvocationTarget(parseReference());
            advance();
            validate(">");
            reference = mDocument->createInvocationReference(target);
        }
        else if (match("("))
        {
            if(matchNext(id_tkn))
            {
                // action
                advance();
                Name *name = parseName();
                EventClass *eventClass = mDocument->createEventClass( name );
                advance();
                validate(")");
                reference = mDocument->createActionReference( eventClass );
            }
            else if(matchNext(double_tkn))
            {
                advance();
                // keyframe
                TimePointLiteral *time = parseTimePoint();
                advance();
                validate(")");
                advance();
                skipWs();
                validate("{");
                advance();
                Name *name = parseName();
                SnapshotDomain *snapshotDomain = mDocument->createSnapshotDomain( name );
                advance();
                validate("}");
                reference = mDocument->createKeyframeReference( time, snapshotDomain );
            }
            else
            {
                // invalid sequence
                abruptNext();
            }
        }
        else
        {
            // invalid
            abrupt();
        }
        
        if(matchNext("."))
        {
            advance();
            advance();
            
            if (result)
            {
                result = mDocument->createCompoundReference(result, currentToken(), reference);
            }
            else
            {
                result = reference;
            }
        }
        else if(result)
        {
            // end
            result = mDocument->createCompoundReference(result, currentToken(), reference);
            break;
        }
        else
        {
            // end
            result = reference;
            break;
        }
    }
    while(tokenExists());
    
    return result;
}

IdentityRelationshipsList *PDocumentParser::parseRelationships()
{
    IdentityRelationshipsList *list = mDocument->createRelationshipsList();
    
    if(!assumeRelationships())
        return list;
    
    while(tokenExists())
    {
        Relationship *rel = mDocument->createRelationship( parseName() );
        list->append(rel);

        advance();

        if(match("|"))
        {
            advance();
            continue;
        }
        
        validate(":");
        advance(); // auto advance
        break;
    }
    
    return list;
}

void PDocumentParser::parseAttributesAndBindings()
{
    while (matchNext(id_tkn, compiler::lexer_whitespace) || matchNext("{", compiler::lexer_whitespace) || matchNext("(", compiler::lexer_whitespace))
    {
        advanceSkip(compiler::lexer_whitespace);
        
        if (match(id_tkn))
            parseAttribute();
        else
            parseBinding();
    }
}

void PDocumentParser::parseAttribute()
{
    Name *name = parseName();
    advanceSkip(compiler::lexer_whitespace);
    if(match(":"))
    {
        advanceSkip(compiler::lexer_whitespace);
        Value *value = parseValue();
        top()->appendAttribute(mDocument->createMirror(name, value));
    }
    else
    {
        validate("=");
        advanceSkip(compiler::lexer_whitespace);
        Value *value = parseValue();
        top()->appendAttribute(mDocument->createAttribute(name, value));
    }
}

void PDocumentParser::parseBinding()
{
    if(match("{"))
    {
        // while binding
        advanceSkip(compiler::lexer_whitespace);
        Expression *condition = computeExpr();
        advanceSkip(compiler::lexer_whitespace);
        validate("}");
        top()->appendBinding(mDocument->createWhileBinding(currentToken(), condition));
    }
    else if (match("("))
    {
        // when binding
        advanceSkip(compiler::lexer_whitespace);
        Expression *condition = computeExpr();
        advanceSkip(compiler::lexer_whitespace);
        validate(")");
        top()->appendBinding(mDocument->createWhenBinding(currentToken(), condition));
    }
    else
        abrupt();
}

void PDocumentParser::parseElementOrPrototype()
{
    Entity *parent = computeParent();
    validate("[");
    auto token = currentToken();
    advance();
    IdentityRelationshipsList *relationships = parseRelationships();

    if (match("["))
    {
        // parse prototype
        advance(); // to expected name
        Name *name = parseName();
        advance();
        Name *parentName = nullptr;
        if(match(":"))
        {
            advance();
            parentName = parseName();
            advance();
        }
        validate("]");
        ElementClass *elementClass = mDocument->createElementClass(name);
        ElementClass *parentClass = parentName ? mDocument->createElementClass(parentName) : nullptr;
        PrototypeIdentity *identity = mDocument->createPrototypeIdentity( relationships, elementClass, parentClass );
        Prototype *prototype = mDocument->createPrototype( parent, identity );
        PrototypeSymbol *symbol = mDocument->createPrototypeSymbol( elementClass );
        define(symbol);
        push(prototype);
    }
    else if(match(id_tkn))
    {
        // parse element instance
        Name *name = parseName();
        ElementID *id = parseID();
        ElementClass *elementClass = mDocument->createElementClass( name );
        ElementIdentity *identity = mDocument->createElementIdentity( relationships, elementClass, id );
        Element *element = new Element{ parent, identity };
        push(element);
    }
    else
    {
        // error
        abrupt();
    }
    
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace); // to expected ]
    validate("]");
}

void PDocumentParser::parseSnapshot()
{
    Entity *parent = computeParent();
    validate("{");
    advance();
    IdentityRelationshipsList *relationships = new IdentityRelationshipsList{};
    Name *name = parseIdentityName(relationships);
    SnapshotDomain *_class = new SnapshotDomain{ name };
    SnapshotIdentity *identity = new SnapshotIdentity{ relationships, _class };
    Snapshot *snapshot = new Snapshot{ parent, identity };
    push(snapshot);
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace); // to expected }
    validate("}");
}

void PDocumentParser::parseKeyframe()
{
    Entity *parent = computeParent();
    validate("(");
    advance();                                 // to expected time
    TimePointLiteral *time = parseTimePoint(); // time point
    advance();                                 // to expected )
    validate(")");
    advance(); // to expected {
    skipWs();
    validate("{");
    advance();
    IdentityRelationshipsList *relationships = mDocument->createRelationshipsList();
    Name *name = parseIdentityName(relationships);
    SnapshotDomain *_class = mDocument->createSnapshotDomain( name );
    SnapshotIdentity *identity = mDocument->createSnapshotIdentity( relationships, _class );
    Keyframe *keyframe = mDocument->createKeyframe(parent, time, identity);
    push(keyframe);
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace); // to expected }
    validate("}");
}

void PDocumentParser::parseAction()
{
    Entity *parent = computeParent();
    validate("(");
    advance(); // to expected name
    IdentityRelationshipsList *relationships = new IdentityRelationshipsList{};
    Name *name = parseIdentityName(relationships);
    EventClass *_class = mDocument->createEventClass(name);
    ActionIdentity *identity = mDocument->createActionIdentity(relationships, _class);
    Action *action = mDocument->createAction( parent, identity );
    push(action);
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace); // to expected )
    validate(")");
}

void PDocumentParser::parseProcedure()
{
    Entity *parent = computeParent();
    validate("<");
    advance(); // to expected name
    IdentityRelationshipsList *relationships = mDocument->createRelationshipsList();
    Name *name = parseIdentityName(relationships);
    ProcedureClass *_class = mDocument->createProcedureClass(name);
    ProcedureIdentity *identity = mDocument->createProcedureIdentity(relationships, _class);
    Procedure *action = mDocument->createProcedure(parent, identity);
    push(action);
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace); // to expected )
    validate(">");
}

void PDocumentParser::parseInvocation()
{
    Entity *parent = computeParent();
    validate("<");
    advance(); // to expected target
    Reference *reference = parseReference();
    InvocationTarget *target = mDocument->createInvocationTarget(reference);
    InvocationIdentity *identity = mDocument->createInvocationIdentity(target);
    Invocation *invocation = mDocument->createInvocation(parent, identity);
    push(invocation);
    parseAttributesAndBindings();
    advanceSkip(compiler::lexer_whitespace);
    validate(">");
}

void PDocumentParser::parseQuery()
{
    validate("(");
    
    validate(")");
}

int PDocumentParser::binaryPrec(compiler::Token op)
{
    return binaryPrec(op.value());
}

int PDocumentParser::binaryPrec(std::string op)
{
    if (op == "(" || op == "[" || op == "." || op == "..")
        return 13; // primary
    else if (op == "**")
        return 12; // exponential
    else if (op == "*" || op == "/" || op == "%")
        return 11; // multiplicative
    else if (op == "+" || op == "-")
        return 10; // additive
    else if (op == "<<" || op == ">>" || op == ">>>")
        return 9; // bitwise shift
    else if (op == "<" || op == ">" || op == "<=" ||
             op == ">=")
        return 8; // relational
    else if (op == "==" || op == "!=")
        return 7; // equality
    else if (op == "&")
        return 6; // bitwise AND
    else if (op == "^")
        return 5; // bitwise XOR
    else if (op == "|")
        return 4; // bitwise OR
    else if (op == "&&")
        return 3; // logical AND
    else if (op == "||")
        return 2; // logical OR
    else if (op == "?")
        return 1; // conditional

    return 0;
}

int PDocumentParser::binaryAssoc(compiler::Token op)
{
    return binaryAssoc(op.value());
}

int PDocumentParser::binaryAssoc(std::string op)
{
    if (
        op == "=" ||
        op == "**=" ||
        op == "*=" ||
        op == "/=" ||
        op == "%=" ||
        op == "+=" ||
        op == "-=" ||
        op == "&=" ||
        op == "|=" ||
        op == "^=" ||
        op == ">>=" ||
        op == ">>>=" ||
        op == "<<=")
        return compiler::op_right_assoc; // right associative

    return compiler::op_left_assoc; // left associative
}

bool PDocumentParser::isBinaryOp(compiler::Token op)
{
    return isBinaryOp(op.value());
}

bool PDocumentParser::isBinaryOp(std::string op)
{
    return binaryPrec(op) > 0;
}

int PDocumentParser::unaryPrec(compiler::Token op)
{
    return unaryPrec(op.value());
}

int PDocumentParser::unaryPrec(std::string op)
{
    if (op == "!" ||
        op == "+" ||
        op == "-" ||
        op == "~")
        return 10;

    return 0;
}

Expression *
PDocumentParser::computeExpr()
{
    static_cast<PDocumentLexer *>(getLexer())->setState(engine_parse_expression); // reset lexer state
    auto expr = computeExpr(-1);
    static_cast<PDocumentLexer *>(getLexer())->setState(engine_parse_entity); // reset lexer state
    return expr;
}

Expression *
PDocumentParser::computeExpr(int minPrec)
{
    std::stack<compiler::Token> operators;
    std::stack<Expression *> operands;
    Expression *expr;
    Expression *lhs;
    Expression *rhs;
    compiler::Token a;
    compiler::Token b;

    skipWs();

    // init
    operators.push(compiler::NilToken); // push sentinel
    operands.push(parseOpnd());            // shift first operand (as expected)
    
    // Begin shift loop
    while (assumeBinaryExpression() &&
           ((matchNext(op_tkn, compiler::lexer_whitespace) || matchNext("[", compiler::lexer_whitespace)) &&
           (!matchNext(")", compiler::lexer_whitespace) && !matchNext("]", compiler::lexer_whitespace) && !matchNext(":", compiler::lexer_whitespace) && !matchNext("{", compiler::lexer_whitespace) && !matchNext("}", compiler::lexer_whitespace)) // Don't expect these to be binary operators
    ))
    {
        advance();          // To assumed binary or post-fix operator
        skipWs();

        a = currentToken(); // Target operator
        if(binaryPrec(a) < minPrec)
            break; // skip

        if (!isBinaryOp(a)) //&& !isPostfix(a))
        {
            reportError("Not a valid binary operator.", a);
            abort();
        }

        // Begin reduction loop
        while (true)
        {
            b = operators.top(); // Visit top of stack
            
            if (binaryPrec(a) > binaryPrec(b) || (binaryPrec(a) == binaryPrec(b) && binaryAssoc(a) == compiler::op_right_assoc))
            {   // If a > b
                if (match("[", a))
                {
                    // subscript
                    lhs = operands.top();
                    operands.pop();
                    advance(); // to expected expression
                    skipWs();
                    rhs = computeExpr();
                    advance();
                    skipWs();
                    validate("]");
                    operands.push(createBinaryExpr(lhs, a, rhs));
                    break;
                }
                else if (match("?", a))
                {
                    // conditional expression (expr ? block : block)
                    Expression *cond = operands.top();
                    operands.pop();
                    advance(); // to expected expr
                    skipWs();
                    lhs = computeExpr(binaryPrec(a));
                    advance(); // To expected
                    skipWs();
                    validate(":");
                    b = currentToken();
                    advance(); // to expected expr
                    skipWs();
                    rhs = computeExpr(binaryPrec(a));
                    operands.push(new ConditionalExpression(cond, lhs, rhs));
                    break;
                }
                else
                {
                    // push a onto operator stack and shift next operand
                    operators.push(a);
                    advance();
                    skipWs();
                    operands.push(parseOpnd());
                    break;
                }
            }
            else
            {
                // reduce b
                rhs = operands.top();
                operands.pop(); // pop rhs
                lhs = operands.top();
                operands.pop(); // pop lhs
                operands.push(createBinaryExpr(lhs, b, rhs));
                operators.pop(); // pop reduced operator b
                continue;        // continue reduction
            }
        }
    } // end shift loop

    // begin pop loop
    while (operators.size() > 1) // while sentinel is not the only token
    {
        a = operators.top();
        operators.pop();     // pop operator a
        b = operators.top(); // operator b

        if ((binaryPrec(a) > binaryPrec(b)) || (binaryPrec(a) == binaryPrec(b) && binaryAssoc(a) == compiler::op_right_assoc))
        {
            // reduce a
            rhs = operands.top();
            operands.pop(); // pop rhs
            lhs = operands.top();
            operands.pop(); // pop lhs
            operands.push(createBinaryExpr(lhs, a, rhs));
        }
        else
        {
            // reduce b
            operators.pop(); // pop operator b
            rhs = operands.top();
            operands.pop(); // pop rhs
            lhs = operands.top();
            operands.pop(); // pop lhs
            operands.push(createBinaryExpr(lhs, b, rhs));
            operators.push(a); // restore operator a as the top of the stack
        }
    } // end pop loop

    operators.top(); // pop sentinel
    expr = operands.top();
    operands.pop(); // pop result
    return expr;
}

Expression *PDocumentParser::createBinaryExpr(Expression *lhs, const compiler::Token &token, Expression *rhs)
{
    std::string op = token.value();
    Expression *expr = nullptr;
    Selector *left = dynamic_cast<Selector *>(lhs);
    Selector *right = dynamic_cast<Selector *>(rhs);
    
    if(op == "**")
        expr = mDocument->createExponentiation(lhs, token, rhs);
    else if(op == "*")
        expr = mDocument->createMultiplication(lhs, token, rhs);
    else if(op == "/")
        expr = mDocument->createDivision(lhs, token, rhs);
    else if(op == "%")
        expr = mDocument->createRemainder(lhs, token, rhs);
    else if(op == "+")
        expr = mDocument->createAddition(lhs, token, rhs);
    else if(op == "-")
        expr = mDocument->createSubtraction(lhs, token, rhs);
    else if(op == "&&")
        expr = mDocument->createLogicalAND(lhs, token, rhs);
    else if(op == "||")
        expr = mDocument->createLogicalOR(lhs, token, rhs);
    else if(op == "==")
        expr = mDocument->createEquality(lhs, token, rhs);
    else if(op == "!=")
        expr = mDocument->createInequality(lhs, token, rhs);
    else if(op == ">")
        expr = mDocument->createGreaterThan(lhs, token, rhs);
    else if(op == ">=")
        expr = mDocument->createGreaterThanOrEqual(lhs, token, rhs);
    else if(op == "<")
        expr = mDocument->createLessThan(lhs, token, rhs);
    else if(op == "<=")
        expr = mDocument->createLessThanOrEqual(lhs, token, rhs);
    else if(op == "&")
        expr = mDocument->createBitwiseAND(lhs, token, rhs);
    else if(op == "|")
        expr = mDocument->createBitwiseOR(lhs, token, rhs);
    else if(op == "^")
        expr = mDocument->createBitwiseXOR(lhs, token, rhs);
    else if(op == "<<")
        expr = mDocument->createBitwiseLeftShift(lhs, token, rhs);
    else if(op == ">>")
        expr = mDocument->createBitwiseRightShift(lhs, token, rhs);
    else if (op == ".")
    {
        // selector or member access
        if (left && right)
            expr = mDocument->createChildSelector(left, token, right);
        else
            expr = mDocument->createMemberAccess(lhs, token, rhs);
    }
    else if (op == "..")
    {
        if (left && right)
            expr = mDocument->createDescendantSelector(left, token, right);
        else
        {
            if (!left)
                reportError("Expected a selector to the left of the descendent selector.", left->getToken());
            if (!right)
            reportError("Expected a selector to the right of the descendent selector.", right->getToken());
        }
    }
    else if (op == "[")
    {
        if (left)
            expr = mDocument->createIndexSelector( left, token, rhs );
        else
            expr = mDocument->createSubscriptAccess( lhs, token, rhs );
    }
    else
    {
        // invalid binary expression.
        reportError("Expecting a binary operator or compound selector.", token);
        abort();
    }
    expr->setToken(token);
    return expr;
}

StringLiteral *
PDocumentParser::parseString()
{
    validate(string_tkn);
    return mDocument->createString(currentToken());
}

NumberLiteral *
PDocumentParser::parseNumber()
{
    validate(double_tkn);
    return mDocument->createNumber(currentToken());
}

BooleanLiteral *
PDocumentParser::parseBool()
{
    validate(bool_tkn);
    return mDocument->createBoolean(currentToken());
}

ColorLiteral *
PDocumentParser::parseColor()
{
    validate(color_tkn);
    return mDocument->createColor(currentToken());
}

Expression *
PDocumentParser::parseOpnd()
{
        if (match(string_tkn))
            return parseString();
        else if (match(double_tkn))
            return parseNumber();
        else if (match(bool_tkn))
            return parseBool();
        else if(match(color_tkn))
            return parseColor();
        else if(match("(") && !matchNext(id_tkn))
        {
            // nested expression
            auto token = currentToken();
            advance();
            skipWs();
            Expression *expr = computeExpr();
            advance();
            skipWs();
            validate(")");
            return mDocument->createNested(token, expr);
        }
        else if(assumeElementSelector())
            return parseElementSelector();
        else if(assumeProcedureSelector())
            return parseProcedureSelector();
        else if(assumeSnapshotSelector())
            return parseSnapshotSelector();
        else if(assumeKeyframeSelector())
            return parseKeyframeSelector();
        else if(assumeActionSelector())
            return parseActionSelector();
        else if(match(id_tkn))
            return parseAttributeSelector();
        else if(match("@self"))
            return parseSelfSelector();
        else if(match("@parent"))
            return parseParentSelector();
        else if(match("@root"))
            return parseRootSelector();
        else if(match("@document"))
            return parseDocumentSelector();

    abrupt();

    // fail
    return nullptr;
}

Selector *PDocumentParser::parseSelector()
{
    Expression *expr = computeExpr();
    
    if(Selector *selector = dynamic_cast<Selector *>(expr))
        return selector;

    reportError("Expression is not a valid selector.", expr->getToken());

    // fail
    return nullptr;
}

ElementSelector *PDocumentParser::parseElementSelector()
{
    validate("[");
    advance();
    ElementClass *elementClass = nullptr;
    ElementID *id = nullptr;
    if(match(id_tkn))
    {
        elementClass = mDocument->createElementClass( parseName());
        if(matchNext(identity_tkn))
        {
            advance();
            id = mDocument->createElementID(currentToken());
        }
    }
    else
    {
        validate(identity_tkn);
        id = mDocument->createElementID(currentToken());
    }
    advance();
    validate("]");
    return mDocument->createElementSelector(elementClass, id);
}

AttributeSelector *PDocumentParser::parseAttributeSelector()
{
    return mDocument->createAttributeSelector(parseName());
}

SelfSelector *PDocumentParser::parseSelfSelector()
{
    validate("@self");
    return mDocument->createSelfSelector( currentToken() );
}

ParentSelector *PDocumentParser::parseParentSelector()
{
    validate("@parent");
    return mDocument->createParentSelector(currentToken());
}

RootSelector *PDocumentParser::parseRootSelector()
{
    validate("@root");
    return mDocument->createRootSelector(currentToken());
}

DocumentSelector *PDocumentParser::parseDocumentSelector()
{
    validate("@document");
    return mDocument->createDocumentSelector(currentToken());
}

ProcedureSelector *PDocumentParser::parseProcedureSelector()
{
    validate("<");
    advance();
    ProcedureClass *procedureClass = mDocument->createProcedureClass(parseName());
    advance();
    validate(">");
    return mDocument->createProcedureSelector(procedureClass);
}

SnapshotSelector *PDocumentParser::parseSnapshotSelector()
{
    validate("{");
    advance();
    SnapshotDomain *snapshotDomain = mDocument->createSnapshotDomain( parseName() );
    advance();
    validate("}");
    return mDocument->createSnapshotSelector( snapshotDomain );
}

KeyframeSelector *PDocumentParser::parseKeyframeSelector()
{
    validate("(");
    advance();
    TimePointLiteral *time = parseTimePoint();
    advance();
    validate(")");
    advance();
    skipWs();
    validate("{");
    advance();
    SnapshotDomain *snapshotDomain = mDocument->createSnapshotDomain(parseName());
    advance();
    validate("}");
    return mDocument->createKeyframeSelector( time, snapshotDomain );
}

ActionSelector *PDocumentParser::parseActionSelector()
{
    validate("(");
    advance();
    EventClass *eventClass = mDocument->createEventClass( parseName() );
    advance();
    validate(")");
    return mDocument->createActionSelector( eventClass );
}

Value *
PDocumentParser::parseValue()
{
    // if is some other value...
    if (false)
    {
        // parse some other value...
    }

    // otherwise, compute expression
    return computeExpr();
}

} // namespace hydro::engine
