import QtQuick 2.9


MouseArea{
    z:2;
    anchors.top: headerWithTitle.top;
    anchors.left: headerWithTitle.left;
    anchors.right: headerWithTitle.right;
    height: 20;
    onPressed: {
        previousX = mouseX
        previousY = mouseY
    }
    onMouseXChanged: {
        var dx = mouseX - previousX;
        win.setX(win.x + dx)
    }

    onMouseYChanged: {
        var dy = mouseY - previousY
        win.setY(win.y + dy)
    }
}
