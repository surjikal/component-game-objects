
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

    Interface.GameObject("GameObject")(
        "init(PhysicsComponent,",
        "     GraphicsComponent,",
        "     InputComponent)",
        "update()",
        "draw()"
    );
    Interface.Component("Component")("update(GameObject)");

    Interface.PhysicsComponent("PhysicsComponent")();
    Interface.GraphicsComponent("GraphicsComponent")("draw(GameObject)");
    Interface.InputComponent("InputComponent")();

    Note.UpdateDelegate(
        "physicsComponent->update(this)",
        "inputComponent->update(this)"
    );

    Note.DrawDelegate("graphicsComponent->draw(this)");

    topToBottom(V_SPACING)(Component, GraphicsComponent, GameObject);
    leftToRight(10)(PhysicsComponent, GraphicsComponent, InputComponent);

    UpdateDelegate.nw = GameObject.se + (H_SPACING, UpdateDelegate.height);
    DrawDelegate.nw = GameObject.se + (H_SPACING, -5);

    drawObjects(
        UpdateDelegate, DrawDelegate,
        GameObject, Component,
        GraphicsComponent, PhysicsComponent, InputComponent
    );

    link(inheritance)(pathStepY(PhysicsComponent.n, Component.s, V_SPACING/2));
    link(inheritance)(pathStepY(GraphicsComponent.n, Component.s, V_SPACING/2));
    link(inheritance)(pathStepY(InputComponent.n, Component.s, V_SPACING/2));

    link(aggregation)(pathStepY(PhysicsComponent.s, GameObject.n, -V_SPACING/2));
    link(aggregation)(pathStepY(GraphicsComponent.s, GameObject.n, -V_SPACING/2));
    link(aggregation)(pathStepY(InputComponent.s, GameObject.n, -V_SPACING/2));

    link(dashedLink)(GameObject.methodStack.pict[3].e -- UpdateDelegate.w);
    link(dashedLink)(GameObject.methodStack.pict[4].e -- DrawDelegate.w);

endfig;



beginfig(2);
    Reset;

    Interface.GameObject("GameObject")(
        "init(PhysicsComponent,",
        "     GraphicsComponent,",
        "     InputComponent)",
        "update()",
        "draw()"
    );
    Interface.Component("Component")("update(GameObject)");

    Interface.PhysicsComponent("PhysicsComponent")();
    Interface.GraphicsComponent("GraphicsComponent")("draw(GameObject)");
    Interface.InputComponent("InputComponent")();

    Class.SnowmanPhysicsComponent("SnowmanPhysicsComponent")()();
    Class.SnowmanGraphicsComponent("SnowmanGraphicsComponent")()();
    Class.PlayerInputComponent("PlayerInputComponent")()();

    Note.UpdateDelegate(
        "GameObject snowman;",
        "snowman->init(new SnowmanPhysicsComponent,",
        "              new SnowmanGraphicsComponent,",
        "              new PlayerInputComponent)"
    );

    UpdateDelegate.nw = GameObject.ne + (15, 10);

    topToBottom(60)(Component, GraphicsComponent, GameObject);


    OFFSET := 10;

    PhysicsComponent.s = GraphicsComponent.nw + (-5, OFFSET);
    InputComponent.n = GraphicsComponent.se - (0, OFFSET);


    PlayerInputComponent.sw = InputComponent.ne + (40, 15);
    SnowmanGraphicsComponent.sw = GraphicsComponent.ne + (40, 15);
    SnowmanPhysicsComponent.sw = PhysicsComponent.ne + (40, 15);


    % SnowmanGraphicsComponent.s = GraphicsComponent.n + (0, 60);


    drawObjects(
        UpdateDelegate,
        SnowmanPhysicsComponent, SnowmanGraphicsComponent, PlayerInputComponent,
        GameObject, Component,
        GraphicsComponent, PhysicsComponent, InputComponent
    );


    link(inheritance)(SnowmanPhysicsComponent.s-(OFFSET, 0) -- PhysicsComponent.e);
    link(inheritance)(SnowmanGraphicsComponent.s-(OFFSET, 0) -- GraphicsComponent.e);
    link(inheritance)(PlayerInputComponent.s-(OFFSET, 0) -- InputComponent.e);

    link(composition)(pathStepY(PhysicsComponent.s-(5,0), GameObject.n, -V_SPACING));
    link(composition)(pathStepY(GraphicsComponent.s, GameObject.n, -V_SPACING/2));
    link(composition)(pathStepY(InputComponent.s, GameObject.n, -OFFSET));

    link(inheritance)(pathStepY(PhysicsComponent.n, Component.s, OFFSET));
    link(inheritance)(pathStepY(GraphicsComponent.n, Component.s, V_SPACING/2));
    link(inheritance)(pathStepY(InputComponent.n+(OFFSET,0), Component.s, V_SPACING));


    link(dashedLink)(GameObject.methodStack.pict[0].e -- UpdateDelegate.w);

endfig;


beginfig(3);
    Reset;

    Class.GameObject("GameObject")()(
        "addComponent(Component)",
        "removeComponent(ComponentId)"
    );
    Interface.Component("Component")();

    Class.MovementComponent("FooComponent")()();
    Class.CollisionComponent("BarComponent")()();
    Class.GraphicsComponent("FooBarComponent")()();

    Class.Ellipsis("    ...    ")()();


    leftToRight(60)(GameObject, Component);
    topToBottom(30)(MovementComponent, CollisionComponent, GraphicsComponent, Ellipsis);

    CollisionComponent.w = Component.e + (40, 0);

    drawObjects(
        MovementComponent, CollisionComponent, GraphicsComponent, Ellipsis,
        GameObject, Component
    );

    clink(composition)(Component, GameObject);
    link(inheritance)(MovementComponent.s -- Component.e);
    clink(inheritance)(CollisionComponent, Component);
    link(inheritance)(GraphicsComponent.n -- Component.e);
    link(inheritance)(Ellipsis.w -- Component.s);

    item(iAssoc)("0..1")(obj.ne = Component.w);
    item(iAssoc)("0..*")(obj.nw = GameObject.e + (6,0));

    % item(iAssoc)("employee")(obj.sw = Component.e);
    % item(iAssoc)("employer")(obj.se = C.w);
    % item(iAssoc)("0..*")(obj.ne = C.w);
    % item(iAssoc)("works for")(obj.s = .5[P.e,C.w]);

endfig;



end
