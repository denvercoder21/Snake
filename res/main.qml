import QtQuick 2.0
import QtQuick.Controls 1.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Snake")

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello")
    }
}