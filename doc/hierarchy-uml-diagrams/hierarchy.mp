% Hierarchy number 01

input metauml;
input hierarchy_template;
input hierarchy_util;

H_SPACING = 50;
V_SPACING = 20;

def Reset =
    save Meltable, GameObject, StaticGameObject, DynamicGameObject, Bed, Igloo, Movable, Snowman, Car;
enddef;


beginfig(1);
    Reset;

    Interface.GameObject("GameObject")();
    Interface.StaticGameObject("StaticGameObject")();
    Interface.DynamicGameObject("DynamicGameObject")();

	Class.Bed("Bed")()();
	Class.Igloo("Igloo")()();

	Class.Snowman("Snowman")()();
	Class.Car("Car")()();

    Hierarchy(30)(V_SPACING)(GameObject)(StaticGameObject, DynamicGameObject);
    Hierarchy(10)(V_SPACING)(StaticGameObject)(Bed, Igloo);
    Hierarchy(10)(V_SPACING)(DynamicGameObject)(Snowman, Car);
endfig;


beginfig(2);
    Reset;

    Interface.GameObject("GameObject")();
    Interface.StaticGameObject("StaticGameObject")();
    Interface.DynamicGameObject("DynamicGameObject")();

	Class.Bed("Bed")()();
	Class.Igloo("Igloo")()("melt()");

	Class.Snowman("Snowman")()("melt()");
	Class.Car("Car")()();

    Hierarchy(30)(V_SPACING)(GameObject)(StaticGameObject, DynamicGameObject);
    Hierarchy(10)(V_SPACING)(StaticGameObject)(Bed, Igloo);
    Hierarchy(10)(V_SPACING)(DynamicGameObject)(Snowman, Car);
endfig;



beginfig(3);
    Reset;

    Interface.Meltable("Meltable")("melt()");
    Interface.GameObject("GameObject")();
    Interface.StaticGameObject("StaticGameObject")();
    Interface.DynamicGameObject("DynamicGameObject")();

    Class.Bed("Bed")()();
    Class.Igloo("Igloo")()();

    Class.Snowman("Snowman")()();
    Class.Car("Car")()();

    Hierarchy(80)(20)(GameObject)(StaticGameObject, DynamicGameObject);
    Hierarchy(10)(30)(StaticGameObject)(Bed, Igloo);
    Hierarchy(10)(30)(DynamicGameObject)(Snowman, Car);


    Meltable.top = StaticGameObject.top;
    drawObject(Meltable);

    link(inheritance)(pathStepY(Igloo.n + (5,0), Meltable.s, 10));
    link(inheritance)(pathStepY(Snowman.n - (5,0), Meltable.s, 10));
endfig;



beginfig(4);
    Reset;

    Interface.GameObject("GameObject")("melt()");
    Interface.StaticGameObject("StaticGameObject")();
    Interface.DynamicGameObject("DynamicGameObject")();

	Class.Bed("Bed")()();
	Class.Igloo("Igloo")()();

	Class.Snowman("Snowman")()();
	Class.Car("Car")()();

    Hierarchy(30)(V_SPACING)(GameObject)(StaticGameObject, DynamicGameObject);
    Hierarchy(10)(V_SPACING)(StaticGameObject)(Bed, Igloo);
    Hierarchy(10)(V_SPACING)(DynamicGameObject)(Snowman, Car);
endfig;



end
