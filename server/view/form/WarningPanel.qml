import QtQuick 2.15
import QtQuick.Controls 2.15

import view.component 1.0
import view.constant 1.0

import Backend.Viewmodel 1.0

Item {
    property var viewmodelInterface: ViewmodelInterface

    CPanel{
        anchors.fill: parent

        Column{
            anchors{
                margins:Constant.average
                fill: parent
            }
            CLabel{
                id:labelWarnings
                width: parent.width
                height: parent.height*(0.1)
                text: "ALERSTS"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Rectangle {
                id: bcrLedContainer
                width: parent.width
                height: parent.height*(0.1)
                color: Constant.subpanelColor

                CLabel {
                    id: label
                    anchors {
                        left: parent.left
                        leftMargin: Constant.average
                        verticalCenter: parent.verticalCenter
                    }
                    text: "BCR REQUEST"
                }

                CLed {
                    id: bcrRecuestLed
                    anchors {
                        right: parent.right
                        rightMargin: Constant.huge
                        verticalCenter: parent.verticalCenter
                    }
                    size: 10
                    state:(viewmodelInterface.bcrRecuestState.value === "true")? true:false
                }
            }
        }
    }
}
