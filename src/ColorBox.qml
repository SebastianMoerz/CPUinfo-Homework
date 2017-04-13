import QtQuick 2.0

Rectangle{

    id: rect
    width: 120
    height: 32

    border.color: "#5984bd"
    border.width: 4
    radius : 8

    property alias text: boxtext.text

    Text {
        id: boxtext
        anchors.centerIn: parent
        color: "#000000"
        text: "placeholder"
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 0
        wrapMode: Text.WordWrap
        clip : true
    }
}
