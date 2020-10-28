import QtQuick 2.12
import QtQuick.Controls 1.0

ApplicationWindow
{
    id: mainWindow

    visible: true
    width: 640
    height: 480
    title: qsTr("Snake")

    color: "#BECB02"

    Grid {
        columns: BoardModel.columnCount()
        spacing: 2

        Repeater {
            model: BoardModel.rowCount()

            Rectangle {
                width: 20
                height: 20
                color: getColor(BoardModel.data(BoardModel.index(index, index)))

                Text {
                    anchors.fill: parent
                    text: BoardModel.data(BoardModel.index(index, index))
                    font.pixelSize: 9
                }
            }
        }
    }

    function getColor(index) {
        if (index === "Empty")
            return "gold"
        if (index === BoardModel.Snake)
            return "lightsteelblue"
        if (index === BoardModel.Fruit)
            return "red"
        return "brown"
    }
}

//    WelcomeScreen {
//        id: welcomeScreen

//        width: 450
//        height: 350

//        anchors.centerIn: parent
//    }

//    Shortcut {
//        sequence: "Q"
//        context: Qt.ApplicationShortcut
//        onActivated: Qt.quit()
//    }

//    Shortcut {
//        sequence: "H"
//        context: Qt.ApplicationShortcut
//        onActivated: console.log("show highscore")
//    }
//}
