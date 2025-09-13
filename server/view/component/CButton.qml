import QtQuick 2.15
import QtQuick.Controls 2.15
// import QtQuick.Controls.Material 2.15

import view.constant 1.0

RoundButton {
    id: button

    property color defaultColor: Constant.buttonColor
    property color selectColor: Constant.acceptColor
    property bool round: false

    font {
        pixelSize: Constant.smallFontSize
        family: Constant.fontFamily
    }

    background: Rectangle {
        id: recOnBack
        anchors.fill: parent

        radius: (round) ? width : 3
        color: (parent.checked || parent.down)? button.selectColor : button.defaultColor
        border {
            color: Qt.darker(defaultColor)
            width: 1
        }
    }
}
