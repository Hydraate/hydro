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

#ifndef __h3o_HydroCodeGenerator__
#define __h3o_HydroCodeGenerator__

#include "ast/ASTVisitor.hpp"

namespace hydro::compiler
{
class HydroCodeGenerator : ASTVisitor
{
public:
private:
    virtual void visit(CompilationUnit *compilationUnit) override;
    virtual void visit(ASTNode *node) override;
    virtual void visit(SimpleName *name) override;
    virtual void visit(QualifiedName *name) override;
    virtual void visit(Identifier *expr) override;
    virtual void visit(Undefined *expr) override;
    virtual void visit(NullLiteral *expr) override;
    virtual void visit(BooleanLiteral *expr) override;
    virtual void visit(CharacterLiteral *expr) override;
    virtual void visit(StringLiteral *expr) override;
    virtual void visit(BinaryLiteral *expr) override;
    virtual void visit(HexadecimalLiteral *expr) override;
    virtual void visit(UnsignedIntegerLiteral *expr) override;
    virtual void visit(IntegerLiteral *expr) override;
    virtual void visit(UnsignedShortLiteral *expr) override;
    virtual void visit(ShortLiteral *expr) override;
    virtual void visit(UnsignedLongLiteral *expr) override;
    virtual void visit(LongLiteral *expr) override;
    virtual void visit(FloatLiteral *expr) override;
    virtual void visit(DoubleLiteral *expr) override;
    virtual void visit(RegularExpressionLiteral *expr) override;
    virtual void visit(ObjectInitializer *expr) override;
    virtual void visit(JsonInitializer *expr) override;
    virtual void visit(ListInitialzier *expr) override;
    virtual void visit(LambdaExpression *expr) override;
    virtual void visit(UnaryExpression *expr) override;
    virtual void visit(BinaryExpression *expr) override;
    virtual void visit(TernaryExpression *expr) override;
    virtual void visit(Invocation *expr) override;
    virtual void visit(InvocationArguments *expr) override;
    virtual void visit(SuperConstructorInvocation *expr) override;
    virtual void visit(SuperMethodInvocation *expr) override;
    virtual void visit(SuperPropertyReference *expr) override;
    virtual void visit(Assignment *expr) override;
    virtual void visit(VariableExpression *expr) override;
    virtual void visit(ThisExpression *expr) override;
    virtual void visit(EmptyStatement *stmt) override;
    virtual void visit(ExprStatement *stmt) override;
    virtual void visit(IfStatement *stmt) override;
    virtual void visit(ElseStatement *stmt) override;
    virtual void visit(ThrowStatement *stmt) override;
    virtual void visit(TryStatement *stmt) override;
    virtual void visit(CatchClause *stmt) override;
    virtual void visit(SwitchStatement *stmt) override;
    virtual void visit(CaseClause *stmt) override;
    virtual void visit(DefaultClause *stmt) override;
    virtual void visit(BreakStatement *stmt) override;
    virtual void visit(ContinueStatement *stmt) override;
    virtual void visit(ForStatement *stmt) override;
    virtual void visit(ForEachStatement *stmt) override;
    virtual void visit(DoStatement *stmt) override;
    virtual void visit(WhileStatement *stmt) override;

    // declarations
    virtual void visit(ImportDeclaration *decl) override;
    virtual void visit(VariableDeclaration *decl) override;
    virtual void visit(VariableFragment *decl) override;
    virtual void visit(FunctionDeclaration *decl) override;
    virtual void visit(ClassDeclaration *decl) override;
    virtual void visit(ConstructorDeclaration *decl) override;
    virtual void visit(PropertyDeclaration *decl) override;
    virtual void visit(GetterDeclaration *decl) override;
    virtual void visit(SetterDeclaration *decl) override;
    virtual void visit(MethodDeclaration *decl) override;
    virtual void visit(OperatorDeclaration *decl) override;
    virtual void visit(CastDeclaration *delc) override;
    virtual void visit(InterfaceDeclaration *decl) override;
    virtual void visit(EventDeclaration *decl) override;
    virtual void visit(EtypeDeclaration *decl) override;
    virtual void visit(EventParameterDeclaration *decl) override;
    virtual void visit(StateDeclaration *decl) override;
};

} // namespace hydro::compiler

#endif /* __h3o_HydroCodeGenerator__ */
