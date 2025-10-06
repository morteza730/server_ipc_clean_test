import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

CSubpanel {
    property bool currentState: false

    Row {
        id: stateButtons
        anchors {
            left: parent.left
            leftMargin: Constant.huge
            verticalCenter: parent.verticalCenter
        }
        width: Constant.averageWidth
        height: Constant.smallHeight

        RadioButton {
            text: "TRUE"
            checked: currentState
            onClicked: {
                currentState = true
            }
        }

        RadioButton {
            text: "FALSE"
            checked: !currentState
            onClicked: {
                currentState = false
            }
        }
    }
}
