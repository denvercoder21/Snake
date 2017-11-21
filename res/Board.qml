import QtQuick 2.0

Column {
  Repeater {
    model: board.columnCount()

    Row {
      property int y_pos: index

      Repeater {
        id: repeatr
        model: board.rowCount()

        Cell {
          x_cord: index
          y_cord: y_pos

          size: 21
        }
      } //Repeater
    } //Row
  } //Repeater
} //Column
