import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

CPanel{
    property alias text: inputText.text

    CLabel {
        id: title
        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            margins: Constant.large
        }
        text: "MESSAGE TO SEND"
    }

    CTextArea {
        id: inputText
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: title.bottom
        }
        anchors.margins: Constant.average
    }
}
