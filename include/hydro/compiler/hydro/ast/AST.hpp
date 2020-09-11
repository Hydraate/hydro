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

#ifndef __h3o_AST__
#define __h3o_AST__

#include <list>

#include "../../Token.hpp"

// expressions
#include "Assignment.hpp"
#include "BinaryExpression.hpp"
#include "BinaryLiteral.hpp"
#include "BooleanLiteral.hpp"
#include "DictionaryInitializer.hpp"
#include "DoubleLiteral.hpp"
#include "EmptyExpression.hpp"
#include "FloatLiteral.hpp"
#include "HexadecimalLiteral.hpp"
#include "Identifier.hpp"
#include "IntegerLiteral.hpp"
#include "Invocation.hpp"
#include "JsonInitializer.hpp"
#include "LambdaExpression.hpp"
#include "ListInitializer.hpp"
#include "LongLiteral.hpp"
#include "NestedExpression.hpp"
#include "NullLiteral.hpp"
#include "ObjectInitializer.hpp"
#include "OctalLiteral.hpp"
#include "PostfixExpression.hpp"
#include "RegularExpressionLiteral.hpp"
#include "ShortLiteral.hpp"
#include "StringExpression.hpp"
#include "StringLiteral.hpp"
#include "SubscriptExpression.hpp"
#include "SuperConstructorInvocation.hpp"
#include "SuperMethodInvocation.hpp"
#include "TernaryExpression.hpp"
#include "ThisExpression.hpp"
#include "UnaryExpression.hpp"
#include "Undefined.hpp"
#include "UnsignedIntegerLiteral.hpp"
#include "UnsignedLongLiteral.hpp"
#include "UnsignedShortLiteral.hpp"
#include "VariableExpression.hpp"

// statements
#include "Block.hpp"
#include "BreakStatement.hpp"
#include "CaseClause.hpp"
#include "CatchClause.hpp"
#include "ContinueStatement.hpp"
#include "DefaultClause.hpp"
#include "DoStatement.hpp"
#include "EmptyStatement.hpp"
#include "ExpressionStatement.hpp"
#include "ForEachStatement.hpp"
#include "ForStatement.hpp"
#include "IfStatement.hpp"
#include "ImportDeclaration.hpp"
#include "ReturnStatement.hpp"
#include "StateDeclaration.hpp"
#include "SwitchStatement.hpp"
#include "ThrowStatement.hpp"
#include "TryStatement.hpp"
#include "WhileStatement.hpp"

// declarations
#include "CastDeclaration.hpp"
#include "ClassDeclaration.hpp"
#include "ConstructorDeclaration.hpp"
#include "EventDeclaration.hpp"
#include "EventParameterDeclaration.hpp"
#include "EventTypeDeclaration.hpp"
#include "FunctionDeclaration.hpp"
#include "GetterDeclaration.hpp"
#include "MethodDeclaration.hpp"
#include "OperatorDeclaration.hpp"
#include "PackageDeclaration.hpp"
#include "PropertyDeclaration.hpp"
#include "SetterDeclaration.hpp"
#include "VariableDeclaration.hpp"
#include "VariableFragment.hpp"

// symbols
#include "QualifiedName.hpp"
#include "SimpleName.hpp"
/*
#include "ClassSymbol.hpp"
#include "ConstructorSymbol.hpp"
#include "EtypeSymbol.hpp"
#include "EventSymbol.hpp"
#include "FuncSymbol.hpp"
#include "LibrarySymbol.hpp"
#include "PackageSymbol.hpp"
#include "ParamSymbol.hpp"
#include "VarSymbol.hpp"
*/
// scope and symbol table
#include "SymbolTable.hpp"
namespace hydro::compiler
{
class ASTVisitor;

class AST final
{
private:
    AST();

public:
    virtual ~AST();
    Assignment *createAssignment(Token token);
    BinaryExpression *createBinaryExpression(Token token);
    BinaryLiteral *createBinaryLiteral(Token token);
    Block *createBlock(Token token);
    BooleanLiteral *createBooleanLiteral(Token token);
    BreakStatement *createBreakStatement(Token token);
    CaseClause *createCaseClause(Token token);
    CastDeclaration *createCastDeclaration(Token token, Modifiers *modifiers);
    DefaultClause *createDefaultClause(Token token);
    DictionaryEntry *createDictionaryEntry();
    DictionaryInitializer *createDictionaryInitializer(Token token);
    DoStatement *createDoStatement(Token token);
    DoubleLiteral *createDoubleLiteral(Token token);
    EmptyExpression *createEmptyExpression();
    EmptyStatement *createEmptyStatement();
    EventDeclaration *createEventDeclaration(Token token, Modifiers *modifiers);
    EventTypeDeclaration *createEventTypeDeclaration(Token token);
    EventParameterDeclaration *createEventParameterDeclaration(Token token);
    ExpressionStatement *createExpressionStatement();
    FloatLiteral *createFloatLiteral(Token token);
    ForEachStatement *createForEachStatement(Token token);
    ForStatement *createForStatement(Token token);
    FunctionArgument *createFunctionArgument(Token token);
    FunctionArgumentsList *createFunctionArgumentsList(Token token);
    GetterDeclaration *createGetterDeclaration(Token token);
    HexadecimalLiteral *createHexadecimalLiteral(Token token);
    Identifier *createIdentifier(Token token, SimpleName *name);
    IfStatement *createIfStatement(Token token);
    ImportDeclaration *createImportDeclaration(Token token);
    Invocation *createInvocation(Token token);
    InvocationArguments *createInvocationArguments(Token token);
    JsonInitializer *createJsonInitializer(Token token);
    JsonMember *createJsonMember();
    LambdaExpression *createLambdaExpression(Token token);
    ListInitializer *createListInitializer(Token token);
    LongLiteral *createLongLiteral(Token token);
    MethodDeclaration *createMethodDeclaration(Token token, Modifiers *modifiers);
    NestedExpression *createNestedExpression(Token token);
    NullLiteral *createNullLiteral(Token token);
    ObjectInitializer *createObjectInitializer(Token token);
    ObjectMember *createObjectMember(Token token);
    OperatorDeclaration *createOperatorDeclaration(Token token, Modifiers *modifiers);
    PackageDeclaration *createPackageDeclaration(Token token);
    PostfixExpression *createPostfixExpression(Token token);
    PropertyDeclaration *createPropertyDeclaration(Token token, Modifiers *modifiers);
    QualifiedName *createQualifiedName(Name *qualifier, SimpleName *name);
    RegularExpressionLiteral *createRegularExpressionLiteral(Token token);
    ReturnStatement *createReturnStatement(Token token);
    SetterDeclaration *createSetterDeclaration(Token token);
    ShortLiteral *createShortLiteral(Token token);
    SimpleName *createSimpleName(Token token);
    StateDeclaration *createStateDeclaration(Token token, Modifiers *modifiers);
    StringExpression *createStringExpression(Token token);
    StringLiteral *createStringLiteral(Token token);
    SubscriptExpression *createSubscriptExpression(Token token);
    SuperConstructorInvocation *createSuperConstructorInvocation(Token token);
    SuperMethodInvocation *createSuperMethodInvocation(Token token);
    SwitchStatement *createSwitchStatement(Token token);
    TernaryExpression *createTernaryExpression(Token token);
    ThrowStatement *createThrowStatement(Token token);
    TryStatement *createTryStatement(Token token);
    UnaryExpression *createUnaryExpression(Token token);
    Undefined *createUndefined(Token token);
    UnsignedIntegerLiteral *createUnsignedIntegerLiteral(Token token);
    UnsignedLongLiteral *createUnsignedLongLiteral(Token token);
    UnsignedShortLiteral *createUnsignedShortLiteral(Token token);
    VariableDeclaration *createVariableDeclaration(Token token);
    VariableExpression *createVariableExpression(Token token);
    VariableFragment *createVariableFragment(Token token);
    WhileStatement *createWhileStatement(Token token);

    Scope *createScope();
    Scope *createScope(std::string name);
    Scope *createScope(Scope *enclosingScope);
    Scope *createScope(std::string name, Scope *enclosingScope);

    const std::list<ASTNode *> &nodes() const { return m_nodes; }
    const std::list<Scope *> &scopes() const { return m_scopes; }

private:
    std::list<ASTNode *> m_nodes;
    std::list<Scope *> m_scopes;

    template <typename T, typename... Args>
    T *createNode(Args... args)
    {
        T *node = new T{this, args...};
        m_nodes.push_back(node);
        return node;
    }

    template <typename T, typename... Args>
    T *createNode(Token token, Args... args)
    {
        T *node = new T{this, args...};
        node->token = token;
        m_nodes.push_back(node);
        return node;
    }

    friend class ASTNode;
};

} // namespace hydro::compiler

#endif /* __h3o_AST__ */
