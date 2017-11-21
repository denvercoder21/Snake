import QtQuick 2.0

Rectangle {
  id: cell
  property int x_cord: 0
  property int y_cord: 0
  property int size: 10

  width: size
  height: size

  color: getCorrectColor()

  Column {
    Repeater {
      model: 3

      Row {
        property int x_pos: index

        Repeater {
          model: 3

          Rectangle {
            id: small_cell

            width: cell.size / 3
            height: cell.size / 3

            color: "transparent"

            border.color: "#C1CF02"
            border.width: 0.5
          }
        }
      }
    }
  }

  Connections {
    target: board
    onDataChanged: {
      cell.color = cell.getCorrectColor()
    }
  }

  function getCorrectColor() {
    switch(board.data(board.index(cell.x_cord, cell.y_cord)) + 0) {
    case 0 :
      return "transparent"
    case 1 :
      return "black"
    case 2 :
      return "orangered"
    default:
      return "yellow"
    }
  }
}


