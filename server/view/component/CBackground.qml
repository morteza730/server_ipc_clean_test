import QtQuick 2.15

import view.constant 1.0

Rectangle {
    id: background
    property alias imageSource: backgroundImage.source

    anchors.fill: parent
    color: Constant.backgroundColor

    Image {
        id: backgroundImage
        anchors.centerIn: parent
        fillMode: Qt.IgnoreAspectRatio
        width: parent.width
        height: parent.height
    }
}
