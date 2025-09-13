import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0

Label {
    text: "Costum Label"
    font {
        pixelSize: Constant.smallFontSize
        bold: true
        family: Constant.fontFamily
    }
    leftPadding: Constant.average
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter
}
