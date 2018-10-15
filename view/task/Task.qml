import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import ColorBLL 1.0

TaskForm {
    visible: false
    newTaskBtn.onClicked: {
//        newTaskDialog.open()
        var colorCode = randomColorCode();
//        colorListModel.insert(0,{"name":colorCode,"colorCode":colorCode})
//        colorListModel.append()
        colorBLL.appendColor(colorCode,colorCode)

    }
    removeTaskBtn.onClicked: {
//        colorListModel.remove(colorListModel.count-1,1)
        colorBLL.removeColor()

    }
    function randomColorCode(){
        var colorCode ="#"
       for(var i=0; i<6; i++ ){
           var ran = Math.ceil(Math.random()*15)
           if(ran<10){
               colorCode+=ran
           }else{
               switch(ran){
               case 10: colorCode+='A';break;
               case 11: colorCode+='B';break;
               case 12: colorCode+='C';break;
               case 13: colorCode+='D';break;
               case 14: colorCode+='E';break;
               case 15: colorCode+='F';break;
                  default:break;
               }
           }

       }

       return colorCode

    }

    Dialog {
        id: newTaskDialog
        Text {
            id: tipText
            text: qsTr("text")
        }
        standardButtons: Dialog.Ok

    }
    ColorBLL{
        id: colorBLL
    }

    listView1.model: colorBLL.data
    listView1.delegate: Item {
        x: 5
        width: 40
        height: 40
//        anchors.fill: parent
        Row {
            id: row1
            Rectangle {
                width: 40
                height: 40
                color: model.modelData.color
//                anchors.left:parent.left
//                anchors.leftMargin:80
            }

            Text {
                text: model.modelData.name
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }
            Button {
                text: qsTr("删除")
                onClicked: {
                    console.log(model.modelData.name)
                    console.log(model)
                }

            }

            spacing: 10
        }
    }

    /*
    listView1.model: ListModel {
        id: colorListModel
        ListElement {
            name: "Grey"
            colorCode: "grey"
        }

        ListElement {
            name: "Red"
            colorCode: "red"
        }

        ListElement {
            name: "Blue"
            colorCode: "blue"
        }

        ListElement {
            name: "Green"
            colorCode: "green"
        }
        ListElement {
            name: "Diy"
            colorCode: "#ff332f"
        }
    }
    // listView1.
    listView1.delegate: Item {
        x: 5
        width: 80
        height: 40
        Row {
            id: row1
            Rectangle {
                width: 40
                height: 40
                color: colorCode
            }

            Text {
                text: name
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }
            spacing: 10
        }
    }
*/


}

