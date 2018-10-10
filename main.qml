import QtQuick 2.11
import QtQuick.Controls 2.4

import "view/login/" as LoginView
import "view/task/" as TaskView
ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("JD Coupon")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Login")
                width: parent.width
                onClicked: {
                    stackView.push(loginWindow)
//                    stackView.push("Login.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Task")
                width: parent.width
                onClicked: {
                    stackView.push(taskWindow)
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }
    LoginView.Login{
        id: loginWindow
    }
    TaskView.Task{
        id: taskWindow
    }
    Connections{
        target: loginWindow
        onLogin:{
            if(status){
                console.log("login success")
                stackView.pop()
            }else{
                console.log("login fail")

            }
        }
    }
}
