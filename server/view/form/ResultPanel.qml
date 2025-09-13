import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

CSubpanel {
    property alias text: resultContainer.text

    CTextArea {
        id: resultContainer
        anchors.fill: parent
        anchors.margins: Constant.average
    }
}
