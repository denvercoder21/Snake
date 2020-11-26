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

    Board {
        id: board
    }

    WelcomeScreen {
        id: welcomeScreen

        width: 450
        height: 350

        anchors.centerIn: parent

        onStartClicked: states.state = "game"
        onHighscoreClicked: states.state = "highscore"
        onHelpClicked: states.state = "help"
    }

    GameOverScreen {
        id: gameOverScreen

        width: 450
        height: 350

        anchors.centerIn: parent

        onStartmenuClicked: states.state = "welcome"
    }

    HighscoreScreen {
        id: highscoreScreen

        width: 450
        height: 350

        anchors.centerIn: parent

        onBackClicked: states.state = "welcome"
    }

    HelpScreen {
        id: helpScreen

        width: 450
        height: 350

        anchors.centerIn: parent

        onBackClicked: states.state = "welcome"
    }

    Item {
        id: states

        state: "welcome"

        states: [
            State {
                name: "welcome"
                PropertyChanges { target: welcomeScreen; visible: true }
            },
            State {
                name: "game"
            },
            State {
                name: "gameOver"
                PropertyChanges { target: gameOverScreen; visible: true }
            },
            State {
                name: "highscore"
                PropertyChanges { target: highscoreScreen; visible: true }
            },
            State {
                name: "help"
                PropertyChanges { target: helpScreen; visible: true }
            }
        ]

        Connections {
            target: Game
            function onGameOver() { states.state = "gameOver" }
        }
    }
}
