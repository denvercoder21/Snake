import QtQuick 2.0

import Board.CellState 1.0

Grid {
    id: root

    columns: BoardModel.columnCount()
    spacing: 2

    Repeater {
        model: BoardModel

        delegate: Cell {
            width: 30
            color: getColor(model.display)
        }
    }

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
}
