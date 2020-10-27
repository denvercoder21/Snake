import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    radius: 15

    color: "white"

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

        Rectangle {
            id: body

            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout {
                id: keyMapLayout

                anchors.fill: body

                Rectangle {
                    id: arrows

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    color: "blue"
                }

                RowLayout {
                    id: enterRow

                    Item {
                        id: enterKeyItemLeft

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        KeyboardKey {
                            id: enterKeyIcon

                            anchors.verticalCenter: enterKeyItemLeft.verticalCenter

                            width: 50
                            height: 25

                            text: qsTr("↵ Enter")
                            textPixelSize: 11
                        }
                    }

                    Item {
                        id: enterKeyItemRight

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            anchors.fill: enterKeyItemRight
                            verticalAlignment: Text.AlignVCenter
                            text: qsTr("Start Game")
                        }
                    }
                }

                RowLayout {
                    id: highscoreRow

                    Item {
                        id: highscoreKeyItemLeft

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        KeyboardKey {
                            id: highscoreKeyIcon

                            anchors.verticalCenter: highscoreKeyItemLeft.verticalCenter

                            width: 25
                            height: 25

                            text: qsTr("H")
                        }
                    }

                    Item {
                        id: highscoreKeyItemRight

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            anchors.fill: highscoreKeyItemRight
                            verticalAlignment: Text.AlignVCenter
                            text: qsTr("Show Highscores")
                        }
                    }
                }

                RowLayout {
                    id: quitRow

                    Item {
                        id: quitItemLeft

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        KeyboardKey {
                            id: quitKeyIcon

                            anchors.verticalCenter: quitItemLeft.verticalCenter

                            width: 25
                            height: 25

                            text: qsTr("Q")
                        }
                    }

                    Item {
                        id: quitItemRight

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Text {
                            anchors.fill: quitItemRight
                            verticalAlignment: Text.AlignVCenter
                            text: qsTr("Quit Game")
                        }
                    }
                }
            }
        }
    }

//    KeyboardKey {
//        id: enterButton

//        width: 50
//        height: 25

//        text: qsTr("↵ Enter")
//        pixelSize: 11
//    }

//    KeyboardKey {
//        id: quitButton

//        width: 25
//        height: width

//        anchors {
//            left: welcomeScreen.left
//            leftMargin: 15
//            bottom: welcomeScreen.bottom
//            bottomMargin: 15
//        }

//        text: qsTr("Q")
//    }
}
