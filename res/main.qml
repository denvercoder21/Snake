import QtQuick 2.12
import QtQuick.Controls 1.0
import QtGraphicalEffects 1.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Snake")

    color: "#BECB02"

    Rectangle {
        id: welcomeScreen

        anchors.centerIn: parent
        width: 450
        height: 350
        radius: 15

        color: "white"

        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
            color: "#888888"
            samples: 32
        }

        Text {
            id: headline

            anchors {
                top: welcomeScreen.top
                topMargin: 30
                horizontalCenter: welcomeScreen.horizontalCenter
            }

            text: qsTr("Snake 🐍")
            font {
                pixelSize: 30
            }
        }

        Text {
            id: welcomeMessage

            anchors {
                left: welcomeScreen.left
                right: welcomeScreen.right
                leftMargin: 10
                rightMargin: 10
                top: headline.bottom
                topMargin: 10
            }

            horizontalAlignment: Text.AlignHCenter

            wrapMode: Text.WordWrap
            color: "#777777"

            text: qsTr("This is a classic snake game as you have played on your old Nokia phone. Have fun chasing that highscore!")
        }

        Rectangle {
            id: enterButton

            width: 50
            height: width / 2
            radius: 6

            border {
                color: "#AAAAAA"
                width: 1
            }

            Text {
                anchors {
                    fill: parent
                    rightMargin: 5
                }

                color: "#AAAAAA"
                text: qsTr("↵ Enter")

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight

                font {
                    pixelSize: 11
                }
            }
        }

        Rectangle {
            id: quitButton

            anchors {
                left: welcomeScreen.left
                leftMargin: 15
                bottom: welcomeScreen.bottom
                bottomMargin: 15
            }

            width: 25
            height: width
            radius: 6

            border {
                color: "#AAAAAA"
                width: 1
            }

            Text {
                anchors.centerIn: parent
                color: "#AAAAAA"
                text: qsTr("Q")
            }
        }
    }

    Shortcut {
        sequence: "Q"
        context: Qt.ApplicationShortcut
        onActivated: Qt.quit()
    }

    Shortcut {
        sequence: "H"
        context: Qt.ApplicationShortcut
        onActivated: console.log("show highscore")
    }
}
