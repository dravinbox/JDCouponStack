import QtQuick 2.4
import QtQuick.Controls 2.4

Page {
    id: page
    property alias removeTaskBtn: removeTaskBtn
    property alias newTaskBtn: newTaskBtn
    property alias listView1: listView1
    title: qsTr("Task")

    Rectangle {
        id: rectangle
        height: 100
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        Row {
            id: row
            anchors.fill: parent

            Button {
                id: newTaskBtn
                text: qsTr("new Task")
            }
            Button {
                id: removeTaskBtn
                text: qsTr("remove Task")
            }
        }
    }

    Rectangle {
        id: rectangle1
        color: "#ffffff"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: rectangle.bottom
        anchors.topMargin: 0

        ScrollView {
            id: scrollView
            anchors.fill: parent
            clip: true

            ListView {
                id: listView1
                orientation: ListView.Vertical
                anchors.fill: parent
            }
        }
    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2;anchors_height:400;anchors_width:200}
D{i:1;anchors_width:200;anchors_x:54;anchors_y:0}D{i:5;anchors_height:200;anchors_width:200;anchors_x:9;anchors_y:118}
D{i:4;anchors_height:200}
}
 ##^##*/
