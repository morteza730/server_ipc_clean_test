import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0

SpinBox {
    id: spinBox
    property color defaultColor: "transparent"

    editable: true

    value: 0
    font.pixelSize: Constant.smallFontSize

    background: Rectangle{
        id:recOnBack
        anchors.fill: parent
        color: Constant.lightColor

        border{
            width: 1
            color: Constant.buttonColor
        }
    }
}
