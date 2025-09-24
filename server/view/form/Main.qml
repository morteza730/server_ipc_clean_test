import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

import Backend.Viewcontrol 1.0
import Backend.Viewmodel 1.0

ApplicationWindow {
    id:mainPage
    property var vasInfo: VasInfo
    property var viewmodelInterface: ViewmodelInterface

    title: "Server"
    width: Constant.width
    height: Constant.height

    minimumWidth: Constant.width
    minimumHeight:Constant.height

    visible: true

    CBackground {
    }

    CPanel {
        id:panel
        anchors {
            fill:parent
            margins: Constant.small
        }

        InputPanel {
            id: inputPanel
            anchors {
                right: parent.right
                left: parent.left
                top: parent.top
                bottom: controlPanel.top
            }
            text: viewmodelInterface.vasInfo.value
        }

        ControlPanel {
            id: controlPanel
            anchors {
                right: parent.right
                left: parent.left
                bottom: resultPanel.top
            }
            height: Constant.smallHeight

            onSendClicked: {
                vasInfo.send()
            }
        }

        ResultPanel {
            id: resultPanel
            anchors {
                right: parent.right
                left: parent.left
                bottom: parent.bottom
            }
            height: Constant.largeHeight
            text: viewmodelInterface.trxInfo.value
        }
    }
}
