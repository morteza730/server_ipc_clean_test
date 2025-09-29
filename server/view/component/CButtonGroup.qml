import QtQuick 2.15
import QtQuick.Controls 2.15

import view.component 1.0
import view.constant 1.0


Item {
    id:buttongroup

    property ListModel modelProperty
    property var actionProperty
    property int defaultSelection:-1
    property int colomn
    property int row

    ButtonGroup{
        id:group
        exclusive:true
    }

    GridView{
        id:grid
        interactive: false
        anchors{
            fill: parent
            margins: Constant.small
        }
        cellHeight:height/row
        cellWidth:width/colomn
        model: modelProperty
        delegate: CButton{
            checked: (defaultSelection == index)
            checkable: true
            // font.pixelSize: 12
            ButtonGroup.group: group
            width: grid.width/colomn
            height: grid.height/row
            text: name
            onCheckedChanged:{
                if (checked){
                    actionProperty(model)
                    // console.log(index,defaultSelection,checked)
                }
            }
        }
    }
}
