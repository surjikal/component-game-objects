
vardef Hierarchy(expr horizontal_spacing_token)(expr vertical_spacing_token)(suffix root)(text elements) =
    save derived, s, ss;
    numeric s, ss;


    horizontal_spacing := scantokens str horizontal_spacing_token;
    vertical_spacing := scantokens str vertical_spacing_token;

    leftToRight.top(horizontal_spacing)(elements);
    Group.derived(elements);
    topToBottom(vertical_spacing)(root, derived);

    drawObject(root);
    drawObjects(derived);

    forsuffixes Element := elements:
        link(inheritance)(pathStepY(Element.n, root.s, vertical_spacing_token * 1/2));
    endfor;

enddef;

