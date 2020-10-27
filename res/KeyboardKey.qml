import QtQuick 2.0

Rectangle {
    id: root

    property string text: qsTr("")
    property int textPixelSize

    radius: 6

    border {
        color: "#AAAAAA"
        width: 1
    }

    Text {
        id: keyText

        anchors.centerIn: root

        color: "#AAAAAA"
        text: root.text

        font {
            pixelSize: root.textPixelSize
        }
    }
}
