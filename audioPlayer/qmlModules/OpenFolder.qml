import QtQuick 2.0
import QtQuick.Controls 2.2

Button {
    Image{
        anchors.fill: parent;
        anchors.margins: 5;
        source: "../resources/openFolder.png";
    }
    background: Rectangle{
        radius: 20;
        border.width: 1;
        border.color: "blue";
        color: "#696969";
    }
    onReleased: {
        openFile.open();
    }
}
