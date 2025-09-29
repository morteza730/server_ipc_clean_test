import QtQuick 2.15

import view.constant 1.0

Rectangle{
    id:led

    property bool state: false
    property int size: Constant.average

    width:size
    height:width
    radius:width
    color: (state)?Constant.acceptColor:Constant.warningColor
}
