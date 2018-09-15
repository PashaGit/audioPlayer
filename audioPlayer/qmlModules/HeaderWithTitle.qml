import QtQuick 2.0

Rectangle{
    id: areaForDragWindow;
    color: "#232323";
    clip: true;
    Text{
        anchors.horizontalCenter: areaForDragWindow.horizontalCenter;
        anchors.verticalCenter: areaForDragWindow.verticalCenter;
        style:  Text.Outline;
        styleColor: "blue";
        text: "audioPlayer";
        color: "white";
        font.letterSpacing: 5
    }
    Rectangle{
        id: closeWin;
        anchors.right: areaForDragWindow.right;
        anchors.rightMargin: -20;
        width: 50;
        radius: 20;
        color: "#ff9900";
        height: areaForDragWindow.height;
        Image {
            id: img
            anchors.leftMargin: 12
            source: "qrc:/resources/close.png"
            sourceSize.width: parent.width/2;
            sourceSize.height: parent.height/2;
            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
        }

    }
    MouseArea{
        id: msClose;
        z:3;
        property bool enteredMouse: false;
        anchors.fill: closeWin;
        hoverEnabled: true;
        onEntered: {
            enteredMouse=true;
        }
        onExited: {
            enteredMouse=false;
        }
        onReleased: {
            if(enteredMouse==true){
                win.close();
            }
        }
    }
}
