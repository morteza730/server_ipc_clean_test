import QtQuick 2.15
import QtQuick.Controls 2.15

import view.component 1.0
import view.constant 1.0

CSubpanel {
    id: root
    property alias text: textArea.text

    Flickable {
        anchors {
            fill: parent
            margins: Constant.average
        }
        ScrollBar.vertical: ScrollBar {
            id: scrollviewVertical
        }
        boundsBehavior: Flickable.StopAtBounds
        interactive: true
        contentHeight: textArea.contentHeight + Constant.large
        contentWidth: textArea.contentWidth + Constant.small
        clip: true

        TextArea {
            id: textArea
            anchors {
                left: parent.left
                top: parent.top
                bottom: parent.bottom
            }
            font {
                pixelSize: Constant.smallFontSize
                family: Constant.fontFamily
            }
            width: root.width - Constant.small - scrollviewVertical.implicitWidth 
            inputMethodHints: Qt.ImhDigitsOnly
            leftPadding: Constant.average
            verticalAlignment: Text.AlignVCenter
            wrapMode: TextInput.Wrap
        }
    }
}
