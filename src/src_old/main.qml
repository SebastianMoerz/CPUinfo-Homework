import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id : main_window
    visible: true
    width: 800
    height: 640
    color: "#68b459"
    title: qsTr("Hello World")



    MouseArea {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 1
        anchors.topMargin: 0
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Button {
        id: button
        x: 139
        y: 29
        width: 103
        height: 26
        text: qsTr("Read CPU info")
        onClicked: {
            cpureader.initializeCPUinfo_developmentOnly() //DEVELOPMENT ONLY!!
            statusinfo.text = cpureader.readCPUinfoFile("C:/Users/Sebastian/Desktop/CPUproj/test/demo/cpuinfo2.txt")

        }
    }

    Button {
        id: button_cpu1
        x: 140
        y: 66
        text: qsTr("CPU 1")
        onClicked: {
            cputext.text = cpureader.readCPUinfo(1,0)
            vendortext.text = cpureader.readCPUinfo(2,0)
            familytext.text = cpureader.readCPUinfo(3,0)
            modeltext.text = cpureader.readCPUinfo(4,0)
            modelnametext.text = cpureader.readCPUinfo(5,0)
            steppingtext.text = cpureader.readCPUinfo(6,0)
            microcodetext.text = cpureader.readCPUinfo(7,0)
            mhztext.text = cpureader.readCPUinfo(8,0)
            cachetext.text = cpureader.readCPUinfo(9,0)
            physicaltext.text = cpureader.readCPUinfo(10,0)
            siblingstext.text = cpureader.readCPUinfo(11,0)
            coreidtext.text = cpureader.readCPUinfo(12,0)
            cpucoretext.text = cpureader.readCPUinfo(13,0)
            apicidtext.text = cpureader.readCPUinfo(14,0)
            initialapicidtext.text = cpureader.readCPUinfo(15,0)
            fputext.text = cpureader.readCPUinfo(16,0)
            fpuexceptiontext.text = cpureader.readCPUinfo(17,0)
            cpuidleveltext.text = cpureader.readCPUinfo(18,0)
            wptext.text = cpureader.readCPUinfo(19,0)
            flagstext.text = cpureader.readCPUinfo(20,0)
            bogomipstext.text = cpureader.readCPUinfo(21,0)
            clflushtext.text = cpureader.readCPUinfo(22,0)
            cachealignmenttext.text = cpureader.readCPUinfo(23,0)
            addresssizetext.text = cpureader.readCPUinfo(24,0)
            powermanagementtext.text = cpureader.readCPUinfo(25,0)
        }
    }

    Button {
        id: button_cpu2
        x: 242
        y: 66
        text: qsTr("CPU 2")
        onClicked: {
            cputext.text = cpureader.readCPUinfo(1,1)
            vendortext.text = cpureader.readCPUinfo(2,1)
            familytext.text = cpureader.readCPUinfo(3,1)
            modeltext.text = cpureader.readCPUinfo(4,1)
            modelnametext.text = cpureader.readCPUinfo(5,1)
            steppingtext.text = cpureader.readCPUinfo(6,1)
            microcodetext.text = cpureader.readCPUinfo(7,1)
            mhztext.text = cpureader.readCPUinfo(8,1)
            cachetext.text = cpureader.readCPUinfo(9,1)
            physicaltext.text = cpureader.readCPUinfo(10,1)
            siblingstext.text = cpureader.readCPUinfo(11,1)
            coreidtext.text = cpureader.readCPUinfo(12,1)
            cpucoretext.text = cpureader.readCPUinfo(13,1)
            apicidtext.text = cpureader.readCPUinfo(14,1)
            initialapicidtext.text = cpureader.readCPUinfo(15,1)
            fputext.text = cpureader.readCPUinfo(16,1)
            fpuexceptiontext.text = cpureader.readCPUinfo(17,1)
            cpuidleveltext.text = cpureader.readCPUinfo(18,1)
            wptext.text = cpureader.readCPUinfo(19,1)
            flagstext.text = cpureader.readCPUinfo(20,1)
            bogomipstext.text = cpureader.readCPUinfo(21,1)
            clflushtext.text = cpureader.readCPUinfo(22,1)
            cachealignmenttext.text = cpureader.readCPUinfo(23,1)
            addresssizetext.text = cpureader.readCPUinfo(24,1)
            powermanagementtext.text = cpureader.readCPUinfo(25,1)
        }
    }

    Text {
        id: statusinfo
        x: 345
        y: 35
        text: qsTr("file not read yet. click button!")
        font.pixelSize: 12
    }

    GridLayout {
        id: gridLayout
        x: 139
        y: 103
        columnSpacing: 25
        clip: true
        rowSpacing: 5
        rows: 14
        columns: 2

        Text {
            id: label1
            text: qsTr("processor")
            font.pixelSize: 12
        }

        Text {
            id: cputext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label2
            text: qsTr("vendor id")
            font.pixelSize: 12
        }

        Text {
            id: vendortext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label3
            text: qsTr("cpu family")
            font.pixelSize: 12
        }

        Text {
            id: familytext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label4
            text: qsTr("model")
            font.pixelSize: 12
        }

        Text {
            id: modeltext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label5
            text: qsTr("model name")
            font.pixelSize: 12
        }

        Text {
            id: modelnametext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label6
            text: qsTr("stepping")
            font.pixelSize: 12
        }

        Text {
            id: steppingtext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label7
            text: qsTr("microcode")
            font.pixelSize: 12
        }

        Text {
            id: microcodetext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label8
            text: qsTr("cpu MHz")
            font.pixelSize: 12
        }

        Text {
            id: mhztext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label9
            text: qsTr("cache size")
            font.pixelSize: 12
        }


        Text {
            id: cachetext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label10
            text: qsTr("phyisical id")
            font.pixelSize: 12
        }


        Text {
            id: physicaltext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label11
            text: qsTr("siblings")
            font.pixelSize: 12
        }


        Text {
            id: siblingstext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label12
            text: qsTr("core id")
            font.pixelSize: 12
        }


        Text {
            id: coreidtext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label13
            text: qsTr("cpu cores")
            font.pixelSize: 12
        }


        Text {
            id: cpucoretext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label14
            text: qsTr("apicid")
            font.pixelSize: 12
        }


        Text {
            id: apicidtext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label15
            text: qsTr("initial apicid")
            font.pixelSize: 12
        }


        Text {
            id: initialapicidtext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label16
            text: qsTr("fpu")
            font.pixelSize: 12
        }


        Text {
            id: fputext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label17
            text: qsTr("fpu_exception")
            font.pixelSize: 12
        }


        Text {
            id: fpuexceptiontext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label18
            text: qsTr("cpuid level")
            font.pixelSize: 12
        }


        Text {
            id: cpuidleveltext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label19
            text: qsTr("wp")
            font.pixelSize: 12
        }


        Text {
            id: wptext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label20
            text: qsTr("flags")
            font.pixelSize: 12
        }


        Text {
            id: flagstext
            text: qsTr("---")
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 12
        }

        Text {
            id: label21
            text: qsTr("bogomips")
            font.pixelSize: 12
        }


        Text {
            id: bogomipstext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label22
            text: qsTr("clflush size")
            font.pixelSize: 12
        }


        Text {
            id: clflushtext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label23
            text: qsTr("cache_alignment")
            font.pixelSize: 12
        }


        Text {
            id: cachealignmenttext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label24
            text: qsTr("address sizes")
            font.pixelSize: 12
        }


        Text {
            id: addresssizetext
            text: qsTr("---")
            font.pixelSize: 12
        }

        Text {
            id: label25
            text: qsTr("power management")
            font.pixelSize: 12
        }


        Text {
            id: powermanagementtext
            text: qsTr("---")
            font.pixelSize: 12
        }

    }



































}
