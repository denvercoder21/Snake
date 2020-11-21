import QtQuick 2.12
import QtQuick.Controls 1.0

import Board.CellState 1.0

ApplicationWindow
{
    id: mainWindow

    visible: true
    width: board.implicitWidth
    height: board.implicitHeight
    title: qsTr("Snake")

    color: "#BECB02"

    function getColor(state) {
        switch(state) {
        case CellState.Empty:
            return "#BACA00"
        case CellState.Snake:
            return "#232323"
        case CellState.Fruit:
            return "crimson"
        }
    }

    Grid {
        id: board

        columns: BoardModel.columnCount()
        spacing: 2

        Repeater {
            model: BoardModel

            delegate: Cell {
                width: 30
                color: getColor(model.display)
            }
        }
    }

    Shortcut {
        sequence: "S"
        context: Qt.ApplicationShortcut
        onActivated: Game.start()
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
