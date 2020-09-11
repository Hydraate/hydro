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

#ifndef __h3o_engine_Resolver__
#define __h3o_engine_Resolver__

#include <string>
#include <vector>
#include <cassert>

#include "../../compiler/ErrorReporter.hpp"

#include "DocumentVisitor.hpp"
#include "Document.hpp"

namespace hydro::engine
{

/**
 * The abstract Resolver class is the base class of all resolver types. Resolvers are responsible for resolving symbols and bindings.
 */
class Resolver : protected DocumentVisitor
{
public:
    /**
     *
     */
    Resolver(compiler::ErrorReporter *reporter);
    
    /**
     * Destroys the Resolver object.
     */
    virtual ~Resolver();
    
    /**
     * Resolves symbols in the supplied performance document.
     */
    void resolve(Document *document);
    
protected:
    /**
     * Visits a document entity.
     * @param document The document to visit.
     */
    virtual void visit(Document *document) override;
    
    /**
     * Visits an element entity.
     * @param element The element to visit.
     */
    virtual void visit(Element *element) override;
    
    /**
     * Visits an element identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ElementIdentity *identity) override;
    
    /**
     * Visits an element class.
     * @param _class The class to visit.
     */
    virtual void visit(ElementClass *_class) override;
    
    /**
     * Visits an element reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ElementReference *reference) override;
    
    /**
     * Visits a procedure entity.
     * @param procedure The procedure to visit.
     */
    virtual void visit(Procedure *procedure) override;

    /**
     * Visits a procedure identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ProcedureIdentity *identity) override;

    /**
     * Visits a procedure class.
     * @param _class The class to visit.
     */
    virtual void visit(ProcedureClass *_class) override;

    /**
     * Visits a procedure reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ProcedureReference *reference) override;
    
    /**
     * Visits a snapshot entity.
     * @param snapshot The document to visit.
     */
    virtual void visit(Snapshot *snapshot) override;
    
    /**
     * Visits a snapshot identity.
     * @param identity The identity to visit.
     */
    virtual void visit(SnapshotIdentity *identity) override;

    /**
     * Visits a snapshot domain.
     * @param domain The domain to visit.
     */
    virtual void visit(SnapshotDomain *domain) override;
    
    /**
     * Visits a snapshot reference.
     * @param reference The reference to visit.
     */
    virtual void visit(SnapshotReference *reference) override;

    /**
     * Visits a keyframe entity.
     * @param keyframe The keyframe to visit.
     */
    virtual void visit(Keyframe *keyframe) override;
    
    /**
     * Visits a keyframe reference.
     * @param reference The reference to visit.
     */
    virtual void visit(KeyframeReference *reference) override;

    /**
     * Visits an action entity.
     * @param action The action to visit.
     */
    virtual void visit(Action *action) override;
    
    /**
     * Visits an action identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ActionIdentity *identity) override;
    
    /**
     * Visits an event class.
     * @param _class The event class to visit.
     */
    virtual void visit(EventClass *_class) override;
    
    /**
     * Visits a action reference.
     * @param reference The reference to visit.
     */
    virtual void visit(ActionReference *reference) override;
    
    /**
     * Visits an element prototype.
     * @param prototype The prototype to visit.
     */
    virtual void visit(Prototype *prototype) override;
    
    /**
     * Visits an element prototype identity.
     * @param identity The identity to visit.
     */
    virtual void visit(PrototypeIdentity *identity) override;
    
    /**
     * Visits an invocation entity.
     * @param invocation The invocation to visit.
     */
    virtual void visit(Invocation *invocation) override;
    
    /**
     * Visits an invocation identity.
     * @param identity The identity to visit.
     */
    virtual void visit(InvocationIdentity *identity) override;
    
    /**
     * Visits an invocation target.
     * @param target The target to visit.
     */
    virtual void visit(InvocationTarget *target) override;
    
    /**
     * Visits an invocation reference.
     * @param reference The reference to visit.
     */
    virtual void visit(InvocationReference *reference) override;
    
    /**
     * Visits a query entity.
     * @param query The query to visit.
     */
    virtual void visit(Query *query) override;
    
    /**
     * Visits a query identity.
     * @param identity The identity to visit.
     */
    virtual void visit(QueryIdentity *identity) override;
    
    /**
     * Visits a query target.
     * @param target The target to visit.
     */
    virtual void visit(QueryTarget *target) override;
    
    /**
     * Visits a model entity.
     * @param model The model to visit.
     */
    virtual void visit(Model *model) override;
    
    /**
     * Visits a model identity.
     * @param identity The identity to visit.
     */
    virtual void visit(ModelIdentity *identity) override;
    
    /**
     * Visits a model description.
     * @param description The description to visit.
     */
    virtual void visit(ModelDescription *description) override;
    
    /**
     * Visits a compound reference.
     * @param reference The reference to visit.
     */
    virtual void visit(CompoundReference *reference) override;
    
    /**
     * Visits an identity's relationships list.
     * @param relationships The list of relationships to visit.
     */
    virtual void visit(IdentityRelationshipsList *relationships) override;
    
    /**
     * Visits an attribute.
     * @param attribute The attribute to visit.
     */
    virtual void visit(Attribute *attribute) override;
    
    /**
     * Visits a mirror.
     * @param mirror The mirror to visit.
     */
    virtual void visit(Mirror *mirror) override;
    
    /**
     * Visits a simple name.
     * @param name The name to visit.
     */
    virtual void visit(SimpleName *name) override;
    
    /**
     * Visits a qualified name.
     * @param name The name to visit.
     */
    virtual void visit(QualifiedName *name) override;
    
    /**
     * Visits a ID name.
     * @param name The name to visit.
     */
    virtual void visit(ElementID *name) override;
    
    /**
     * Visits a selector initializer expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SelectorInitializer *expression) override;
    
    /**
     * Visits an attribute selector.
     * @param selector The selector to visit
     */
    virtual void visit(AttributeSelector *selector) override;
    
    /**
     * Visits an element selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ElementSelector *selector) override;
    
    /**
     * Visits a procedure selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ProcedureSelector *selector) override;
    
    /**
     * Visits an invocation selector.
     * @param selector The selector to visit.
     */
    virtual void visit(InvocationSelector *selector) override;
    
    /**
     * Visits a snapshot selector.
     * @param selector The selector to visit.
     */
    virtual void visit(SnapshotSelector *selector) override;
    
    /**
     * Visits a keyframe selector.
     * @param selector The selector to visit.
     */
    virtual void visit(KeyframeSelector *selector) override;
    
    /**
     * Visits an action selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ActionSelector *selector) override;
    
    /**
     * Visits the child selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ChildSelector *selector) override;
    
    /**
     * Visits the descendant selector.
     * @param selector The selector to visit.
     */
    virtual void visit(DescendantSelector *selector) override;
    
    /**
     * Visits the index selector.
     * @param selector The selector to visit.
     */
    virtual void visit(IndexSelector *selector) override;
    
    /**
     * Visits the self selector.
     * @param selector The selector to visit.
     */
    virtual void visit(SelfSelector *selector) override;
    
    /**
     * Visits the parent selector.
     * @param selector The selector to visit.
     */
    virtual void visit(ParentSelector *selector) override;
    
    /**
     * Visits the root selector.
     * @param selector The selector to visit.
     */
    virtual void visit(RootSelector *selector) override;
    
    /**
     * Visits the document selector.
     * @param selector The selector to visit.
     */
    virtual void visit(DocumentSelector *selector) override;
    
    /**
     * Visits a undefined expression.
     * @param expression The expression to visit.
     */
    virtual void visit(UndefinedExpression *expression) override;
    
    /**
     * Visits a null expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NullExpression *expression) override;
    
    /**
     * Visits a boolean literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BooleanLiteral *expression) override;
    
    /**
     * Visits a color literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ColorLiteral *expression) override;
    
    /**
     * Visits a multiplicity literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MultiplicityLiteral *expression) override;
    
    /**
     * Visits a number literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NumberLiteral *expression) override;
    
    /**
     * Visits a time point literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(TimePointLiteral *expression) override;
    
    /**
     * Visits a percent literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(PercentLiteral *expression) override;
    
    /**
     * Visits a string literal expression.
     * @param expression The expression to visit.
     */
    virtual void visit(StringLiteral *expression) override;
    
    /**
     * Visits a nested expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NestedExpression *expression) override;
    
    /**
     * Visits a logical NOT unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalNOTExpression *expression) override;
    
    /**
     * Visits a bitwise NOT unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseNOTExpression *expression) override;
    
    /**
     * Visits a positive expression.
     * @param expression The expression to visit.
     */
    virtual void visit(PositiveExpression *expression) override;
    
    /**
     * Visits a negative unary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(NegationExpression *expression) override;
    
    /**
     * Visits an exponentiation binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ExponentiationExpression *expression) override;
    
    /**
     * Visits a multiplication binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MultiplicationExpression *expression) override;
    
    /**
     * Visits a division binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(DivisionExpression *expression) override;
    
    /**
     * Visits a remainder (modulo) binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(RemainderExpression *expression) override;
    
    /**
     * Visits an addition binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(AdditionExpression *expression) override;
    
    /**
     * Visits a subtraction binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SubtractionExpression *expression) override;
    
    /**
     * Visits a equality binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(EqualityExpression *expression) override;
    
    /**
     * Visits a inequality binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(InequalityExpression *expression) override;
    
    /**
     * Visits a greater than binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(GreaterThanExpression *expression) override;
    
    /**
     * Visits a greater than or equal binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(GreaterThanOrEqualExpression *expression) override;
    
    /**
     * Visits a less than binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LessThanExpression *expression) override;
    
    /**
     * Visits a less than or equal binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LessThanOrEqualExpression *expression) override;
    
    /**
     * Visits a logical AND binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalANDExpression *expression) override;
    
    /**
     * Visits a bitwise AND binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseANDExpression *expression) override;
    
    /**
     * Visits a logical OR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(LogicalORExpression *expression) override;
    
    /**
     * Visits a bitwise OR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseORExpression *expression) override;
    
    /**
     * Visits a bitwise XOR binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseXORExpression *expression) override;
    
    /**
     * Visits a bitwise left shift binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseLeftShiftExpression *expression) override;
    
    /**
     * Visits a bitwise right shift binary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(BitwiseRightShiftExpression *expression) override;
    
    /**
     * Visits a member access expression.
     * @param expression The expression to visit.
     */
    virtual void visit(MemberAccess *expression) override;
    
    /**
     * Visits a subscript expression.
     * @param expression The expression to visit.
     */
    virtual void visit(SubscriptAccess *expression) override;
    
    /**
     * Visits a conditional ternary expression.
     * @param expression The expression to visit.
     */
    virtual void visit(ConditionalExpression *expression) override;
    
    /**
     * Visits a when binding.
     * @param binding The binding to visit.
     */
    virtual void visit(WhenBinding *binding) override;
    
    /**
     * Visits a while binding.
     * @param binding The binding to visit.
     */
    virtual void visit(WhileBinding *binding) override;
    
private:
    /**
     * The error reporter.
     */
    compiler::ErrorReporter *mErrorReporter;
    
    /**
     * The entity node stack.
     */
    std::vector<Entity *> mNodeStack;
    
    /**
     * Pushes an entity on the top of the entity node stack.
     * @param node The entity node to push.
     */
    void push(Entity *node);
    
    Entity *top() const;
    
    /**
     * Pops the entity node stack.
     */
    void pop();
    
    /**
     * Resolves a prototype symbol.
     * @param name The name of the symbol to resolve.
     */
    PrototypeSymbol *resolvePrototype(std::string name);
};

} // namespace hydro::engine

#endif /* __h3o_engine_Resolver__ */
