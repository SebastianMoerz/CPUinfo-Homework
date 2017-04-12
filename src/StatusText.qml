import QtQuick 2.0

Rectangle {

    property alias text: statusinfo.text

    height: 25
    width: 200


    color : "#b0c4de"

    Text {
        id: statusinfo
        x: 8
        y: 6
        text: qsTr("file not read yet. click button!")
        font.pixelSize: 12
    }

}
