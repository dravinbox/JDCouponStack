import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Page {
    id: page

    title: qsTr("Login")

    visible: true
    property alias passwordTF: passwordTF
    property alias usernameTF: usernameTF
    property alias loginBtn: loginBtn
    property alias cancelBtn: cancelBtn

    ColumnLayout {
        width: 320
        height: 160
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        RowLayout {

            Label {
                text: qsTr("Username")
                Layout.fillWidth: true
            }
            TextField {
                id: usernameTF
                Layout.fillWidth: true
                placeholderText: qsTr("enter username")
            }
        }
        RowLayout {
            Label {
                text: qsTr("Password")
                Layout.fillWidth: true
            }
            TextField {
                id: passwordTF
                Layout.fillWidth: true
                placeholderText: qsTr("enter password")
                echoMode: "Password"
                Keys.forwardTo: [loginPwdKeys]
            }
        }
        RowLayout {
            Button {
                id: loginBtn
                text: qsTr("login")
            }
            Button {
                id: cancelBtn
                text: qsTr("cancel")
            }
        }
    }
}
