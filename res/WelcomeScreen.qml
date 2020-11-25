import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Rectangle {
    id: root

    signal startClicked
    signal highscoreClicked
    signal helpClicked

    radius: 15

    color: "white"

    visible: false

    layer.enabled: true
    layer.effect: DropShadow {
        transparentBorder: true
        color: "#888888"
        samples: 32
    }

    ColumnLayout {
        id: layout

        anchors {
            fill: root
            margins: 20
        }

        spacing: 12

        Text {
            id: headline

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Snake 🐍")
            font {
                pixelSize: 30
            }
        }

        Text {
            id: welcomeMessage

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            horizontalAlignment: Qt.AlignHCenter

            wrapMode: Text.WordWrap

            text: qsTr("This is a classic snake game as you have played on your old Nokia phone. Have fun chasing that highscore!")

            color: "#777777"
        }

        Item {
            id: dummy

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RoundButton {
            id: startButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Start Game")

            onClicked: startClicked()
        }

        RoundButton {
            id: highscoreButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Highscore")

            onClicked: highscoreClicked()
        }

        RoundButton {
            id: helpButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Help")

            onClicked: helpClicked()
        }

        RoundButton {
            id: quitButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Quit")

            onClicked: Qt.quit()
        }
    }
}
