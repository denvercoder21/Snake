import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    radius: 15

    color: "white"

    visible: false

    layer.enabled: true
    layer.effect: DropShadow {
        transparentBorder: true
        color: "#888888"
        samples: 32
    }

    Text {
        anchors.centerIn: parent
        text: qsTr("Help")
    }
}
