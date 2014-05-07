import QtQuick 1.1

// Layout for the menu

Rectangle {
    id: menu

    width: 760
    height: 755
    color: "white"



       ListView{
     id:column
     clip:true
     anchors { top: parent.top; bottom: parent.bottom; left: parent.left; right: parent.right; margins: 0 }
     model:menuModel
     delegate:

Rectangle{width:parent.width*98/100; height:80;



    // Layout for the first column


    Rectangle{
        id:tablet
        anchors.top: parent.top

        width: 130; height:80; color: "#00aaee"; border.color: "#00aaee"

        Text{anchors.top:parent.top;anchors.left:parent.left;text:"Menu "+(index+1); anchors.margins:5; color: "white"}

    }

    // Left Arrow

    Rectangle{
        id:arrowL
        anchors.top: parent.top
        anchors.left:tablet.right
        width:30
        height:80
        border.color:"#00aaee"
        color:"#00aaee"

        Image {
            width:25
            height:75
            anchors.centerIn:parent
            source: "arrowL.png"
        }

        MouseArea{

            anchors.fill: parent
            onClicked:list1.positionViewAtBeginning()
        }

    }

    // Right Arrow

    Rectangle{
        id:arrowR
        anchors.top: parent.top
        anchors.right:parent.right
        width:30
        height:80
        border.color:"#00aaee"
        color:"#00aaee"

        Image {
            width:25
            height:75
            anchors.centerIn:parent
            source: "arrowR.png"
        }

        MouseArea{

            anchors.fill: parent
            onClicked:list1.positionViewAtEnd()
        }

    }


    // Layout for the first menu
    Rectangle{
        id:menuZone
        anchors.top: parent.top
        anchors.left:arrowL.right
        anchors.right:arrowR.left
        height:80
        color: "#00aaee"
        border.color:"#00aaee"

        ListView {
            snapMode: ListView.SnapToItem
            id:list1
            clip:true
            anchors { top: parent.top; bottom: parent.bottom; left: parent.left; right: parent.right; margins: 0 }
            orientation:Qt.Horizontal
            model:modelData
            delegate: Rectangle { width: 160; height:80; color: "white"; border.color: "#00aaee"

                Text{ color:"#00aaee";id: text1; font.italic: true;anchors.top:parent.top;anchors.left:parent.left;text:modelData.type+" :"; anchors.margins:5;}
                Text{anchors.top:text1.bottom;anchors.left:parent.left;text:modelData.name; anchors.right:parent.right;elide:Text.ElideRight;anchors.margins:5; color:"#00aaee";}
                Text{anchors.bottom:parent.bottom;anchors.right:parent.right;text:modelData.price; anchors.margins:5; color:"#00aaee";}
            }
        }


    }

}


       }









}
