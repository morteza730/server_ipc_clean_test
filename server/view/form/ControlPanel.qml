import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

CMenu {
    signal sendClicked()

    CButton {
        id: sendButton
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
            margins: Constant.average
        }
        width: Constant.smallWidth
        text: "SEND"

        onClicked: {
            sendClicked()
        }
    }
}
