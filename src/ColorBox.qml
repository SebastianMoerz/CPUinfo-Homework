import QtQuick 2.0

Rectangle{

    id: rect
    width: 120
    height: 32

    border.width: 2
    radius : 8
    gradient: Gradient {
        GradientStop {
            position: 0.099
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#caaf28"
        }
    }
    border.color: "#9a7e1c"

    property alias text: boxtext.text

    Text {
        id: boxtext
        //width: 109
        //height: 14
        anchors.fill: parent
        //anchors.centerIn: parent
        color: "#000000"
        text: "placeholder"
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        textFormat: Text.PlainText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        //anchors.verticalCenterOffset: 1
        //anchors.horizontalCenterOffset: 1
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        clip : true
    }
}


