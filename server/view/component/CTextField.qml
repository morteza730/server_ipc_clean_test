import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0

TextField {
    text: "0"
    font {
        pixelSize: Constant.smallFontSize
        bold: false
        family: Constant.fontFamily
    }
    inputMethodHints: Qt.ImhDigitsOnly
    leftPadding: Constant.average
    verticalAlignment: Text.AlignVCenter
    autoScroll: false
    wrapMode: TextInput.Wrap
}
