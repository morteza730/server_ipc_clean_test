import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

CSubpanel {
    signal sendAck(string ack)

    CButton {
        id: sendButton
        anchors {
            left: parent.left
            leftMargin: Constant.huge
            verticalCenter: parent.verticalCenter
        }
        width: Constant.smallWidth
        height: Constant.smallHeight
        text: "SEND ACK"

        onClicked: {
            sendAck(bcrAckResponse.text)
        }
    }

    CTextField {
        id: bcrAckResponse
        anchors {
            right: parent.right
            left: sendButton.right
            verticalCenter: parent.verticalCenter
            leftMargin: Constant.huge
            rightMargin: Constant.huge
        }
        height: Constant.smallHeight
        leftPadding: Constant.huge
    }
}
