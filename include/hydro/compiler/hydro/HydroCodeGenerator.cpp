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

#include "HydroCodeGenerator.hpp"

namespace hydro::compiler
{
void HydroCodeGenerator::visit(CompilationUnit *compilationUnit)
{
}

void HydroCodeGenerator::visit(ASTNode *node)
{
}

void HydroCodeGenerator::visit(SimpleName *name)
{
}

void HydroCodeGenerator::visit(QualifiedName *name)
{
}

void HydroCodeGenerator::visit(Identifier *expr)
{
}

void HydroCodeGenerator::visit(Undefined *expr)
{
}

void HydroCodeGenerator::visit(NullLiteral *expr)
{
}

void HydroCodeGenerator::visit(BooleanLiteral *expr)
{
}

void HydroCodeGenerator::visit(CharacterLiteral *expr)
{
}

void HydroCodeGenerator::visit(StringLiteral *expr)
{
}

void HydroCodeGenerator::visit(BinaryLiteral *expr)
{
}

void HydroCodeGenerator::visit(HexadecimalLiteral *expr)
{
}

void HydroCodeGenerator::visit(UnsignedIntegerLiteral *expr)
{
}

void HydroCodeGenerator::visit(IntegerLiteral *expr)
{
}

void HydroCodeGenerator::visit(UnsignedShortLiteral *expr)
{
}

void HydroCodeGenerator::visit(ShortLiteral *expr)
{
}

void HydroCodeGenerator::visit(UnsignedLongLiteral *expr)
{
}

void HydroCodeGenerator::visit(LongLiteral *expr)
{
}

void HydroCodeGenerator::visit(FloatLiteral *expr)
{
}

void HydroCodeGenerator::visit(DoubleLiteral *expr)
{
}

void HydroCodeGenerator::visit(RegularExpressionLiteral *expr)
{
}

void HydroCodeGenerator::visit(ObjectInitializer *expr)
{
}

void HydroCodeGenerator::visit(JsonInitializer *expr)
{
}

void HydroCodeGenerator::visit(ListInitialzier *expr)
{
}

void HydroCodeGenerator::visit(LambdaExpression *expr)
{
}

void HydroCodeGenerator::visit(UnaryExpression *expr)
{
}

void HydroCodeGenerator::visit(BinaryExpression *expr)
{
}

void HydroCodeGenerator::visit(TernaryExpression *expr)
{
}

void HydroCodeGenerator::visit(Invocation *expr)
{
}

void HydroCodeGenerator::visit(InvocationArguments *expr)
{
}

void HydroCodeGenerator::visit(SuperConstructorInvocation *expr)
{
}

void HydroCodeGenerator::visit(SuperMethodInvocation *expr)
{
}

void HydroCodeGenerator::visit(SuperPropertyReference *expr)
{
}

void HydroCodeGenerator::visit(Assignment *expr)
{
}

void HydroCodeGenerator::visit(VariableExpression *expr)
{
}

void HydroCodeGenerator::visit(ThisExpression *expr)
{
}

void HydroCodeGenerator::visit(EmptyStatement *stmt)
{
}

void HydroCodeGenerator::visit(ExprStatement *stmt)
{
}

void HydroCodeGenerator::visit(IfStatement *stmt)
{
}

void HydroCodeGenerator::visit(ElseStatement *stmt)
{
}

void HydroCodeGenerator::visit(ThrowStatement *stmt)
{
}

void HydroCodeGenerator::visit(TryStatement *stmt)
{
}

void HydroCodeGenerator::visit(CatchClause *stmt)
{
}

void HydroCodeGenerator::visit(SwitchStatement *stmt)
{
}

void HydroCodeGenerator::visit(CaseClause *stmt)
{
}

void HydroCodeGenerator::visit(DefaultClause *stmt)
{
}

void HydroCodeGenerator::visit(BreakStatement *stmt)
{
}

void HydroCodeGenerator::visit(ContinueStatement *stmt)
{
}

void HydroCodeGenerator::visit(ForStatement *stmt)
{
}

void HydroCodeGenerator::visit(ForEachStatement *stmt)
{
}

void HydroCodeGenerator::visit(DoStatement *stmt)
{
}

void HydroCodeGenerator::visit(WhileStatement *stmt)
{
}

// declarations
void HydroCodeGenerator::visit(ImportDeclaration *decl)
{
}

void HydroCodeGenerator::visit(VariableDeclaration *decl)
{
}

void HydroCodeGenerator::visit(VariableFragment *decl)
{
}

void HydroCodeGenerator::visit(FunctionDeclaration *decl)
{
}

void HydroCodeGenerator::visit(ClassDeclaration *decl)
{
}

void HydroCodeGenerator::visit(ConstructorDeclaration *decl)
{
}

void HydroCodeGenerator::visit(PropertyDeclaration *decl)
{
}

void HydroCodeGenerator::visit(GetterDeclaration *decl)
{
}

void HydroCodeGenerator::visit(SetterDeclaration *decl)
{
}

void HydroCodeGenerator::visit(MethodDeclaration *decl)
{
}

void HydroCodeGenerator::visit(OperatorDeclaration *decl)
{
}

void HydroCodeGenerator::visit(CastDeclaration *delc)
{
}

void HydroCodeGenerator::visit(InterfaceDeclaration *decl)
{
}

void HydroCodeGenerator::visit(EventDeclaration *decl)
{
}

void HydroCodeGenerator::visit(EtypeDeclaration *decl)
{
}

void HydroCodeGenerator::visit(EventParameterDeclaration *decl)
{
}

void HydroCodeGenerator::visit(StateDeclaration *decl)
{
}

} // namespace hydro::compiler
