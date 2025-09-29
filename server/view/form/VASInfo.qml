import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

import Backend.Viewcontrol 1.0
import Backend.Viewmodel 1.0

CPanel {
    id:vasInfo

    property var vasInfoController: VASInfo
    property var viewmodelInterface: ViewmodelInterface

    InputPanel {
        id: inputPanel
        anchors {
            right: parent.right
            left: parent.left
            top: parent.top
            bottom: controlPanel.top
        }
        title: "VAS INFO"
        text: viewmodelInterface.vasInfo.value

        onTextChanged: {
            viewmodelInterface.vasInfo.value = text
        }
    }

    ControlPanel {
        id: controlPanel
        anchors {
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }
        height: Constant.smallHeight

        onSendClicked: {
            vasInfoController.send()
        }
    }
}
