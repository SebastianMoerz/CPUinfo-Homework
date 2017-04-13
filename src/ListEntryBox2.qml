import QtQuick 2.0

Rectangle {
    width: 300
    height: 40

    property alias labeltext: labelbox.text
    property alias contentext: contentbox.text
    property alias fulltext: contentbox.fulltext
    property alias abreviated: contentbox.abreviatedtext

    ColorBox{
        id: labelbox
        x: 8
        y: 4

        text : cpureader.getLabelText(index,currentCPU-1);
    }

    ColorBox{
        id: contentbox
        x: 134
        y: 4
        width: 161
        height: 32

        property string  fulltext: cpureader.getContentText(index,currentCPU-1)
        property string  abreviatedtext: "..."

        // ToDo
        text: fulltext.length<30 ? fulltext : abreviatedtext

    }
}
