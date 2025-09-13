import QtQuick 2.15

import view.constant 1.0

Rectangle {
    color: Constant.panelColor
    anchors.margins: Constant.average

    border{
        width: 3
        color: Qt.darker(color)
    }
}
