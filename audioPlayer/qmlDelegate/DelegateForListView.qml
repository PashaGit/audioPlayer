import QtQuick 2.0

Item{
    function getComponent(){
        return componentForListView;
    }
    Component{
        id: componentForListView;
        Rectangle{
            id:mainRecDelegeate;
            function getImage(){return im.source;}
          //  function getNameComposition(){return nComp.text;}
          //  function getFormatFile(){return formFile.text; }
            function getDuration(){return durat.text; }
            property string covarAudioWithR: "0";
            property bool getData: true

            Image{
                id: im;
                width: 40;
                height: parent.height/1.5;
                source: {
                    if(getData){return coverAudio}
                    else {getData=true; return (coverAudio+";"+covarAudioWithR);}
                }
                anchors.top: parent.top;
                anchors.left: parent.left;
                anchors.leftMargin: 5;
                anchors.topMargin: 7;
                clip: true;
            }
            Text {
                id:nComp;
                anchors.left: im.right;
                anchors.verticalCenter: im.verticalCenter;
                text: nameComposition;
                clip: true;
                width: lv.width/3;
                color: "white";
            }
            Text {
                id: durat;
                visible: if(typeData=="file")return true; else if(typeData=="folder")return false;
                anchors.top: im.bottom;
                anchors.left: im.left;
                text: {durationComposition.toFixed(2)}
                color: "green"
            }
            Text {
                id: formFile;
                anchors.top: im.bottom;
                anchors.right: parent.right;
                anchors.rightMargin: 5;
                text: formatFile;
                color: "green";
            }

            color: "#1a1616";
            height: 70;
            width: lv.width;
            border.width: 1;
            border.color: "grey"
            Rectangle{
                id: circle;
                visible: {if(lv.currentIndex==index)return true; else false;}
                radius: 50;
                height: 10;
                width: 10;
                color: "green";
                anchors.right: parent.right;
                anchors.rightMargin: 10;
                anchors.verticalCenter: parent.verticalCenter;
            }
            MouseArea {
                visible: if(typeData=="file")return true; else if(typeData=="folder")return false;
                anchors.fill: parent
                onClicked: lv.currentIndex = model.index
            }
            Connections{
                target: DataManagerLV;
                onReloadImage : {
                    covarAudioWithR=Math.random();
                    getData=false;
                }
            }
        }
    }
}
