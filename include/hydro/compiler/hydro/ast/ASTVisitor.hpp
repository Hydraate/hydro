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

#ifndef __h3o_ASTVisitor__
#define __h3o_ASTVisitor__

namespace hydro::compiler
{
class ASTVisitor
{
public:
    ASTVisitor() {}
    virtual ~ASTVisitor() {}

    virtual void visit(class CompilationUnit *compilationUnit) = 0;
    virtual void visit(class ASTNode *node) = 0;
    virtual void visit(class SimpleName *name) = 0;
    virtual void visit(class QualifiedName *name) = 0;

    // expressions
    virtual void visit(class Identifier *expr) = 0;
    virtual void visit(class Undefined *expr) = 0;
    virtual void visit(class NullLiteral *expr) = 0;
    virtual void visit(class BooleanLiteral *expr) = 0;
    virtual void visit(class CharacterLiteral *expr) = 0;
    virtual void visit(class StringLiteral *expr) = 0;
    virtual void visit(class BinaryLiteral *expr) = 0;
    virtual void visit(class HexadecimalLiteral *expr) = 0;
    virtual void visit(class UnsignedIntegerLiteral *expr) = 0;
    virtual void visit(class IntegerLiteral *expr) = 0;
    virtual void visit(class UnsignedShortLiteral *expr) = 0;
    virtual void visit(class ShortLiteral *expr) = 0;
    virtual void visit(class UnsignedLongLiteral *expr) = 0;
    virtual void visit(class LongLiteral *expr) = 0;
    virtual void visit(class FloatLiteral *expr) = 0;
    virtual void visit(class DoubleLiteral *expr) = 0;
    virtual void visit(class RegularExpressionLiteral *expr) = 0;
    virtual void visit(class ObjectInitializer *expr) = 0;
    virtual void visit(class JsonInitializer *expr) = 0;
    virtual void visit(class ListInitialzier *expr) = 0;
    virtual void visit(class LambdaExpression *expr) = 0;
    virtual void visit(class UnaryExpression *expr) = 0;
    virtual void visit(class BinaryExpression *expr) = 0;
    virtual void visit(class TernaryExpression *expr) = 0;
    virtual void visit(class Invocation *expr) = 0;
    virtual void visit(class InvocationArguments *expr) = 0;
    virtual void visit(class SuperConstructorInvocation *expr) = 0;
    virtual void visit(class SuperMethodInvocation *expr) = 0;
    virtual void visit(class SuperPropertyReference *expr) = 0;
    virtual void visit(class Assignment *expr) = 0;
    virtual void visit(class VariableExpression *expr) = 0;
    virtual void visit(class ThisExpression *expr) = 0;

    // statements
    virtual void visit(class EmptyStatement *stmt) = 0;
    virtual void visit(class ExprStatement *stmt) = 0;
    virtual void visit(class IfStatement *stmt) = 0;
    virtual void visit(class ElseStatement *stmt) = 0;
    virtual void visit(class ThrowStatement *stmt) = 0;
    virtual void visit(class TryStatement *stmt) = 0;
    virtual void visit(class CatchClause *stmt) = 0;
    virtual void visit(class SwitchStatement *stmt) = 0;
    virtual void visit(class CaseClause *stmt) = 0;
    virtual void visit(class DefaultClause *stmt) = 0;
    virtual void visit(class BreakStatement *stmt) = 0;
    virtual void visit(class ContinueStatement *stmt) = 0;
    virtual void visit(class ForStatement *stmt) = 0;
    virtual void visit(class ForEachStatement *stmt) = 0;
    virtual void visit(class DoStatement *stmt) = 0;
    virtual void visit(class WhileStatement *stmt) = 0;

    // declarations
    virtual void visit(class ImportDeclaration *decl) = 0;
    virtual void visit(class VariableDeclaration *decl) = 0;
    virtual void visit(class VariableFragment *decl) = 0;
    virtual void visit(class FunctionDeclaration *decl) = 0;
    virtual void visit(class ClassDeclaration *decl) = 0;
    virtual void visit(class ConstructorDeclaration *decl) = 0;
    virtual void visit(class PropertyDeclaration *decl) = 0;
    virtual void visit(class GetterDeclaration *decl) = 0;
    virtual void visit(class SetterDeclaration *decl) = 0;
    virtual void visit(class MethodDeclaration *decl) = 0;
    virtual void visit(class OperatorDeclaration *decl) = 0;
    virtual void visit(class CastDeclaration *delc) = 0;
    virtual void visit(class InterfaceDeclaration *decl) = 0;
    virtual void visit(class EventDeclaration *decl) = 0;
    virtual void visit(class EtypeDeclaration *decl) = 0;
    virtual void visit(class EventParameterDeclaration *decl) = 0;
    virtual void visit(class StateDeclaration *decl) = 0;
};

} // namespace hydro::compiler

#endif /* __h3o_ASTVisitor__ */
