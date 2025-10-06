import QtQuick 2.15

import view.component 1.0
import view.constant 1.0

import Backend.Viewcontrol 1.0
import Backend.Viewmodel 1.0

CPanel {
    property var verificationController: Verification
    property var viewmodelInterface: ViewmodelInterface

    VerificationState {
        id: statePanel
        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            margins: Constant.average
        }
        height: Constant.averageHeight
        currentState: viewmodelInterface.verificationState.value
        onCurrentStateChanged: {
            viewmodelInterface.verificationState.value = currentState;
        }
    }

    InputPanel {
        id: inputPanel
        anchors {
            right: parent.right
            left: parent.left
            top: statePanel.bottom
            bottom: controlPanel.top
        }
        title: "VERIFICATION DATA"
        text: (viewmodelInterface.verificationInfo.value !== text)? viewmodelInterface.verificationInfo.value: text;

        onTextChanged: {
            viewmodelInterface.verificationInfo.value = text
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
            verificationController.verify()
        }
    }
}
