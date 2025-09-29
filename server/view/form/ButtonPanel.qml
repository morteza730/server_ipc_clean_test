import QtQuick 2.15
import QtQuick.Controls 2.15

import view.component 1.0
import view.constant 1.0

Item {
    id:root
    CMenu{
        anchors.fill: parent

        ListModel{
            id:model
            ListElement{name:"VAS Info";page:"VASInfo.qml"}
            ListElement{name:"BCR Data";page:"BCRData.qml"}
        }

        CButtonGroup{
            defaultSelection:0
            height:parent.height*(0.4)
            anchors{
                left: parent.left
                right:parent.right
                top:parent.top
                margins: Constant.small
            }
            colomn:1
            row:2
            modelProperty:model
            actionProperty:function(input){loader.setSource(input.page)}
        }
    }
}
