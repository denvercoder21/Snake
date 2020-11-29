import QtQuick 2.12
import QtQuick.Controls 1.0

import Board.CellState 1.0
import Snake.Direction 1.0

ApplicationWindow
{
    id: mainWindow

    visible: true
    width: board.implicitWidth
    height: board.implicitHeight

    minimumWidth: width
    minimumHeight: height

    maximumWidth: width
    maximumHeight: height

    title: qsTr("Snake")

    color: "#BECB02"

    Board {
        id: board

        Keys.enabled: focus
        Keys.onLeftPressed: Snake.setDirection(Direction.Left)
        Keys.onRightPressed: Snake.setDirection(Direction.Right)
        Keys.onUpPressed: Snake.setDirection(Direction.Up)
        Keys.onDownPressed: Snake.setDirection(Direction.Down)
    }

    WelcomeScreen {
        id: welcomeScreen

        width: 450
        height: 350

        anchors.centerIn: parent

        onStartClicked: {
            states.state = "game"
            Game.start()
        }
        onHighscoreClicked: states.state = "highscore"
        onHelpClicked: states.state = "help"
        onQuitClicked: Qt.quit()
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
                PropertyChanges { target: board; focus: true }
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
