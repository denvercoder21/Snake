import QtQuick 2.12
import QtQuick.Controls 1.0
import Board.CellState 1.0

ApplicationWindow
{
    id: mainWindow

    visible: true
    width: 640
    height: 480
    title: qsTr("Snake")

    color: "#BECB02"

    function getColor(state) {
        console.log(state)
        switch(state) {
        case CellState.Empty:
            return "gray"
        case CellState.Snake:
            return "black"
        case CellState.Fruit:
            return "orange"
        }
    }

    Grid {
        columns: BoardModel.columnCount()
        spacing: 2

        Repeater {
            model: BoardModel

            delegate: Rectangle {
                width: 30
                height: width
                color: getColor(model.display)
            }
        }
    }
}



//    Shortcut {
//        sequence: "S"
//        context: Qt.ApplicationShortcut
//        onActivated: Game.start()
//    }

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
