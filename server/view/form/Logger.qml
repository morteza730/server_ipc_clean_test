import QtQuick 2.15

import view.constant 1.0
import view.component 1.0

import Backend.Viewmodel 1.0

CPanel {
    property var viewmodelInterface: ViewmodelInterface

    ResultPanel {
        id: resultPanel
        anchors {
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }
        height: Constant.largeHeight
        text: viewmodelInterface.logInfo.value
    }
}
