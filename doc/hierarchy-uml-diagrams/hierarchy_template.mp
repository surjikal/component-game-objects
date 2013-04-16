if known _metauml_skin_simple_mp:
  expandafter endinput
fi;
_metauml_skin_simple_mp:=1;

% iClass.foreColor := (0.2, 0.1, 0.3);
% iClass.iName.iFont.name := "cmr12";

% iNote.foreColor :=(0.9, 0.6, 0.4);



DEFAULT_RELATION_WIDTH := 15;
DEFAULT_RELATION_HEIGHT := 5;


vardef AssociationUniInfo@# =
  LinkInfo@#;

  @#widthA      = 0;
  @#heightA     = 0;
  @#drawMethodA = "drawNothing";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawArrow";

  @#drawMethod = "drawLine";
enddef;

AssociationUniInfo.associationUni;


vardef InheritanceInfo@# =
  LinkInfo@#;

  @#widthA      = 0;
  @#heightA     = 0;
  @#drawMethodA = "drawNothing";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawTriangle";

  @#drawMethod = "drawLine";
enddef;

InheritanceInfo.inheritance;

vardef AggregationInfo@# =
  LinkInfo@#;

  @#widthA      = 0;
  @#heightA     = 0;
  @#drawMethodA = "drawNothing";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawDiamond";

  @#drawMethod = "drawLine";
enddef;

AggregationInfo.aggregation;

vardef AggregationUniInfo@# =
  LinkInfo@#;

  @#widthA      = DEFAULT_RELATION_WIDTH;
  @#heightA     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodA = "drawArrow";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawDiamond";

  @#drawMethod = "drawLine";
enddef;

AggregationUniInfo.aggregationUni;


vardef CompositionInfo@# =
  LinkInfo@#;

  @#widthA      = 0;
  @#heightA     = 0;
  @#drawMethodA = "drawNothing";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawDiamondBlack";

  @#drawMethod = "drawLine";
enddef;

CompositionInfo.composition;


vardef CompositionUniInfo@# =
  LinkInfo@#;

  @#widthA      = DEFAULT_RELATION_WIDTH;
  @#heightA     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodA = "drawArrow";

  @#widthB      = DEFAULT_RELATION_WIDTH;
  @#heightB     = DEFAULT_RELATION_HEIGHT;
  @#drawMethodB = "drawDiamondBlack";

  @#drawMethod = "drawLine";
enddef;

CompositionUniInfo.compositionUni;


vardef NoteInfo@#=
  attributes(@#);
  var(color)   foreColor, borderColor;
  var(numeric) horizontalFolding, verticalFolding;

  FontInfo.@#iFont("tyxtt", .7);
  @#iFont.ignoreNegativeBase := 1;

  PictureInfo.@#iText  (2, 2, 2, 2)(@#iFont);
  PictureStackInfo.@#iStack (0, 0, 0, 0)(9)(@#iText);

  @#iStack.iPict.ignoreNegativeBase := 1;

  ShadeInfo.@#iShade;
  Margins.@#(2,2,2,2);

  @#foreColor   := .9white;
  @#borderColor := black;
  @#horizontalFolding := 5;
  @#verticalFolding := 5;
enddef;

NoteInfo.iNote;


vardef ClassInfo@#=
  attributes(@#);
  var(numeric) featureAccessSpacing, accessWidth, accessHeight;
  var(color)   foreColor, borderColor;

  FontInfo.@#nameFont(metauml_defaultFont, defaultscale);

  FontInfo.@#attributeFont ("tyxtt", .7);
  FontInfo.@#methodFont    ("tyxtt", .7);
  FontInfo.@#stereotypeFont(metauml_defaultFont, .7);

  ShadeInfo.@#iShade;

  @#featureAccessSpacing := 0;
  @#accessWidth := 0;
  @#accessHeight := 0;

  @#foreColor := .9white;
  @#borderColor := .9black;

  PictureInfo.@#iName      (2, 2, 1, 3)(@#nameFont);

  PictureInfo.@#iStereotype(2, -5, 2, 2)(@#stereotypeFont);
  PictureInfo.@#iAttribute (2, 2, 0.7, 0)(@#attributeFont);
  PictureInfo.@#iMethod    (2, 2, 0.7, 0)(@#methodFont);

  PictureStackInfo.@#iStereotypeStack(0, 2, 1, 1)(5.5)(@#iStereotype);
  PictureStackInfo.@#iAttributeStack (0, 2, 3, 2)(5.5)(@#iAttribute); % 8.5
  PictureStackInfo.@#iMethodStack    (0, 2, 2.5, 2)(8)(@#iMethod);


  @#iAttributeStack.iPict.bottom := 2;
  % @#iAttributeStack.iPict.boxed := 1;
  @#iMethodStack.iPict.bottom := 2;
  @#iMethodStack.iPict.top := 2;
  % @#iMethodStack.iPict.boxed := 1;

  @#iAttributeStack.top := 0;
  @#iAttributeStack.bottom := 0;
  @#iMethodStack.top := 0;
  @#iMethodStack.bottom := 0;

  LockInfo.@#iLock(0, 0, .6, .15, .55, .4white, .6white, .7white, .3white);

  @#iName.ignoreNegativeBase := 1;
  @#iAttributeStack.iPict.ignoreNegativeBase := 1;
  @#iMethodStack.iPict.ignoreNegativeBase := 1;
  @#iStereotypeStack.iPict.ignoreNegativeBase := 1;
enddef;

ClassInfo.iClass;

ClassInfoCopy.iInterface(iClass);
iInterface.iAttributeStack.top := 0;
iInterface.iAttributeStack.bottom := 0;
iInterface.iName.iFont.name := metauml_defaultFontOblique;


ClassInfoCopy.iBlend(iInterface);
iBlend.foreColor := (1, 1, 1);