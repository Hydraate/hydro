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

#ifndef __h3o_internal_HydroParser__
#define __h3o_internal_HydroParser__

// parser
#include "../Compiler.hpp"
#include "../Parser.hpp"
#include "HydroLexer.hpp"
#include "ast/AST.hpp"
#include "hvm_compile_errors.hpp"

namespace hydro::compiler
{
/*
class HydroParser final : public Parser
{
public:
    HydroParser(Compiler *compiler, Scope *globals);
    virtual ~HydroParser();

protected:
    virtual void parseFromCurrentToken() override;
    virtual void onParseInit() override;
    virtual void reset() override;

private:
    Scope *mGlobalScope;
    Scope *m_moduleScope;
    AST *mAST;
    CompilationUnit *m_compilationUnit;
    std::stack<ASTNode *> m_nodeStack;

    // speculation
    bool specAllowLine();
    bool specID();
    bool specBool();
    bool specChar();
    bool specString();
    bool specStringTemplate();
    bool specBinary();
    bool specHexadecimal();
    bool specOctal();
    bool specUshort();
    bool specShort();
    bool specUint();
    bool specInt();
    bool specUlong();
    bool specLong();
    bool specFloat();
    bool specDouble();
    bool specNumber();
    bool specNaN();
    bool specInfinity();
    bool specNull();
    bool specUndefined();
    bool specIdentityRef();
    bool specPackageRef();
    bool specDirective();
    bool specExpr(int minPrec);
    bool specExpr();
    bool assumeOpnd();
    bool specOpnd();
    bool specUnaryOp();
    bool assumeUnaryOp();
    bool assumeObject();
    bool specObject();
    bool assumeJson();
    bool specJson();
    bool assumeArray();
    bool specArray();
    bool assumeDict();
    bool specDict();
    bool assumeRegex();
    bool specRegex();
    bool assumeXml();
    bool specXml();
    bool specNestedExpr();
    bool assumeTuple();
    bool specTuple();
    bool assumeNamedTuple();
    bool specNamedTuple();
    bool assumeNamedArgs();
    
    // other expressions
    bool specAfunc(); // anonymous function

    // control structure speculation
    bool specEos();
    bool specStmt();
    bool specBlock();
    bool specNilBlock();
    bool specIf();
    bool specElseIf();
    bool specElse();
    bool specWhile();
    bool specDoWhile();
    bool specAlways(); // ?
    bool specFor();
    bool specForIn();
    bool specForEachIn();
    bool specSwitch();
    bool specCase();
    bool specDefault();
    bool specBreak();
    bool specTry();
    bool specCatch();
    bool assumeThrow();

    // statement speculation
    bool specImport();

    // declaration speculation
    bool isModifier(std::string);
    bool specModifiers(bool modRequired = false);
    bool specPackage();
    bool specLibrary();
    bool specVar();
    bool assumeFunc();
    bool assumeAnonymousFunc();
    bool assumeAction();
    bool assumeAnonymousAction();
    bool assumeReturn();
    bool assumeEtype();
    bool assumeEvent();
    bool assumeParam();
    bool assumeClass();
    bool specProperty();
    bool specGetter();
    bool specSetter();
    bool specConstructor();
    bool specMethod();
    bool specEvent();
    bool specEtype();
    bool specAttribute();

    // operator precedence table
    int binaryPrec(token_t op);
    int binaryPrec(std::string op);
    int binaryAssoc(token_t op);
    int binaryAssoc(std::string op);
    bool isBinaryOp(token_t op);
    bool isBinaryOp(std::string op);
    int unaryPrec(token_t op);
    int unaryPrec(std::string op);
    int postfixPrec(token_t op);
    int postfixPrec(std::string op);
    bool isPostfix(token_t op);
    bool isPostfix(std::string op);

    // parsing
    Expression *computeExpr();
    Expression *computeExpr(int minPrec);
    Expression *emptyExpr(); // helper
    Expression *parseOpnd();
    StringExpression *buildString(std::vector<token_t> &stringTokens);
    StringLiteral *parseString();
    SimpleName *parseSimpleName();
    QualifiedName *parseQualifiedName();
    Name *parseName();
    Name *parseID();
    UnaryExpression *parseUnaryExpr();
    BinaryExpression *parseBinaryExpr(Expression *lhs, token_t token, Expression *rhs);
    InvocationArguments *parseInvocationArgs();
    NamedInvocationArguments *parseNamedInvocationArgs();
    NestedExpression *parseNested();
    TupleInitializer *parseTuple();
    NamedTupleInitializer *parseNamedTuple();
    ObjectInitializer *parseObject();
    JsonInitializer *parseJson();
    Expression *parseJsonValue();
    ListInitialzier *parseJsonArray();
    ListInitialzier *parseList();
    DictionaryInitializer *parseDict();
    RegularExpressionLiteral *parseRegex();
    XmlInitializer *parseXml();

    // parsing
    void parseEos();
    Statement *parseStmt(bool eos = true);
    ImportStatement *parseImport();
    Modifiers *parseModifiers();
    VariableDeclaration *parseVar();
    void *parseTypeRef();
    void *parseImportType();
    void *parseTypeSpec();
    void *parseTypeDecl();
    Block *parseBlock();
    Statement *parseBody();
    IfStatement *parseIf();
    TryStatement *parseTry();
    CatchClause *parseCatch();
    ThrowStatement *parseThrow();
    BreakStatement *parseBreak();
    ContinueStatement *parseContinue();
    ForStatement *parseFor();
    ForEachStatement *parseForEach();
    DoStatement *parseDoWhile();
    WhileStatement *parseWhile();
    SwitchStatement *parseSwitch();
    CaseClause *parseCase();
    DefaultClause *parseDefault();
    PackageDeclaratino *parsePackage();
    //LibraryDecl *parseLibrary();
    FunctionDeclaration *parseFunc();
    LambdaExpression *parseLambda();
    FunctionArguments *parseFuncArgs();
    ReturnStatement *parseReturn();
    EventDeclaration *parseEvent();
    EventTypeDeclaration *parseEtype();
    EventParamaterDeclaration *parseParam();
    ClassDeclaration *parseClass();
    ConstructorDeclaration *parseConstructor();
    GetterDeclaration *parseGetter();
    SetterDeclaration *parseSetter();

    // package handlers and helpers
    PackageSymbol *buildPackageTree(Name *name, Scope *scope = nullptr);
    PackageSymbol *resolvePackage(Name *name, Scope *scopeToUse = nullptr);
    PackageSymbol *loadEnclosingPackage();
    PackageSymbol *loadParentPackage(Name *packageName);
    

    // class helpers
    ClassSymbol *getEnclosingClass();
    Symbol *getOwnerOf(Scope *scope);

};
*/

} // namespace hydro::compiler

#endif /* __h3o_internal_HydroParser__ */
