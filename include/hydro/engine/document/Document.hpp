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

#ifndef __h3o_engine_Document__
#define __h3o_engine_Document__

#include <list>
#include <stack>

#include "expression/BinaryExpression.hpp"
#include "expression/BooleanLiteral.hpp"
#include "expression/ColorLiteral.hpp"
#include "expression/SelectorInitializer.hpp"
#include "expression/ElementSelector.hpp"
#include "expression/AttributeSelector.hpp"
#include "expression/ProcedureSelector.hpp"
#include "expression/SnapshotSelector.hpp"
#include "expression/KeyframeSelector.hpp"
#include "expression/ActionSelector.hpp"
#include "expression/InvocationSelector.hpp"
#include "expression/ChildSelector.hpp"
#include "expression/DescendantSelector.hpp"
#include "expression/IndexSelector.hpp"
#include "expression/SelfSelector.hpp"
#include "expression/ParentSelector.hpp"
#include "expression/RootSelector.hpp"
#include "expression/DocumentSelector.hpp"
#include "expression/NestedExpression.hpp"
#include "expression/MultiplicityLiteral.hpp"
#include "expression/NumberLiteral.hpp"
#include "expression/StringLiteral.hpp"
#include "expression/TimePointLiteral.hpp"
#include "expression/PercentLiteral.hpp"
#include "expression/UndefinedExpression.hpp"
#include "expression/NullExpression.hpp"
#include "expression/PositiveExpression.hpp"
#include "expression/NegationExpression.hpp"
#include "expression/ExponentiationExpression.hpp"
#include "expression/MultiplicationExpression.hpp"
#include "expression/DivisionExpression.hpp"
#include "expression/RemainderExpression.hpp"
#include "expression/AdditionExpression.hpp"
#include "expression/SubtractionExpression.hpp"
#include "expression/EqualityExpression.hpp"
#include "expression/InequalityExpression.hpp"
#include "expression/LogicalANDExpression.hpp"
#include "expression/LogicalORExpression.hpp"
#include "expression/LogicalNOTExpression.hpp"
#include "expression/GreaterThanExpression.hpp"
#include "expression/GreaterThanOrEqualExpression.hpp"
#include "expression/LessThanExpression.hpp"
#include "expression/LessThanOrEqualExpression.hpp"
#include "expression/BitwiseORExpression.hpp"
#include "expression/BitwiseANDExpression.hpp"
#include "expression/BitwiseORExpression.hpp"
#include "expression/BitwiseNOTExpression.hpp"
#include "expression/BitwiseLeftShiftExpression.hpp"
#include "expression/BitwiseRightShiftExpression.hpp"
#include "expression/BitwiseXORExpression.hpp"
#include "expression/MemberAccess.hpp"
#include "expression/SubscriptAccess.hpp"
#include "expression/ConditionalExpression.hpp"

#include "Action.hpp"
#include "Attribute.hpp"
#include "Mirror.hpp"
#include "Document.hpp"
#include "Element.hpp"
#include "IdentityRelationshipsList.hpp"
#include "Invocation.hpp"
#include "Keyframe.hpp"
#include "Procedure.hpp"
#include "Prototype.hpp"
#include "SimpleName.hpp"
#include "QualifiedName.hpp"
#include "Snapshot.hpp"
#include "ElementReference.hpp"
#include "Query.hpp"
#include "CompoundReference.hpp"
#include "ProcedureReference.hpp"
#include "SnapshotReference.hpp"
#include "KeyframeReference.hpp"
#include "ActionReference.hpp"
#include "InvocationReference.hpp"
#include "ActionSymbol.hpp"
#include "PrototypeSymbol.hpp"
#include "ProcedureSymbol.hpp"
#include "EventSymbol.hpp"
#include "SnapshotContextSymbol.hpp"
#include "WhenBinding.hpp"
#include "WhileBinding.hpp"
#include "PDocumentLexer.hpp"

namespace hydro::engine
{
/**
 * The Document class represents a Performance document in its entirety. The document is the root entity in any source and is a prototype of the entire source. This class keeps track of all entities within a source file and is a factory for all nodes.
 */
class Document final : public Entity
{
protected:
    /**
     * Creates a Document object with a parser.
     */
    Document();
    
public:

    /**
     * Destroyes the Document object and frees resources belonging to the document.
     */
    virtual ~Document();
    
    /**
     * Creates a new document with a parser.
     * @return Returns the newly created Document instance.
     */
    static Document *create();
    
    /**
     * Accepts a visitor allowing the visitor to visit the document.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
    
    /**
     * Creates a simple name.
     * @param token The identifier token.
     */
    SimpleName *createSimpleName(compiler::Token token);
    
    /**
     * Creates a qualified name.
     * @param qualifier The name qualifier.
     * @param token The dot token.
     * @param name The simple name.
     */
    QualifiedName *createQualifiedName(Name *qualifier, compiler::Token token, SimpleName *name);
    
    /**
     * Creates an identity relationship..
     * @param name The relationship name.
     */
    Relationship *createRelationship(Name *name);
    
    /**
     * Creates an identity relationships list.
     */
    IdentityRelationshipsList *createRelationshipsList();
    
    /**
     * Creates an attribute.
     * @param name The attribute's name.
     * @param value The attribute's value.
     */
    Attribute *createAttribute(Name *name, Value *value);
    
    /**
     * Creates an attribute mirror.
     * @param name The attribute's name.
     * @param value The attribute's value.
     */
    Mirror *createMirror(Name *name, Value *value);
    
    /**
     * Creates a when binding.
     * @param token The token.
     * @param condition The condition expression.
     */
    WhenBinding *createWhenBinding(compiler::Token token, Expression *condition);
    
    /**
     * Creates a while binding.
     * @param token The token.
     * @param condition The condition expression.
     */
    WhileBinding *createWhileBinding(compiler::Token token, Expression *condition);

    
    /**
     * Creates an element class.
     * @param name The name of the element class.
     */
    ElementClass *createElementClass(Name *name);
    
    /**
     * Creates an element ID with a token.
     * @param token The token.
     */
    ElementID *createElementID(compiler::Token token);
    
    /**
     * Creates an element identity.
     * @param relationships The identity relationships list.
     * @param elementClass The element class.
     * @param id The optional element ID.
     */
    ElementIdentity *createElementIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass, ElementID *id = nullptr);
    
    /**
     * Creates an element entity.
     * @param parent The parent entity.
     * @param identity The element identity.
     */
    Element *createElement(Entity *parent, ElementIdentity *identity);
    
    /**
     * Creates a prototype identity.
     * @param relationships The identity relationships list.
     * @param elementClass The derived element class.
     * @param parentClass The optional parent element class.
     */
    PrototypeIdentity *createPrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass, ElementClass *parentClass);
    
    /**
     * Creates a prototype entity using an element class and an optional parent element class.
     * @param parent The parent entity.
     * @param identity The prototype identity.
     */
    Prototype *createPrototype(Entity *parent, PrototypeIdentity *identity);
    
    /**
     * Creates an element symbol from an element class.
     * @param elementClass The element class.
     */
    PrototypeSymbol *createPrototypeSymbol(ElementClass *elementClass);
    
    /**
     * Creates an element reference.
     * @param elementClass The element class.
     * @param id The element ID.
     */
    ElementReference *createElementReference(ElementClass *elementClass, ElementID *id);
    
    /**
     * Creates a procedure class.
     * @param name The name of the procedure.
     */
    ProcedureClass *createProcedureClass(Name *name);
    
    /**
     * Creates a procedure identity.
     * @param relationships The identity relationships list.
     * @param procedureClass The procedure class.
     */
    ProcedureIdentity *createProcedureIdentity(IdentityRelationshipsList *relationships, ProcedureClass *procedureClass);
    
    /**
     * Creates a procedure entity.
     * @param parent The parent entity.
     * @param identity The procedure identity.
     */
    Procedure *createProcedure(Entity *parent, ProcedureIdentity *identity);
    
    /**
     * Creates a procedure symbol using a procedure class.
     * @param procedureClass The procedure class.
     */
    ProcedureSymbol *createProcedureSymbol(ProcedureClass *procedureClass);
    
    /**
     * Creates a procedure reference.
     * @param procedureClass The procedure class.
     */
    ProcedureReference *createProcedureReference(ProcedureClass *procedureClass);
    
    /**
     * Creates a snapshot domain.
     *
     */
    SnapshotDomain *createSnapshotDomain(Name *name);
    
    SnapshotIdentity *createSnapshotIdentity(IdentityRelationshipsList *relationships, SnapshotDomain *domain);
    
    Snapshot *createSnapshot(Entity *parent, SnapshotIdentity *identity);
    
    SnapshotContextSymbol *createSnapshotContextSymbol(SnapshotDomain *domain);
    
    SnapshotReference *createSnapshotReference(SnapshotDomain *domain);
    
    Keyframe *createKeyframe(Entity *parent, TimePointLiteral *time, SnapshotIdentity *identity);
    
    KeyframeReference *createKeyframeReference(TimePointLiteral *time, SnapshotDomain *domain);

    EventClass *createEventClass(Name *name);
    
    ActionIdentity *createActionIdentity(IdentityRelationshipsList *relationships, EventClass *eventClass);
    
    Action *createAction(Entity *parent, ActionIdentity *identity);
    
    ActionSymbol *createActionSymbol(EventClass *eventClass);
    
    ActionReference *createActionReference(EventClass *eventClass);
    
    QueryTarget *createQueryTarget(Selector *selector);
    
    QueryIdentity *createQueryIdentity(QueryTarget *target);
    
    Query *createQuery(Entity *parent, QueryIdentity *identity);
    
    InvocationTarget *createInvocationTarget(Reference *reference);
    
    InvocationIdentity *createInvocationIdentity(InvocationTarget *target);
        
    Invocation *createInvocation(Entity *parent, InvocationIdentity *identity);
    
    InvocationReference *createInvocationReference(InvocationTarget *target);

    UndefinedExpression *createUndefined(compiler::Token token);

    NullExpression *createNull(compiler::Token token);

    BooleanLiteral *createBoolean(compiler::Token token);

    NumberLiteral *createNumber(compiler::Token token);

    StringLiteral *createString(compiler::Token token);

    ColorLiteral *createColor(compiler::Token token);

    PercentLiteral *createPercent(compiler::Token token, NumberLiteral *value);

    TimePointLiteral *createTimePoint(NumberLiteral *min, NumberLiteral *secs, NumberLiteral *ms);

    TimePointLiteral *createTimePoint(NumberLiteral *hrs, NumberLiteral *min, NumberLiteral *secs, NumberLiteral *ms);

    MultiplicityLiteral *createMultiplicity(NumberLiteral *min, compiler::Token token, NumberLiteral *max);
    
    AttributeSelector *createAttributeSelector(Name *name);
    
    ElementSelector *createElementSelector(ElementClass *elementClass, ElementID *id);
    
    ProcedureSelector *createProcedureSelector(ProcedureClass *procedureClass);
    
    SnapshotSelector *createSnapshotSelector(SnapshotDomain *domain);
    
    KeyframeSelector *createKeyframeSelector(TimePointLiteral* time, SnapshotDomain *domain);
    
    ActionSelector *createActionSelector(EventClass *eventClass);
    
    SelfSelector *createSelfSelector(compiler::Token token);
    
    ParentSelector *createParentSelector(compiler::Token token);

    RootSelector *createRootSelector(compiler::Token token);

    DocumentSelector *createDocumentSelector(compiler::Token token);

    ExponentiationExpression *createExponentiation(Expression *lhs, compiler::Token token, Expression *rhs);
    
    MultiplicationExpression *createMultiplication(Expression *lhs, compiler::Token token, Expression *rhs);

    DivisionExpression *createDivision(Expression *lhs, compiler::Token token, Expression *rhs);

    RemainderExpression *createRemainder(Expression *lhs, compiler::Token token, Expression *rhs);

    AdditionExpression *createAddition(Expression *lhs, compiler::Token token, Expression *rhs);

    SubtractionExpression *createSubtraction(Expression *lhs, compiler::Token token, Expression *rhs);

    EqualityExpression *createEquality(Expression *lhs, compiler::Token token, Expression *rhs);

    InequalityExpression *createInequality(Expression *lhs, compiler::Token token, Expression *rhs);
    
    PositiveExpression *createPositive(compiler::Token token, Expression *expression);
    
    NegationExpression *createNegative(compiler::Token token, Expression *expression);

    LogicalNOTExpression *createLogicalNOT(compiler::Token token, Expression *expression);
    
    BitwiseNOTExpression *createBitwiseNOT(compiler::Token token, Expression *expression);
    
    NestedExpression *createNested(compiler::Token token, Expression *expression);

    LogicalANDExpression *createLogicalAND(Expression *lhs, compiler::Token token, Expression *rhs);

    LogicalORExpression *createLogicalOR(Expression *lhs, compiler::Token token, Expression *rhs);

    GreaterThanExpression *createGreaterThan(Expression *lhs, compiler::Token token, Expression *rhs);

    GreaterThanOrEqualExpression *createGreaterThanOrEqual(Expression *lhs, compiler::Token token, Expression *rhs);
    
    LessThanExpression *createLessThan(Expression *lhs, compiler::Token token, Expression *rhs);
    
    LessThanOrEqualExpression *createLessThanOrEqual(Expression *lhs, compiler::Token token, Expression *rhs);

    BitwiseANDExpression *createBitwiseAND(Expression *lhs, compiler::Token token, Expression *rhs);

    BitwiseORExpression *createBitwiseOR(Expression *lhs, compiler::Token token, Expression *rhs);

    BitwiseXORExpression *createBitwiseXOR(Expression *lhs, compiler::Token token, Expression *rhs);

    BitwiseLeftShiftExpression *createBitwiseLeftShift(Expression *lhs, compiler::Token token, Expression *rhs);

    BitwiseRightShiftExpression *createBitwiseRightShift(Expression *lhs, compiler::Token token, Expression *rhs);

    MemberAccess *createMemberAccess(Expression *subject, compiler::Token token, Expression *target);
    
    SubscriptAccess *createSubscriptAccess(Expression *subject, compiler::Token token, Expression *target);

    ChildSelector *createChildSelector(Selector *subject, compiler::Token token, Selector *target);

    DescendantSelector *createDescendantSelector(Selector *subject, compiler::Token token, Selector *target);

    IndexSelector *createIndexSelector(Selector *subject, compiler::Token token, Expression *target);

    ConditionalExpression *createConditional(Expression *condition, Expression *trueExpression, Expression *falseExpression);
    
    CompoundReference *createCompoundReference(Reference *subject, compiler::Token token, SimpleReference *target);

private:
    /**
     * A list of nodes created, owned, and managed by this document.
     */
    std::list<Node *> mNodes;
    
    /**
     * A list of symbols created, owned, and managed by this document.
     */
    std::list<Symbol *> mSymbols;
    
    template <typename T>
    T *appendNode(T *node)
    {
        mNodes.push_front(node);
        node->mDocument = this;
        return node;
    }
    
    template <typename T>
    T *appendSymbol(T *symbol)
    {
        mSymbols.push_back(symbol);
        return symbol;
    }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Document__ */
