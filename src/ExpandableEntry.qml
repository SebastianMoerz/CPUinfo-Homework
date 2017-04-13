import QtQuick 2.0

Rectangle {
    // default state
    id : expandableEntry
    width: 300
    height: 40

    property int expandedHeight : 200
    property int expandedWidth  : 300
    property int closeButtonWidth  : 25
    property int maxTextLength  : 30

    property alias labeltext: labelbox.text
    property alias contentext: contentbox.text
    property alias fulltext: contentbox.fulltext
    property alias abreviated: contentbox.abreviatedtext

    // click mouse area to expand item
    MouseArea {
        id: mouseArea
         anchors.fill: parent
         onClicked: parent.state = "expanded"
    }

    // the box containing the label
    ColorBox{
        id: labelbox
        y: 4

        anchors.left: parent.left

        text : cpureader.getLabelText(index,currentCPU-1)
        anchors.leftMargin: 8
    }

    // the box containing the content
    ColorBox{
        id: contentbox

        anchors.right: parent.right

        property string  fulltext: cpureader.getContentText(index,currentCPU-1)
        property string  abreviatedtext: "..."

        x: 172
        y: 4

        // if not expanded, check whether text fits in box
        // use abreviated text if not
        text: fulltext.length<maxTextLength ? fulltext : abreviatedtext
        anchors.rightMargin: 8

    }

    // button to close the expanded view
    ColorBox {
        id: closeButton
        opacity: 0
        anchors.right: parent.right
        anchors.top: parent.top

        width: 30
        height: 30
        border.color: "#b0c4de"

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            onClicked: expandableEntry.state = ""
        }
    }

    // define the expanded state
    states: [
        State {
        name: "expanded"
        PropertyChanges { target: closeButton; x: 262; height: 32; radius: 2; text: "X"; anchors.rightMargin: 8; anchors.topMargin: 0; opacity: 1 }
        PropertyChanges { target: expandableEntry; height: expandedHeight; width : expandedWidth; anchors.verticalCenter: liste.verticalCenter}
        PropertyChanges { target: labelbox; anchors.top: parent.top ; width : expandedWidth - 35 ; height: 32; anchors.leftMargin: 0;anchors.topMargin: 0}
        PropertyChanges { target: contentbox; anchors.top : labelbox.bottom; anchors.left : parent.left; width : expandedWidth; height : 154; text : fulltext;}

        PropertyChanges {
            target: mouseArea1
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
        }
        }
    ]

}
