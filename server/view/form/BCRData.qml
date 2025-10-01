import QtQuick 2.15

import view.component 1.0
import view.constant 1.0

import Backend.Viewcontrol 1.0
import Backend.Viewmodel 1.0

CPanel {
    property var bcrRequestController: BCRRequest
    property var bcrReceiveController: BCRReceive
    property var viewmodelInterface: ViewmodelInterface

    BCRRequestAck {
        id: requestAck
        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            margins: Constant.average
        }
        height: Constant.averageHeight

        onSendAck:(ack)=>{
            bcrRequestController.answerBCRRequest(ack)
        }
    }

    InputPanel {
        id: inputPanel
        anchors {
            right: parent.right
            left: parent.left
            top: requestAck.bottom
            bottom: controlPanel.top
        }
        title: "BCR DATA"
        text: (viewmodelInterface.bcrReceiveInfo.value !== text)? viewmodelInterface.bcrReceiveInfo.value: text;

        onTextChanged: {
            viewmodelInterface.bcrReceiveInfo.value = text
        }
    }

    ControlPanel {
        id: controlPanel
        anchors {
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }
        height: Constant.smallHeight

        onSendClicked: {
            bcrReceiveController.send()
        }
    }
}
