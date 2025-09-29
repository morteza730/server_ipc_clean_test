import QtQuick 2.15
import QtQuick.Controls 2.15

import view.constant 1.0
import view.component 1.0

ApplicationWindow {
    id:mainPage

    title: "Server"
    width: Constant.width
    height: Constant.height

    minimumWidth: Constant.width
    minimumHeight:Constant.height

    visible: true

    CBackground {
    }

    Row {
        anchors{
            fill: parent
            margins: Constant.small
        }
        spacing: Constant.small

        Column {
            width:parent.width*(1/5)
            height: parent.height

            ButtonPanel {
                id:preferenceButtonPanel
                width:parent.width
                height: parent.height*(1/2)
            }

            WarningPanel {
                id:preferenceWarningPanel
                width:parent.width
                height: parent.height*(1/2)
            }
        }

        Item {
            width:parent.width*(4/5)
            height: parent.height
            anchors.margins: Constant.average

            Loader {
                id: loader
                clip: true
                anchors {
                    top: parent.top
                    bottom: logger.top
                    bottomMargin: Constant.average
                }
                width:parent.width
            }

            Logger {
                id: logger
                width:parent.width
                height: Constant.largeHeight
                anchors {
                    bottom: parent.bottom
                }
            }
        }
    }
}
