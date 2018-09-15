import QtQuick 2.0

Rectangle{
    id: rec1;
    color: "black";
    layer.enabled: true;
    layer.effect: maskForRecBFP.setId(rec1);

    Rectangle{
        id: imageRec;
        width: 40;
        height: parent.height/2;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.leftMargin: 5;
        anchors.topMargin: 7;
        color: "black";
        border.width: 1;
        border.color: "green";
        Image{
            anchors.margins: 1;
            anchors.fill: parent;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            source: lv.currentItem.getImage();
            clip: true;
        }
    }

    Text {
       anchors.top: imageRec.bottom;
       anchors.left: imageRec.left;
       anchors.topMargin: 2;
       color: "green";
       text: lv.currentItem.getDuration();
    }
    Rectangle{
        id: stp;
        anchors.right: parent.right;
        anchors.rightMargin: 5;
        anchors.verticalCenter: parent.verticalCenter;

        width: 25;
        height: 25;
        clip: true;
        color: "transparent";
        Image{
            anchors.fill: parent;
            anchors.margins: 2;
            source: "qrc:/resources/stop.png"
        }
        MouseArea{
            property bool enteredMouse1: false;
            anchors.fill: parent;
            onEntered: {
                enteredMouse1=true;
            }
            onExited: {
                enteredMouse1=false;
            }
            onReleased: {
                if(enteredMouse1==true){
                     DataManagerLV.stop()
                }
            }
        }
    }
    Rectangle{
        id: strt;
        anchors.right: stp.left;
        anchors.rightMargin: 5;
        anchors.verticalCenter: parent.verticalCenter;
        width: 50;
        height: 50;
        clip: true;
        color: "transparent";
        Image{
            height: 100;
            width: 170;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.margins: 2;
            source: "qrc:/resources/play.png"
        }
        MouseArea{
            property bool enteredMouse: false;
            anchors.fill: parent;
            onEntered: {
                enteredMouse=true;
            }
            onExited: {
                enteredMouse=false;
            }
            onReleased: {
                if(enteredMouse==true){
                     DataManagerLV.play()
                }
            }
        }
    }

}
