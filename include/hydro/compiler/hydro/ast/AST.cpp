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

#include "AST.hpp"

namespace hydro::compiler
{
// constructor
AST::AST() {}

// destructor
AST::~AST()
{
    // free memory
    for (ASTNode *node : m_nodes)
        delete node;

    for (Scope *scope : m_scopes)
        delete scope;
}

Assignment *AST::createAssignment(Token token)
{
    return createNode<Assignment>(token);
}

BinaryExpression *AST::createBinaryExpression(Token token)
{
    return createNode<BinaryExpression>(token);
}

BinaryLiteral *AST::createBinaryLiteral(Token token)
{
    return createNode<BinaryLiteral>(token);
}

Block *AST::createBlock(Token token)
{
    return createNode<Block>(token);
}

BooleanLiteral *AST::createBooleanLiteral(Token token)
{
    return createNode<BooleanLiteral>(token);
}

BreakStatement *AST::createBreakStatement(Token token)
{
    return createNode<BreakStatement>(token);
}

CaseClause *AST::createCaseClause(Token token)
{
    return createNode<CaseClause>(token);
}

CastDeclaration *AST::createCastDeclaration(Token token, Modifiers *modifiers)
{
    CastDeclaration *node = createNode<CastDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

DefaultClause *AST::createDefaultClause(Token token)
{
    return createNode<DefaultClause>(token);
}

DictionaryEntry *AST::createDictionaryEntry()
{
    return createNode<DictionaryEntry>();
}

DictionaryInitializer *AST::createDictionaryInitializer(Token token)
{
    return createNode<DictionaryInitializer>(token);
}

DoStatement *AST::createDoStatement(Token token)
{
    return createNode<DoStatement>(token);
}

DoubleLiteral *AST::createDoubleLiteral(Token token)
{
    return createNode<DoubleLiteral>(token);
}

EmptyExpression *AST::createEmptyExpression()
{
    return createNode<EmptyExpression>();
}

EmptyStatement *AST::createEmptyStatement()
{
    return createNode<EmptyStatement>();
}

EventDeclaration *AST::createEventDeclaration(Token token, Modifiers *modifiers)
{
    EventDeclaration *node = createNode<EventDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

EventTypeDeclaration *AST::createEventTypeDeclaration(Token token)
{
    return createNode<EventTypeDeclaration>(token);
}

EventParameterDeclaration *AST::createEventParameterDeclaration(Token token)
{
    return createNode<EventParameterDeclaration>(token);
}

ExpressionStatement *AST::createExpressionStatement()
{
    return createNode<ExpressionStatement>();
}

FloatLiteral *AST::createFloatLiteral(Token token)
{
    return createNode<FloatLiteral>(token);
}

ForEachStatement *AST::createForEachStatement(Token token)
{
    return createNode<ForEachStatement>(token);
}

ForStatement *AST::createForStatement(Token token)
{
    return createNode<ForStatement>(token);
}

FunctionArgument *AST::createFunctionArgument(Token token)
{
    return createNode<FunctionArgument>(token);
}

FunctionArgumentsList *AST::createFunctionArgumentsList(Token token)
{
    return createNode<FunctionArgumentsList>(token);
}

GetterDeclaration *AST::createGetterDeclaration(Token token)
{
    return createNode<GetterDeclaration>(token);
}

HexadecimalLiteral *AST::createHexadecimalLiteral(Token token)
{
    return createNode<HexadecimalLiteral>(token);
}

Identifier *AST::createIdentifier(Token token, SimpleName *name)
{
    return createNode<Identifier>(token);
}

IfStatement *AST::createIfStatement(Token token)
{
    return createNode<IfStatement>(token);
}

ImportDeclaration *AST::createImportDeclaration(Token token)
{
    return createNode<ImportDeclaration>(token);
}

Invocation *AST::createInvocation(Token token)
{
    return createNode<Invocation>(token);
}

InvocationArguments *AST::createInvocationArguments(Token token)
{
    return createNode<InvocationArguments>(token);
}

JsonInitializer *AST::createJsonInitializer(Token token)
{
    return createNode<JsonInitializer>(token);
}

JsonMember *AST::createJsonMember()
{
    return createNode<JsonMember>();
}

LambdaExpression *AST::createLambdaExpression(Token token)
{
    return createNode<LambdaExpression>(token);
}

ListInitializer *AST::createListInitializer(Token token)
{
    return createNode<ListInitializer>(token);
}

LongLiteral *AST::createLongLiteral(Token token)
{
    return createNode<LongLiteral>(token);
}

MethodDeclaration *AST::createMethodDeclaration(Token token, Modifiers *modifiers)
{
    MethodDeclaration *node = createNode<MethodDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

NestedExpression *AST::createNestedExpression(Token token)
{
    return createNode<NestedExpression>(token);
}

NullLiteral *AST::createNullLiteral(Token token)
{
    return createNode<NullLiteral>(token);
}

ObjectInitializer *AST::createObjectInitializer(Token token)
{
    return createNode<ObjectInitializer>(token);
}

ObjectMember *AST::createObjectMember(Token token)
{
    return createNode<ObjectMember>(token);
}

OperatorDeclaration *AST::createOperatorDeclaration(Token token, Modifiers *modifiers)
{
    OperatorDeclaration *node = createNode<OperatorDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

PackageDeclaration *AST::createPackageDeclaration(Token token)
{
    return createNode<PackageDeclaration>(token);
}

PostfixExpression *AST::createPostfixExpression(Token token)
{
    return createNode<PostfixExpression>(token);
}

PropertyDeclaration *AST::createPropertyDeclaration(Token token, Modifiers *modifiers)
{
    PropertyDeclaration *node = createNode<PropertyDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

QualifiedName *AST::createQualifiedName(Name *qualifier, SimpleName *name)
{
    QualifiedName *node = createNode<QualifiedName>();
    node->setQualifier(qualifier);
    node->setName(name);
    return node;
}

RegularExpressionLiteral *AST::createRegularExpressionLiteral(Token token)
{
    return createNode<RegularExpressionLiteral>(token);
}

ReturnStatement *AST::createReturnStatement(Token token)
{
    return createNode<ReturnStatement>(token);
}

SetterDeclaration *AST::createSetterDeclaration(Token token)
{
    return createNode<SetterDeclaration>(token);
}

ShortLiteral *AST::createShortLiteral(Token token)
{
    return createNode<ShortLiteral>(token);
}

SimpleName *AST::createSimpleName(Token token)
{
    std::string value = token.value();
    SimpleName *node = createNode<SimpleName>(token);
    node->setValue(value);
    return node;
}

StateDeclaration *AST::createStateDeclaration(Token token, Modifiers *modifiers)
{
    StateDeclaration *node = createNode<StateDeclaration>(token);
    node->modifiers = modifiers;
    return node;
}

StringExpression *AST::createStringExpression(Token token)
{
    return createNode<StringExpression>(token);
}

StringLiteral *AST::createStringLiteral(Token token)
{
    return createNode<StringLiteral>(token);
}

SubscriptExpression *AST::createSubscriptExpression(Token token)
{
    return createNode<SubscriptExpression>(token);
}

SuperConstructorInvocation *AST::createSuperConstructorInvocation(Token token)
{
    return createNode<SuperConstructorInvocation>(token);
}

SuperMethodInvocation *AST::createSuperMethodInvocation(Token token)
{
    return createNode<SuperMethodInvocation>(token);
}

SwitchStatement *AST::createSwitchStatement(Token token)
{
    return createNode<SwitchStatement>(token);
}

TernaryExpression *AST::createTernaryExpression(Token token)
{
    return createNode<TernaryExpression>(token);
}

ThrowStatement *AST::createThrowStatement(Token token)
{
    return createNode<ThrowStatement>(token);
}

TryStatement *AST::createTryStatement(Token token)
{
    return createNode<TryStatement>(token);
}

UnaryExpression *AST::createUnaryExpression(Token token)
{
    return createNode<UnaryExpression>(token);
}

Undefined *AST::createUndefined(Token token)
{
    return createNode<Undefined>(token);
}

UnsignedIntegerLiteral *AST::createUnsignedIntegerLiteral(Token token)
{
    return createNode<UnsignedIntegerLiteral>(token);
}

UnsignedLongLiteral *AST::createUnsignedLongLiteral(Token token)
{
    return createNode<UnsignedLongLiteral>(token);
}

UnsignedShortLiteral *AST::createUnsignedShortLiteral(Token token)
{
    return createNode<UnsignedShortLiteral>(token);
}

VariableDeclaration *AST::createVariableDeclaration(Token token)
{
    return createNode<VariableDeclaration>(token);
}

VariableExpression *AST::createVariableExpression(Token token)
{
    return createNode<VariableExpression>(token);
}

VariableFragment *AST::createVariableFragment(Token token)
{
    return createNode<VariableFragment>(token);
}

WhileStatement *AST::createWhileStatement(Token token)
{
    return createNode<WhileStatement>(token);
}

Scope *AST::createScope()
{
    Scope *scope = new Scope();
    m_scopes.push_back(scope);
    return scope;
}

Scope *AST::createScope(std::string name)
{
    Scope *scope = new Scope(name);
    m_scopes.push_back(scope);
    return scope;
}

Scope *AST::createScope(Scope *enclosingScope)
{
    Scope *scope = new Scope(enclosingScope);
    m_scopes.push_back(scope);
    return scope;
}

Scope *AST::createScope(std::string name, Scope *enclosingScope)
{
    Scope *scope = new Scope(name, enclosingScope);
    m_scopes.push_back(scope);
    return scope;
}

} // namespace hydro::compiler
