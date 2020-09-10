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

#include "Document.hpp"

namespace hydro::engine
{
Document::Document()
    : Entity{}
{
    mDocument = this;
}

Document::~Document()
{
    // delete all nodes
    for(auto node : mNodes)
        delete node;
    
    // delete all symbols
    for(auto symbol : mSymbols)
        delete symbol;
}

Document *Document::create()
{
    return new Document{};
}

SimpleName *Document::createSimpleName(compiler::Token token)
{
    return appendNode(new SimpleName{ token });
}

QualifiedName *Document::createQualifiedName(Name *qualifier, compiler::Token token, SimpleName *name)
{
    return appendNode(new QualifiedName{ qualifier, token, name });
}

Relationship *Document::createRelationship(Name *name)
{
    return appendNode(new Relationship{ name });
}

IdentityRelationshipsList *Document::createRelationshipsList()
{
    return appendNode(new IdentityRelationshipsList{});
}

Attribute *Document::createAttribute(Name *name, Value *value)
{
    return appendNode(new Attribute{ name, value });
}

Mirror *Document::createMirror(Name *name, Value *value)
{
    return appendNode(new Mirror{ name, value });
}

WhenBinding *Document::createWhenBinding(compiler::Token token, Expression *condition)
{
    return appendNode(new WhenBinding{ token, condition });
}

WhileBinding *Document::createWhileBinding(compiler::Token token, Expression *condition)
{
    return appendNode(new WhileBinding{ token, condition });
}

ElementClass *Document::createElementClass(Name *name)
{
    return appendNode(new ElementClass{ name });
}

ElementID *Document::createElementID(compiler::Token token)
{
    return appendNode(new ElementID{ token });
}

ElementIdentity *Document::createElementIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass, ElementID *id)
{
    return appendNode(new ElementIdentity{ relationships, elementClass, id });
}

Element *Document::createElement(Entity *parent, ElementIdentity *identity)
{
    return appendNode(new Element{ parent, identity });
}

PrototypeIdentity *Document::createPrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass, ElementClass *parentClass)
{
    return appendNode(new PrototypeIdentity{ relationships, elementClass, parentClass });
}

Prototype *Document::createPrototype(Entity *parent, PrototypeIdentity *identity)
{
    return appendNode(new Prototype{ parent, identity });
}

PrototypeSymbol *Document::createPrototypeSymbol(ElementClass *elementClass)
{
    return appendSymbol(new PrototypeSymbol{ elementClass->getName()->getValue() });
}

ElementReference *Document::createElementReference(ElementClass *elementClass, ElementID *id)
{
    return appendNode(new ElementReference{ elementClass, id });
}

ProcedureClass *Document::createProcedureClass(Name *name)
{
    return appendNode(new ProcedureClass{ name });
}

ProcedureIdentity *Document::createProcedureIdentity(IdentityRelationshipsList *relationships, ProcedureClass *procedureClass)
{
    return appendNode(new ProcedureIdentity{ relationships, procedureClass });
}

Procedure *Document::createProcedure(Entity *parent, ProcedureIdentity *identity)
{
    return appendNode(new Procedure{ parent, identity });
}

ProcedureSymbol *Document::createProcedureSymbol(ProcedureClass *procedureClass)
{
    return appendSymbol(new ProcedureSymbol{ procedureClass->getName()->getValue() });
}

ProcedureReference *Document::createProcedureReference(ProcedureClass *procedureClass)
{
    return appendNode(new ProcedureReference{ procedureClass });
}


SnapshotDomain *Document::createSnapshotDomain(Name *name)
{
    return appendNode(new SnapshotDomain{ name });
}

SnapshotIdentity *Document::createSnapshotIdentity(IdentityRelationshipsList *relationships, SnapshotDomain *domain)
{
    return appendNode(new SnapshotIdentity{ relationships, domain });
}

Snapshot *Document::createSnapshot(Entity *parent, SnapshotIdentity *identity)
{
    return appendNode(new Snapshot{ parent, identity });
}

SnapshotContextSymbol *Document::createSnapshotContextSymbol(SnapshotDomain *domain)
{
    return appendSymbol(new SnapshotContextSymbol{ domain->getName()->getValue() });
}

SnapshotReference *Document::createSnapshotReference(SnapshotDomain *domain)
{
    return appendNode(new SnapshotReference{ domain });
}

Keyframe *Document::createKeyframe(Entity *parent, TimePointLiteral *time, SnapshotIdentity *identity)
{
    return appendNode(new Keyframe{ parent, time, identity });
}

KeyframeReference *Document::createKeyframeReference(TimePointLiteral *time, SnapshotDomain *domain)
{
    return appendNode(new KeyframeReference{ time, domain });
}

EventClass *Document::createEventClass(Name *name)
{
    return appendNode(new EventClass{ name });
}

ActionIdentity *Document::createActionIdentity(IdentityRelationshipsList *relationships, EventClass *eventClass)
{
    return appendNode(new ActionIdentity{ relationships, eventClass });
}

Action *Document::createAction(Entity *parent, ActionIdentity *identity)
{
    return appendNode(new Action{ parent, identity });
}

ActionSymbol *Document::createActionSymbol(EventClass *eventClass)
{
    return appendSymbol(new ActionSymbol{ eventClass->getName()->getValue() });
}

ActionReference *Document::createActionReference(EventClass *eventClass)
{
    return appendNode(new ActionReference{ eventClass });
}

QueryTarget *Document::createQueryTarget(Selector *selector)
{
    return appendNode(new QueryTarget{ selector });
}

QueryIdentity *Document::createQueryIdentity(QueryTarget *target)
{
    return appendNode(new QueryIdentity{ target });
}

Query *Document::createQuery(Entity *parent, QueryIdentity *identity)
{
    return appendNode(new Query{ parent, identity });
}

InvocationTarget *Document::createInvocationTarget(Reference *reference)
{
    return appendNode(new InvocationTarget{ reference });
}

InvocationIdentity *Document::createInvocationIdentity(InvocationTarget *target)
{
    return appendNode(new InvocationIdentity{ target });
}

Invocation *Document::createInvocation(Entity *parent, InvocationIdentity *identity)
{
    return appendNode(new Invocation{ parent, identity });
}

InvocationReference *Document::createInvocationReference(InvocationTarget *target)
{
    return appendNode(new InvocationReference{ target });
}

UndefinedExpression *Document::createUndefined(compiler::Token token)
{
    return appendNode(new UndefinedExpression{ token });
}

NullExpression *Document::createNull(compiler::Token token)
{
    return appendNode(new NullExpression{ token });
}

BooleanLiteral *Document::createBoolean(compiler::Token token)
{
    return appendNode(new BooleanLiteral{ token });
}

NumberLiteral *Document::createNumber(compiler::Token token)
{
    return appendNode(new NumberLiteral{ token });
}

StringLiteral *Document::createString(compiler::Token token)
{
    return appendNode(new StringLiteral{ token });
}

ColorLiteral *Document::createColor(compiler::Token token)
{
    return appendNode(new ColorLiteral{ token });
}

PercentLiteral *Document::createPercent(compiler::Token token, NumberLiteral *value)
{
    return appendNode(new PercentLiteral{ token, value });
}

TimePointLiteral *Document::createTimePoint(NumberLiteral *min, NumberLiteral *secs, NumberLiteral *ms)
{
    return appendNode(new TimePointLiteral{ min, secs, ms });
}

TimePointLiteral *Document::createTimePoint(NumberLiteral *hrs, NumberLiteral *min, NumberLiteral *secs, NumberLiteral *ms)
{
    return appendNode(new TimePointLiteral{ hrs, min, secs, ms });
}

MultiplicityLiteral *Document::createMultiplicity(NumberLiteral *min, compiler::Token token, NumberLiteral *max)
{
    return appendNode(new MultiplicityLiteral{ min, max });
}

AttributeSelector *Document::createAttributeSelector(Name *name)
{
    return appendNode(new AttributeSelector{ name });
}

ElementSelector *Document::createElementSelector(ElementClass *elementClass, ElementID *id)
{
    return appendNode(new ElementSelector{ elementClass, id });
}

ProcedureSelector *Document::createProcedureSelector(ProcedureClass *procedureClass)
{
    return appendNode(new ProcedureSelector{ procedureClass });
}

SnapshotSelector *Document::createSnapshotSelector(SnapshotDomain *domain)
{
    return appendNode(new SnapshotSelector{ domain });
}

KeyframeSelector *Document::createKeyframeSelector(TimePointLiteral* time, SnapshotDomain *domain)
{
    return appendNode(new KeyframeSelector{ time, domain });
}

ActionSelector *Document::createActionSelector(EventClass *eventClass)
{
    return appendNode(new ActionSelector{ eventClass });
}

SelfSelector *Document::createSelfSelector(compiler::Token token)
{
    return appendNode(new SelfSelector{ token });
}

ParentSelector *Document::createParentSelector(compiler::Token token)
{
    return appendNode(new ParentSelector{ token });
}

RootSelector *Document::createRootSelector(compiler::Token token)
{
    return appendNode(new RootSelector{ token });
}

DocumentSelector *Document::createDocumentSelector(compiler::Token token)
{
    return appendNode(new DocumentSelector{ token });
}

ExponentiationExpression *Document::createExponentiation(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new ExponentiationExpression{ lhs, rhs });
}

MultiplicationExpression *Document::createMultiplication(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new MultiplicationExpression{ lhs, rhs });
}

DivisionExpression *Document::createDivision(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new DivisionExpression{ lhs, rhs });
}

RemainderExpression *Document::createRemainder(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new RemainderExpression{ lhs, rhs });
}

AdditionExpression *Document::createAddition(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new AdditionExpression{ lhs, rhs });
}

SubtractionExpression *Document::createSubtraction(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new SubtractionExpression{ lhs, rhs });
}

EqualityExpression *Document::createEquality(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new EqualityExpression{ lhs, rhs });
}

InequalityExpression *Document::createInequality(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new InequalityExpression{ lhs, rhs });
}

PositiveExpression *Document::createPositive(compiler::Token token, Expression *expression)
{
    return appendNode(new PositiveExpression{ expression });
}

NegationExpression *Document::createNegative(compiler::Token token, Expression *expression)
{
    return appendNode(new NegationExpression{ expression });
}

LogicalNOTExpression *Document::createLogicalNOT(compiler::Token token, Expression *expression)
{
    return appendNode(new LogicalNOTExpression{ expression });
}

BitwiseNOTExpression *Document::createBitwiseNOT(compiler::Token token, Expression *expression)
{
    return appendNode(new BitwiseNOTExpression{ expression });
}

NestedExpression *Document::createNested(compiler::Token token, Expression *expression)
{
    return appendNode(new NestedExpression{ token, expression });
}

LogicalANDExpression *Document::createLogicalAND(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new LogicalANDExpression{ lhs, rhs });
}

LogicalORExpression *Document::createLogicalOR(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new LogicalORExpression{ lhs, rhs });
}

GreaterThanExpression *Document::createGreaterThan(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new GreaterThanExpression{ lhs, rhs });
}

GreaterThanOrEqualExpression *Document::createGreaterThanOrEqual(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new GreaterThanOrEqualExpression{ lhs, rhs });
}

LessThanExpression *Document::createLessThan(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new LessThanExpression{ lhs, rhs });
}

LessThanOrEqualExpression *Document::createLessThanOrEqual(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new LessThanOrEqualExpression{ lhs, rhs });
}

BitwiseANDExpression *Document::createBitwiseAND(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new BitwiseANDExpression{ lhs, rhs });
}

BitwiseORExpression *Document::createBitwiseOR(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new BitwiseORExpression{ lhs, rhs });
}

BitwiseXORExpression *Document::createBitwiseXOR(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new BitwiseXORExpression{ lhs, rhs });
}

BitwiseLeftShiftExpression *Document::createBitwiseLeftShift(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new BitwiseLeftShiftExpression{ lhs, rhs });
}

BitwiseRightShiftExpression *Document::createBitwiseRightShift(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new BitwiseRightShiftExpression{ lhs, rhs });
}

MemberAccess *Document::createMemberAccess(Expression *subject, compiler::Token token, Expression *target)
{
    return appendNode(new MemberAccess{ subject, target });
}

SubscriptAccess *Document::createSubscriptAccess(Expression *lhs, compiler::Token token, Expression *rhs)
{
    return appendNode(new SubscriptAccess{ lhs, token, rhs });
}

ChildSelector *Document::createChildSelector(Selector *subject, compiler::Token token, Selector *target)
{
    return appendNode(new ChildSelector{ subject, target });
}

DescendantSelector *Document::createDescendantSelector(Selector *subject, compiler::Token token, Selector *target)
{
    return appendNode(new DescendantSelector{ subject, target });
}

IndexSelector *Document::createIndexSelector(Selector *subject, compiler::Token token, Expression *target)
{
    return appendNode(new IndexSelector{ subject, target });
}

ConditionalExpression *Document::createConditional(Expression *condition, Expression *trueExpression, Expression *falseExpression)
{
    return appendNode(new ConditionalExpression{ condition, trueExpression, falseExpression });
}

CompoundReference *Document::createCompoundReference(Reference *subject, compiler::Token token, SimpleReference *target)
{
    return appendNode(new CompoundReference{ subject, token, target });
}

} // namespace hydro::engine
