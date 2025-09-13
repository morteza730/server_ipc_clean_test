pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property int width: 800
    readonly property int height: 600

    readonly property int minWidth: 800
    readonly property int minHeight: 600

    readonly property int small: 3
    readonly property int average: 5
    readonly property int large: 10
    readonly property int huge: 20

    readonly property int smallFontSize: 13
    readonly property int averageFontSize: 16
    readonly property int largeFontSize: 24

    readonly property string fontFamily: "Roboto"

    readonly property int smallHeight: 50
    readonly property int averageHeight: 70
    readonly property int largeHeight: 150

    readonly property int smallWidth: 100
    readonly property int averageWidth: 200
    readonly property int largeWidth: 400

    readonly property color backgroundColor: "#1e2024"
    readonly property color menuColor: "#a4aeba"
    readonly property color buttonColor: "#b7c5cf"
    readonly property color headerColor: "#546773"
    readonly property color panelColor: "#afaa9f"
    readonly property color subpanelColor:"#dad9d3"

    readonly property color warningColor: "#ff6b6b"
    readonly property color acceptColor: "#4dffc7"
    readonly property color lightColor: "#ffffff"
    readonly property color darkColor: "#000000"
    readonly property color transparentColor: "#00000000"
}
