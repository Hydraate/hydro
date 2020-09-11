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

#include "Resolver.hpp"

namespace hydro::engine
{

Resolver::Resolver(compiler::ErrorReporter *errorReporter)
{
    mErrorReporter = errorReporter;
}

Resolver::~Resolver()
{
}

void Resolver::resolve(Document *document)
{
    push(document);
    document->accept(this);
    pop();
}

void Resolver::visit(Document *document)
{
    for(auto attr : document->attributes())
        attr->accept(this);

    for(auto child : document->children())
        child->accept(this);
}

void Resolver::visit(Element *element)
{
    push(element);
    element->getIdentity()->accept(this);

    for(auto attr : element->attributes())
        attr->accept(this);
    
    for(auto child : element->children())
        child->accept(this);
    
    pop();
}

void Resolver::visit(ElementIdentity *identity)
{
    identity->getSubject()->accept(this);
}

void Resolver::visit(ElementClass *_class)
{
    Symbol *symbol = resolvePrototype(_class->getName()->getValue());

    if(!symbol)
    {
        mErrorReporter->reportError("The prototype '" + _class->getName()->getValue() + "' is undefined.", _class->getName()->getSourcePosition());
    }
}

void Resolver::visit(ElementReference *reference)
{
    
}

void Resolver::visit(Procedure *procedure)
{
    
}

void Resolver::visit(ProcedureIdentity *identity)
{
    
}

void Resolver::visit(ProcedureClass *_class)
{
    
}

void Resolver::visit(ProcedureReference *reference)
{
    
}

void Resolver::visit(Snapshot *snapshot)
{
    
}

void Resolver::visit(SnapshotIdentity *identity)
{
    
}

void Resolver::visit(SnapshotDomain *domain)
{
    
}

void Resolver::visit(SnapshotReference *reference)
{
    
}

void Resolver::visit(Keyframe *keyframe)
{
    
}

void Resolver::visit(KeyframeReference *reference)
{
    
}

void Resolver::visit(Action *action)
{
    
}

void Resolver::visit(ActionIdentity *identity)
{
    
}

void Resolver::visit(EventClass *_class)
{
    
}

void Resolver::visit(ActionReference *reference)
{
    
}

void Resolver::visit(Prototype *prototype)
{
    
}

void Resolver::visit(PrototypeIdentity *identity)
{
    
}

void Resolver::visit(Invocation *invocation)
{
    
}

void Resolver::visit(InvocationIdentity *identity)
{
    
}

void Resolver::visit(InvocationTarget *target)
{
    
}

void Resolver::visit(InvocationReference *reference)
{
    
}

void Resolver::visit(Query *query)
{
    
}

void Resolver::visit(QueryIdentity *identity)
{
    
}

void Resolver::visit(QueryTarget *target)
{
    
}

void Resolver::visit(Model *model)
{
    
}

void Resolver::visit(ModelIdentity *identity)
{
    
}

void Resolver::visit(ModelDescription *description)
{
    
}

void Resolver::visit(CompoundReference *reference)
{
    
}

void Resolver::visit(IdentityRelationshipsList *relationships)
{
    
}

void Resolver::visit(Attribute *attribute)
{
    
}

void Resolver::visit(Mirror *mirror)
{
    
}

void Resolver::visit(SimpleName *name)
{
    
}

void Resolver::visit(QualifiedName *name)
{
    
}

void Resolver::visit(ElementID *name)
{
    
}

void Resolver::visit(SelectorInitializer *expression)
{
    
}

void Resolver::visit(AttributeSelector *selector)
{
    
}

void Resolver::visit(ElementSelector *selector)
{
    
}

void Resolver::visit(ProcedureSelector *selector)
{
    
}

void Resolver::visit(InvocationSelector *selector)
{
    
}

void Resolver::visit(SnapshotSelector *selector)
{
    
}

void Resolver::visit(KeyframeSelector *selector)
{
    
}

void Resolver::visit(ActionSelector *selector)
{
    
}

void Resolver::visit(ChildSelector *selector)
{
    
}

void Resolver::visit(DescendantSelector *selector)
{
    
}

/**
 * Visits the index selector.
 * @param selector The selector to Resolver::visit.
 */
void Resolver::visit(IndexSelector *selector)
{
    
}

/**
 * Visits the self selector.
 * @param selector The selector to Resolver::visit.
 */
void Resolver::visit(SelfSelector *selector)
{
    
}

/**
 * Visits the parent selector.
 * @param selector The selector to Resolver::visit.
 */
void Resolver::visit(ParentSelector *selector)
{
    
}

/**
 * Visits the root selector.
 * @param selector The selector to Resolver::visit.
 */
void Resolver::visit(RootSelector *selector)
{
    
}

/**
 * Visits the document selector.
 * @param selector The selector to Resolver::visit.
 */
void Resolver::visit(DocumentSelector *selector)
{
    
}

/**
 * Visits a undefined expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(UndefinedExpression *expression)
{
    
}

/**
 * Visits a null expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(NullExpression *expression)
{
    
}

/**
 * Visits a boolean literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BooleanLiteral *expression)
{
    
}

/**
 * Visits a color literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(ColorLiteral *expression)
{
    
}

/**
 * Visits a multiplicity literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(MultiplicityLiteral *expression)
{
    
}

/**
 * Visits a number literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(NumberLiteral *expression)
{
    
}

/**
 * Visits a time point literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(TimePointLiteral *expression)
{
    
}

/**
 * Visits a percent literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(PercentLiteral *expression)
{
    
}

/**
 * Visits a string literal expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(StringLiteral *expression)
{
    
}

/**
 * Visits a nested expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(NestedExpression *expression)
{
    
}

/**
 * Visits a logical NOT unary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(LogicalNOTExpression *expression)
{
    
}

/**
 * Visits a bitwise NOT unary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseNOTExpression *expression)
{
    
}

/**
 * Visits a positive expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(PositiveExpression *expression)
{
    
}

/**
 * Visits a negative unary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(NegationExpression *expression)
{
    
}

/**
 * Visits an exponentiation binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(ExponentiationExpression *expression)
{
    
}

/**
 * Visits a multiplication binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(MultiplicationExpression *expression)
{
    
}

/**
 * Visits a division binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(DivisionExpression *expression)
{
    
}

/**
 * Visits a remainder (modulo) binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(RemainderExpression *expression)
{
    
}

/**
 * Visits an addition binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(AdditionExpression *expression)
{
    
}

/**
 * Visits a subtraction binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(SubtractionExpression *expression)
{
    
}

/**
 * Visits a equality binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(EqualityExpression *expression)
{
    
}

/**
 * Visits a inequality binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(InequalityExpression *expression)
{
    
}

/**
 * Visits a greater than binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(GreaterThanExpression *expression)
{
    
}

/**
 * Visits a greater than or equal binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(GreaterThanOrEqualExpression *expression)
{
    
}

/**
 * Visits a less than binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(LessThanExpression *expression)
{
    
}

/**
 * Visits a less than or equal binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(LessThanOrEqualExpression *expression)
{
    
}

/**
 * Visits a logical AND binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(LogicalANDExpression *expression)
{
    
}

/**
 * Visits a bitwise AND binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseANDExpression *expression)
{
    
}

/**
 * Visits a logical OR binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(LogicalORExpression *expression)
{
    
}

/**
 * Visits a bitwise OR binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseORExpression *expression)
{
    
}

/**
 * Visits a bitwise XOR binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseXORExpression *expression)
{
    
}

/**
 * Visits a bitwise left shift binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseLeftShiftExpression *expression)
{
    
}

/**
 * Visits a bitwise right shift binary expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(BitwiseRightShiftExpression *expression)
{
    
}

/**
 * Visits a member access expression.
 * @param expression The expression to Resolver::visit.
 */
void Resolver::visit(MemberAccess *expression)
{
    
}

void Resolver::visit(SubscriptAccess *expression)
{
    
}

void Resolver::visit(ConditionalExpression *expression)
{
    
}

void Resolver::visit(WhenBinding *binding)
{
    
}

void Resolver::visit(WhileBinding *binding)
{
    
}

void Resolver::push(Entity *node)
{
    mNodeStack.push_back(node);
}

void Resolver::pop()
{
    mNodeStack.pop_back();
}

Entity *Resolver::top() const
{
    return !mNodeStack.empty() ? mNodeStack[mNodeStack.size() - 1] : nullptr;
}

PrototypeSymbol *Resolver::resolvePrototype(std::string name)
{
    Entity *node = top();
    
    if (node)
    {
        PDocumentContext *context = node->getContext();
        
        while (context)
        {
            for(Symbol *symbol : context->symbols())
                if(PrototypeSymbol *prototype = dynamic_cast<PrototypeSymbol *>(symbol))
                    if(prototype->getName() == name)
                        return prototype;
            context = context->getParent();
        }
    }
    
    // fail
    return nullptr;
}

} // namespace hydro::engine
