import QtQuick 2.6
import QtQuick.Window 2.2
import Snake.Direction 1.0

Window {
  visible: true

  color: "#BECB02"

  minimumWidth: game_board.width
  minimumHeight: game_board.height

  Item {
    anchors.fill: parent

    focus: true

    Keys.onRightPressed: snake.set_direction(Direction.Right)
    Keys.onLeftPressed: snake.set_direction(Direction.Left)
    Keys.onUpPressed: snake.set_direction(Direction.Up)
    Keys.onDownPressed: snake.set_direction(Direction.Down)

    Board {
      id: game_board
    }
  }
}
