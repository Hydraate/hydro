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

#ifndef __h3o_engine_DocumentVisitor__
#define __h3o_engine_DocumentVisitor__

namespace hydro::engine
{

class Document;
class Element;
class ElementIdentity;
class ElementClass;
class ElementReference;
class Procedure;
class ProcedureIdentity;
class ProcedureClass;
class ProcedureReference;
class Snapshot;
class SnapshotIdentity;
class SnapshotDomain;
class SnapshotReference;
class Keyframe;
class KeyframeReference;
class Action;
class ActionIdentity;
class EventClass;
class ActionReference;
class Prototype;
class PrototypeIdentity;
class Invocation;
class InvocationIdentity;
class InvocationTarget;
class InvocationReference;
class Query;
class QueryIdentity;
class QueryTarget;
class Model;
class ModelIdentity;
class ModelDescription;
class CompoundReference;
class IdentityRelationshipsList;
class Attribute;
class Mirror;
class SimpleName;
class QualifiedName;
class ElementID;
class SelectorInitializer;
class AttributeSelector;
class ElementSelector;
class ProcedureSelector;
class InvocationSelector;
class SnapshotSelector;
class KeyframeSelector;
class ActionSelector;
class ChildSelector;
class DescendantSelector;
class IndexSelector;
class SelfSelector;
class ParentSelector;
class RootSelector;
class DocumentSelector;
class UndefinedExpression;
class NullExpression;
class BooleanLiteral;
class ColorLiteral;
class MultiplicityLiteral;
class NumberLiteral;
class TimePointLiteral;
class PercentLiteral;
class StringLiteral;
class NestedExpression;
class LogicalNOTExpression;
class BitwiseNOTExpression;
class PositiveExpression;
class NegationExpression;
class ExponentiationExpression;
class MultiplicationExpression;
class DivisionExpression;
class RemainderExpression;
class AdditionExpression;
class SubtractionExpression;
class EqualityExpression;
class InequalityExpression;
class GreaterThanExpression;
class GreaterThanOrEqualExpression;
class LessThanExpression;
class LessThanOrEqualExpression;
class LogicalANDExpression;
class BitwiseANDExpression;
class LogicalORExpression;
class BitwiseORExpression;
class BitwiseXORExpression;
class BitwiseLeftShiftExpression;
class BitwiseRightShiftExpression;
class MemberAccess;
class SubscriptAccess;
class ConditionalExpression;
class WhenBinding;
class WhileBinding;

/**
 * The abstract DocumentVisitor class implements the Visitor pattern for Performance documents.
 *
 * The Visitor pattern is flexible and and necessary to decouple a document node's usage from its representation. The visitor determines how nested nodes and children will be visited rather than the visited node. Nodes should not have a predetermined way of visiting nested nodes.
 */
class DocumentVisitor
{
public:
    /**
     * Visits a document entity.
     * @param document The document to visit.
     */
    virtual void visit(Document *document) = 0;
    
    /**
     * Visits an element entity.
     * @param element The element to visit.
     */
    virtual void visit(Element *element) = 0;
    
    /**
     * Visits an element identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ElementIdentity *identity) = 0;
    
    /**
     * Visits an element class.
     * @param _class The class to visit.
     */
    virtual void visit(ElementClass *_class) = 0;
    
    /**
     * Visits an element reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ElementReference *reference) = 0;
    
    /**
     * Visits a procedure entity.
     * @param procedure The procedure to visit.
     */
    virtual void visit(Procedure *procedure) = 0;

    /**
     * Visits a procedure identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ProcedureIdentity *identity) = 0;

    /**
     * Visits a procedure class.
     * @param _class The class to visit.
     */
    virtual void visit(ProcedureClass *_class) = 0;

    /**
     * Visits a procedure reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ProcedureReference *reference) = 0;
    
    /**
     * Visits a snapshot entity.
     * @param snapshot The document to visit.
     */
    virtual void visit(Snapshot *snapshot) = 0;
    
    /**
     * Visits a snapshot identity.
     * @param identity The identity to visit.
     */
    virtual void visit(SnapshotIdentity *identity) = 0;

    /**
     * Visits a snapshot domain.
     * @param domain The domain to visit.
     */
    virtual void visit(SnapshotDomain *domain) = 0;
    
    /**
     * Visits a snapshot reference.
     * @param reference The reference to visit.
     */
    virtual void visit(SnapshotReference *reference) = 0;

    /**
     * Visits a keyframe entity.
     * @param keyframe The keyframe to visit.
     */
    virtual void visit(Keyframe *keyframe) = 0;
    
    /**
     * Visits a keyframe reference.
     * @param reference The reference to visit.
     */
    virtual void visit(KeyframeReference *reference) = 0;

    /**
     * Visits an action entity.
     * @param action The action to visit.
     */
    virtual void visit(Action *action) = 0;
    
    /**
     * Visits an action identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ActionIdentity *identity) = 0;
    
    /**
     * Visits an event class.
     * @param _class The event class to visit.
     */
    virtual void visit(EventClass *_class) = 0;
    
    /**
     * Visits a action reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ActionReference *reference) = 0;
    
    /**
     * Visits an element prototype.
     * @param prototype The prototype to visit.
     */
    virtual void visit(Prototype *prototype) = 0;
    
    /**
     * Visits an element prototype identity.
     * @param identity The identity to visit.
     */
    virtual void visit(PrototypeIdentity *identity) = 0;
    
    /**
     * Visits an invocation entity.
     * @param invocation The invocation to visit.
     */
    virtual void visit(Invocation *invocation) = 0;
    
    /**
     * Visits an invocation identity.
     * @param identity The identity to visit.
     */
    virtual void visit(InvocationIdentity *identity) = 0;
    
    /**
     * Visits an invocation target.
     * @param target The target to visit.
     */
    virtual void visit(InvocationTarget *target) = 0;
    
    /**
     * Visits an invocation reference.
     * @param reference The reference to visit.
     */
    virtual void visit(InvocationReference *reference) = 0;
    
    /**
     * Visits a query entity.
     * @param query The query to visit.
     */
    virtual void visit(Query *query) = 0;
    
    /**
     * Visits a query identity.
     * @param identity The identity to visit.
     */
    virtual void visit(QueryIdentity *identity) = 0;
    
    /**
     * Visits a query target.
     * @param target The target to visit.
     */
    virtual void visit(QueryTarget *target) = 0;
    
    /**
     * Visits a model entity.
     * @param model The model to visit.
     */
    virtual void visit(Model *model) = 0;
    
    /**
     * Visits a model identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ModelIdentity *identity) = 0;
    
    /**
     * Visits a model description.
     * @param description The description to visit.
     */
    virtual void visit(ModelDescription *description) = 0;
    
    /**
     * Visits a compound reference.
     * @param reference The reference to visit.
     */
    virtual void visit(CompoundReference *reference) = 0;
    
    /**
     * Visits an identity's relationships list.
     * @param relationships The list of relationships to visit.
     */
    virtual void visit(IdentityRelationshipsList *relationships) = 0;
    
    /**
     * Visits an attribute.
     * @param attribute The attribute to visit.
     */
    virtual void visit(Attribute *attribute) = 0;
    
    /**
     * Visits a mirror.
     * @param mirror The mirror to visit.
     */
    virtual void visit(Mirror *mirror) = 0;
    
    /**
     * Visits a simple name.
     * @param name The name to visit.
     */
    virtual void visit(SimpleName *name) = 0;
    
    /**
     * Visits a qualified name.
     * @param name The name to visit.
     */
    virtual void visit(QualifiedName *name) = 0;
    
    /**
     * Visits a ID name.
     * @param name The name to visit.
     */
    virtual void visit(ElementID *name) = 0;
    
    /**
     * Visits a selector initializer expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SelectorInitializer *expression) = 0;
    
    /**
     * Visits an attribute selector.
     * @param selector The selector to visit
     */
    virtual void visit(AttributeSelector *selector) = 0;
    
    /**
     * Visits an element selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ElementSelector *selector) = 0;
    
    /**
     * Visits a procedure selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ProcedureSelector *selector) = 0;
    
    /**
     * Visits an invocation selector.
     * @param selector The selector to visit.
     */
    virtual void visit(InvocationSelector *selector) = 0;
    
    /**
     * Visits a snapshot selector.
     * @param selector The selector to visit.
     */
    virtual void visit(SnapshotSelector *selector) = 0;
    
    /**
     * Visits a keyframe selector.
     * @param selector The selector to visit.
     */
    virtual void visit(KeyframeSelector *selector) = 0;
    
    /**
     * Visits an action selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ActionSelector *selector) = 0;
    
    /**
     * Visits the child selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ChildSelector *selector) = 0;
    
    /**
     * Visits the descendant selector.
     * @param selector The selector to visit.
     */
    virtual void visit(DescendantSelector *selector) = 0;
    
    /**
     * Visits the index selector.
     * @param selector The selector to visit.
     */
    virtual void visit(IndexSelector *selector) = 0;
    
    /**
     * Visits the self selector.
     * @param selector The selector to visit.
     */
    virtual void visit(SelfSelector *selector) = 0;
    
    /**
     * Visits the parent selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ParentSelector *selector) = 0;
    
    /**
     * Visits the root selector.
     * @param selector The selector to visit.
     */
    virtual void visit(RootSelector *selector) = 0;
    
    /**
     * Visits the document selector.
     * @param selector The selector to visit.
     */
    virtual void visit(DocumentSelector *selector) = 0;
    
    /**
     * Visits a undefined expression.
     * @param expression The expression to visit.
     */
    virtual void visit(UndefinedExpression *expression) = 0;
    
    /**
     * Visits a null expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NullExpression *expression) = 0;
    
    /**
     * Visits a boolean literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BooleanLiteral *expression) = 0;
    
    /**
     * Visits a color literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ColorLiteral *expression) = 0;
    
    /**
     * Visits a multiplicity literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MultiplicityLiteral *expression) = 0;
    
    /**
     * Visits a number literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NumberLiteral *expression) = 0;
    
    /**
     * Visits a time point literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(TimePointLiteral *expression) = 0;
    
    /**
     * Visits a percent literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(PercentLiteral *expression) = 0;
    
    /**
     * Visits a string literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(StringLiteral *expression) = 0;
    
    /**
     * Visits a nested expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NestedExpression *expression) = 0;
    
    /**
     * Visits a logical NOT unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalNOTExpression *expression) = 0;
    
    /**
     * Visits a bitwise NOT unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseNOTExpression *expression) = 0;
    
    /**
     * Visits a positive expression.
     * @param expression The expression to visit.
     */
    virtual void visit(PositiveExpression *expression) = 0;
    
    /**
     * Visits a negative unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NegationExpression *expression) = 0;
    
    /**
     * Visits an exponentiation binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ExponentiationExpression *expression) = 0;
    
    /**
     * Visits a multiplication binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MultiplicationExpression *expression) = 0;
    
    /**
     * Visits a division binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(DivisionExpression *expression) = 0;
    
    /**
     * Visits a remainder (modulo) binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(RemainderExpression *expression) = 0;
    
    /**
     * Visits an addition binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(AdditionExpression *expression) = 0;
    
    /**
     * Visits a subtraction binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SubtractionExpression *expression) = 0;
    
    /**
     * Visits a equality binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(EqualityExpression *expression) = 0;
    
    /**
     * Visits a inequality binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(InequalityExpression *expression) = 0;
    
    /**
     * Visits a greater than binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(GreaterThanExpression *expression) = 0;
    
    /**
     * Visits a greater than or equal binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(GreaterThanOrEqualExpression *expression) = 0;
    
    /**
     * Visits a less than binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LessThanExpression *expression) = 0;
    
    /**
     * Visits a less than or equal binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LessThanOrEqualExpression *expression) = 0;
    
    /**
     * Visits a logical AND binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalANDExpression *expression) = 0;
    
    /**
     * Visits a bitwise AND binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseANDExpression *expression) = 0;
    
    /**
     * Visits a logical OR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalORExpression *expression) = 0;
    
    /**
     * Visits a bitwise OR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseORExpression *expression) = 0;
    
    /**
     * Visits a bitwise XOR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseXORExpression *expression) = 0;
    
    /**
     * Visits a bitwise left shift binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseLeftShiftExpression *expression) = 0;
    
    /**
     * Visits a bitwise right shift binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseRightShiftExpression *expression) = 0;
    
    /**
     * Visits a member access expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MemberAccess *expression) = 0;
    
    /**
     * Visits a subscript expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SubscriptAccess *expression) = 0;
    
    /**
     * Visits a conditional ternary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ConditionalExpression *expression) = 0;
    
    /**
     * Visits a when binding.
     * @param binding The binding to visit.
     */
    virtual void visit(WhenBinding *binding) = 0;
    
    /**
     * Visits a while binding.
     * @param binding The binding to visit.
     */
    virtual void visit(WhileBinding *binding) = 0;
    
};

} // namespace hydro::engine

#endif /* __h3o_engine_DocumentVisitor__ */
