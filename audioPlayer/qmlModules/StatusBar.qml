import QtQuick 2.0

Rectangle{
    color: "#404040";
    Text{
        id: text1;
        anchors.left: parent.left;
        anchors.leftMargin: 10;
        anchors.verticalCenter: parent.verticalCenter;
        color: "grey"
        text: "compositions: ";
        clip: true;
        width: parent.width/2-10;
    }
    Text{
        anchors.left: text1.right;
        anchors.leftMargin: 10;
        anchors.verticalCenter: parent.verticalCenter;
        color: "grey"
        text: "| folder: ";
    }
}
