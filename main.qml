import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.2
Window {
    id: window
    visible: true
    width: 1280
    height: 768
    color: "#ffffff"
    title: qsTr("Hello World")
    maximumHeight: 768
    maximumWidth: 1280
    Image {
        id: image
        x: 211
        y: -80
        width: 858
        height: 721
        fillMode: Image.PreserveAspectFit
        source: "273782629011211.png"

        Timer {
            id:timer1
            interval: 100
            running: false
            repeat: true
            onTriggered: {

                txtNumber.text =  Math.floor(Math.random() * 50)
                timer2.start()
                roundButton.enabled = false
            }
        }

        Timer {
            id:timer2
            interval: 10000
            running: false
            repeat: false
            onTriggered: {
                timer1.stop()
                txtNumber.text =  ViewManager.Winnernumber
                btnSave.enabled = true
            }
        }

        RoundButton {
            id: btnSave
            x: 275
            y: 1352
            width: 296
            height: 101
            text: "Save"
            enabled: false
            anchors.topMargin: 676
            font.pointSize: 50
            anchors.top: parent.top
            anchors.left: roundButton.right
            layer.enabled: false
            ColorAnimation {
                from: "#ffffff"
                to: "#000000"
                duration: 200
            }
            onClicked: ViewManager.save();
        }

        Text {
            id: txtNumber
            x: 353
            y: 326
            width: 152
            height: 91
            text: "0"
            font.pixelSize: 120
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MessageDialog {
            id: messageDialog
            title: "توجه"
            text: "بانک بارگذاری نشده،لطفا از منوی تنظمیات میزان شماره های دلخواه را وارد کنید"
            onAccepted: {
                Qt.quit()
            }
        }


        MessageDialog {
            id: messageDialog2
            title: "توجه"
            text: "ذخیره شد،برنامه را دوباره باز کنید"
            onAccepted: {
                Qt.quit()
            }
        }
        RoundButton {

            id: roundButton
            x: 142
            width: 296
            height: 101
            text: "Start"
            layer.enabled: false
            anchors.top: parent.top
            anchors.topMargin: 676
            font.pointSize: 50
            onClicked: {
                var xx = ViewManager.CountDatabse
                console.log(xx)
                if(xx === "" || xx === 0 || xx === "0"){
                    messageDialog.visible = true
                } else {
                    timer1.start()
                    ViewManager.start()
                }
            }
            ColorAnimation {
                from: "white"
                to: "black"
                duration: 200
            }


        }


    }
    Window{
        id: myWindow
        title: "myWindow"
        width: 300
        height: 300
        visible: false
        function open(){
            visible = true
        }
        function close(){
            visible = false
        }
        Column {
            anchors.centerIn: parent

            Label {
                text: "تعداد نفرات را وارد کنید"
            }
            TextInput {
                id: textInput
                width: 80
                height: 40
                text: qsTr("0")
                font.pixelSize: 12
            }
            Button {
                id : btnPeople
                text: "اضافه کردن"
                onClicked:{


                    ViewManager.getPeopleNumber(textInput.text)
                    messageDialog2.visible = true
                }
            }

        }
    }

    RoundButton {
        id: roundButton1
        x: 1116
        y: 578
        width: 127
        height: 131
        text: "Setting"
        font.pointSize: 25
        checkable: false
        enabled: true
        display: AbstractButton.TextBesideIcon
        checked: false
        autoRepeat: false
        flat: false
        onClicked: myWindow.open()
    }


}


