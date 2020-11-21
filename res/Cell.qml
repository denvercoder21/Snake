import QtQuick 2.0

Grid {
    id: root

    property color color

    height: width
    spacing: 1
    columns: 3

    Repeater {
        anchors.fill: parent
        model: 9
        delegate: Rectangle {
            width: (root.width - (2 * root.spacing)) / root.columns
            height: width
            color: root.color
        }
    }
}
