import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: masks;
    property var parentId: masks
    function setId(getId){
        parentId=getId;
        return objMask;
    }
    Component{
        id: objMask;
        OpacityMask {
            maskSource: Item {
                width: parentId.width
                height: parentId.height
                Rectangle {
                    id:rec1;
                    Rectangle{
                        height:parent.radius;
                        anchors.right: parent.right;
                        width: parent.radius;
                    }
                    Rectangle{
                        height:parent.radius;
                        anchors.left: parent.left;
                        width: parent.radius;
                    }
                    anchors.centerIn: parent
                    width: parentId.width
                    height:parentId.height
                    radius: 16;
                }}}


    }
}
