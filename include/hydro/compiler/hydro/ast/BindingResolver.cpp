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

#include "BindingResolver.hpp"

namespace hydro::compiler
{
BindingResolver::BindingResolver(Compiler *compiler) {}

BindingResolver::~BindingResolver() {}

Binding *BindingResolver::resolve(Name *name)
{
    // fail
    return nullptr;
}

void BindingResolver::visit(CompilationUnit *compilationUnit)
{
}

void BindingResolver::visit(ASTNode *node)
{
}

void BindingResolver::visit(SimpleName *name)
{
}

void BindingResolver::visit(QualifiedName *name)
{
}

void BindingResolver::visit(Identifier *expr)
{
}

void BindingResolver::visit(Undefined *expr)
{
}

void BindingResolver::visit(NullLiteral *expr)
{
}

void BindingResolver::visit(BooleanLiteral *expr)
{
}

void BindingResolver::visit(CharacterLiteral *expr)
{
}

void BindingResolver::visit(StringLiteral *expr)
{
}

void BindingResolver::visit(BinaryLiteral *expr)
{
}

void BindingResolver::visit(HexadecimalLiteral *expr)
{
}

void BindingResolver::visit(UnsignedIntegerLiteral *expr)
{
}

void BindingResolver::visit(IntegerLiteral *expr)
{
}

void BindingResolver::visit(UnsignedShortLiteral *expr)
{
}

void BindingResolver::visit(ShortLiteral *expr)
{
}

void BindingResolver::visit(UnsignedLongLiteral *expr)
{
}

void BindingResolver::visit(LongLiteral *expr)
{
}

void BindingResolver::visit(FloatLiteral *expr)
{
}

void BindingResolver::visit(DoubleLiteral *expr)
{
}

void BindingResolver::visit(RegularExpressionLiteral *expr)
{
}

void BindingResolver::visit(ObjectInitializer *expr)
{
}

void BindingResolver::visit(JsonInitializer *expr)
{
}

void BindingResolver::visit(ListInitialzier *expr)
{
}

void BindingResolver::visit(LambdaExpression *expr)
{
}

void BindingResolver::visit(UnaryExpression *expr)
{
}

void BindingResolver::visit(BinaryExpression *expr)
{
}

void BindingResolver::visit(TernaryExpression *expr)
{
}

void BindingResolver::visit(Invocation *expr)
{
}

void BindingResolver::visit(InvocationArguments *expr)
{
}

void BindingResolver::visit(SuperConstructorInvocation *expr)
{
}

void BindingResolver::visit(SuperMethodInvocation *expr)
{
}

void BindingResolver::visit(SuperPropertyReference *expr)
{
}

void BindingResolver::visit(Assignment *expr)
{
}

void BindingResolver::visit(VariableExpression *expr)
{
}

void BindingResolver::visit(ThisExpression *expr)
{
}

void BindingResolver::visit(EmptyStatement *stmt)
{
}

void BindingResolver::visit(ExprStatement *stmt)
{
}

void BindingResolver::visit(IfStatement *stmt)
{
}

void BindingResolver::visit(ElseStatement *stmt)
{
}

void BindingResolver::visit(ThrowStatement *stmt)
{
}

void BindingResolver::visit(TryStatement *stmt)
{
}

void BindingResolver::visit(CatchClause *stmt)
{
}

void BindingResolver::visit(SwitchStatement *stmt)
{
}

void BindingResolver::visit(CaseClause *stmt)
{
}

void BindingResolver::visit(DefaultClause *stmt)
{
}

void BindingResolver::visit(BreakStatement *stmt)
{
}

void BindingResolver::visit(ContinueStatement *stmt)
{
}

void BindingResolver::visit(ForStatement *stmt)
{
}

void BindingResolver::visit(ForEachStatement *stmt)
{
}

void BindingResolver::visit(DoStatement *stmt)
{
}

void BindingResolver::visit(WhileStatement *stmt)
{
}

// declarations
void BindingResolver::visit(ImportDeclaration *decl)
{
}

void BindingResolver::visit(VariableDeclaration *decl)
{
}

void BindingResolver::visit(VariableFragment *decl)
{
}

void BindingResolver::visit(FunctionDeclaration *decl)
{
}

void BindingResolver::visit(ClassDeclaration *decl)
{
}

void BindingResolver::visit(ConstructorDeclaration *decl)
{
}

void BindingResolver::visit(PropertyDeclaration *decl)
{
}

void BindingResolver::visit(GetterDeclaration *decl)
{
}

void BindingResolver::visit(SetterDeclaration *decl)
{
}

void BindingResolver::visit(MethodDeclaration *decl)
{
}

void BindingResolver::visit(OperatorDeclaration *decl)
{
}

void BindingResolver::visit(CastDeclaration *delc)
{
}

void BindingResolver::visit(InterfaceDeclaration *decl)
{
}

void BindingResolver::visit(EventDeclaration *decl)
{
}

void BindingResolver::visit(EtypeDeclaration *decl)
{
}

void BindingResolver::visit(EventParameterDeclaration *decl)
{
}

void BindingResolver::visit(StateDeclaration *decl)
{
}

} // namespace hydro::compiler
