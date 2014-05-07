import QtQuick 1.1


Rectangle {
    id: menu

    width: 760
    height: 100
    color: "white"


    // Layout for the title

    Rectangle{
        id:titleZone
        anchors.top: parent.top
        width: parent.width;
        height: 40;
        color: "#00aaee"

        // Title
        Text{ anchors.centerIn: parent; text:"DETAILS";color:"white";}
    }

    // Layout for the selection menu
    Rectangle{

        id:selectMenuZone
        anchors.top: titleZone.bottom
        width: parent.width;
        height: 60;
        color: "white"

        // Horizontal Layout for the selection menu
        Row{

            id:selectMenu
            anchors.centerIn: parent
            spacing:100

            // Button "Ticket"
            Rectangle {
                id:ticket
                objectName:"ticket"
                radius:10
                width: 80
                height: 40
                color: "#00aaee"
                border.color: "#00aaee"
                Text{id:ticketText;anchors.centerIn: parent; text:"Ticket";color:"white" ;}

                signal clicked

                MouseArea  {
                        anchors.fill: parent
                        onClicked:
                        {
                            ticket.clicked();
                            parent.color= "#00aaee";
                            ticketText.color="white";

                            table.color="white";
                            tableText.color="#00aaee";

                        }
                    }
            }

            // Button "Table"
            Rectangle {
                id:table
                objectName:"table"
                radius:10
                width: 80
                height: 40
                color: "white"
                border.color: "#00aaee"
                Text{id:tableText;anchors.centerIn: parent; text:"Table";color:"#00aaee";}

                signal clicked

                    MouseArea  {
                            anchors.fill: parent
                            onClicked:
                            {
                                table.clicked();
                                parent.color= "#00aaee";
                                tableText.color="white";

                                ticket.color="white";
                                ticketText.color="#00aaee";
                            }
                        }


            }
        }

    }
}
