
input metauml;
input hierarchy_template;
input hierarchy_util;

H_SPACING = 30;
V_SPACING = 40;


def Reset =
    save GameObject, Component;
    save PhysicsComponent, GraphicsComponent, InputComponent;
    save UpdateDelegate;
enddef;


beginfig(1);
    Reset;

    Class.GameObject("GameObject")()("Properties['foo_A']", "Properties['foo_B']", "Properties['bar']");
    Class.PropertyDataB("PropertyOverrideMap")()("'foo': 'foo_B'");
    Class.FooComponentB("FooComponentB")()("getProperty(string)");
    
    Note.ComponentGetterB(
        "getProperty('foo')",
        "getProperty('bar')"
    );

    Class.PropertyDataA("PropertyOverrideMap")()("'foo': 'foo_B'");
    Class.FooComponentA("FooComponentA")()("getProperty(string)");

    Note.ComponentGetterA(
        "getProperty('foo')",
        "getProperty('bar')"
    );

    
    leftToRight(V_SPACING)(FooComponentA, PropertyDataA, GameObject);
    leftToRight(V_SPACING)(FooComponentB, PropertyDataB, GameObject);
    
    ComponentGetterA.s = FooComponentB.n + (10, 20);
    PropertyDataA
    
    % FooComponentA.s = ComponentGetterA.n  + (10, -20);

    ComponentGetterB.n = FooComponentB.s + (10, -20);
    
    drawObjects(
    GameObject,
    FooComponentB, PropertyDataB, ComponentGetterB,
    FooComponentA, PropertyDataA, ComponentGetterA);

    link(associationUni)(ComponentGetterB.n + (10,0) -- PropertyDataB.methodStack.pict[0].w);
    link(associationUni)(PropertyDataB.methodStack.pict[0].e -- GameObject.methodStack.pict[1].w);

    clink(aggregation)(FooComponentB, PropertyDataB);

    link(dashedLink)(FooComponentB.methodStack.pict[0].s - (10,0) -- ComponentGetterB.n - (14,0));


endfig;


end
