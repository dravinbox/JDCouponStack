import QtQuick 2.4
import QtQuick.Dialogs 1.2

import UserModel 1.0

LoginForm {
    id: loginform
    visible: false

    signal login(bool status)

    Item{
        id: loginPwdKeys
        Keys.onReturnPressed: {
            loginBtn.clicked()
        }

    }

    loginBtn.onClicked:{
        var username = usernameTF.text
        var passowrd = passwordTF.text
        if(username =='' || passowrd ==''){
            tipText.text=qsTr("username or password is empty")
            tipDialog.open()
        }else{
            aUser.setUserName(username)
            aUser.setPassword(passowrd)
            aUser.toLogin()
//            if(aUser.toLogin()){
//                login(true)
//            }else{
//                tipText.text=qsTr("username or password is wrong")
//                tipDialog.open()
//            }

        }

    }
    cancelBtn.onClicked: {
        console.log("cancel")
            aUser.toLogin()
    }


    Dialog{
        id: tipDialog
        Text {
            id: tipText
        }
    }
    User {
        id: aUser
    }
    Connections{
        target: aUser
        onLoginStatus: {
            if(status){
                login(true)
            }else{
                tipText.text=qsTr("username or password is wrong")
                tipDialog.open()
            }
        }
    }
}

