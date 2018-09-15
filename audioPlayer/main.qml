import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.2
import "./qmlModules"
import "./qmlDelegate"
import "./qmlMask"


Window {
    id: win;
    //for move window
    property int previousX
    property int previousY
    //create obj mouse
    DelegateForListView{ id: del; }
    Mask{id: maskForRecBFP;} //mask  for rectangle with obj ButtonForPlay

    visible: true
    width: 300
    height: 480
    flags: Qt.FramelessWindowHint | Qt.Window;
    color: "transparent";

    Rectangle{
        id: root;
        anchors.fill: parent;
        anchors.margins: 39;
        color: "grey";
        radius: 20;

        //create obj for root
        HeaderWithTitle{
            id: headerWithTitle
            anchors.top: parent.top;
            anchors.left: parent.left
            width: parent.width;
            height: 20;
            MouseForWindow{id: mouse; }
        }  //HeaderWithTitle
        StatusBar{
            id: statusBar;
            anchors.top: headerWithTitle.bottom;
            anchors.right: parent.right;
            anchors.left: parent.left;
            width: parent.width;
            height: 15;
        }   //status Bar
        OpenFolder{
            z:2;
            id: buttonForOpenFolder;
            anchors.top: statusBar.bottom;
            anchors.right: parent.right;
            anchors.margins: 10;
            width: 30;
            height: 30;
        } //button for openFolder
        ListView{
            id: lv;
            cacheBuffer: 200;
            anchors.top: statusBar.bottom;
            anchors.left: root.left;
            anchors.right: root.right;
            anchors.bottom: butForPlay.top;
            highlightFollowsCurrentItem : true;
            spacing: 9;
            model: DataManagerLV;
            delegate: del.getComponent();
            clip: true;
            ScrollBar.vertical: ScrollBar{
                parent: lv.parent
                anchors.top: lv.top
                anchors.right: lv.right
                anchors.bottom: lv.bottom
                minimumSize: 0.2;
            }
            onCurrentIndexChanged: {
                DataManagerLV.setIndexPlayList(lv.currentIndex);
            }
        }
        ButtonForPlay{
            id: butForPlay;
            anchors.bottom: root.bottom;
            anchors.left: root.left;
            anchors.right: root.right;
            height: 70;

        }
    }

    Connections{
        target: DataManagerLV;
        onChangedCurrentIndex : {
           lv.currentIndex=indexPl;
        }
    }
    FileDialog{
        id: openFile;
        selectFolder: true;
        onAccepted: {
            var str=fileUrl.toString().slice(8);
            DataManagerLV.setUrl(str);
        }
    }
}
