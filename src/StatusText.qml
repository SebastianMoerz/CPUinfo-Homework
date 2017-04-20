import QtQuick 2.0

Rectangle {

    property alias text: statusinfo.text

    height: 25
    width: 200


    color : "#c0b16d"

    Text {
        id: statusinfo
        x: 8
        y: 6
        text: qsTr("file not read yet. click button!")
        font.pixelSize: 12
    }

}
