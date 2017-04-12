import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id : main_window
    visible: true
    width: 600
    height: 640
    color: "#33373f"
    title: qsTr("Display CPU info")


    property int currentCPU: 0
    property bool isCPUinfoLoaded: false
    property string displayCPUnumberDefault : "uninitialized"
    property int numberOfCPUs: 0

    // for development only
    // local windows path
    property string filepath: "C:/Users/Sebastian/Desktop/CPUproj/test/demo/cpuinfo3.txt"


    StatusText {
        id: displayCurrentCPU
        x: 233
        y: 71
        width: 134
        height: 25
        text: qsTr("no CPUs loaded")
    }


    StatusText{
        id: statusinfo
        x: 233
        y: 22
        width: 298
        height: 25
        text: qsTr("file not read yet. click button!")
    }


    // the List where the CPU information is displayed
    // the information of the selected CPU is displayed in a flickable list
    Rectangle {

        id : listbackground
        x: 69
        y: 108
        width: 462
        height: 514
        color: "#ffffff"
        radius: 8
        border.width: 4
        border.color: "#808080"

            Column {

                width: 462
                height: 514

                spacing: 5
                clip: true

                ListView {

                    id: liste
                    interactive: true
                    boundsBehavior: Flickable.DragOverBounds

                    width: 462
                    height: 514
                    anchors.margins: 20

                    // initialize the list without elements, since CPU info is not available at start (Button "loadCPUinfo" has to be clicked first)
                    model: 0

                    delegate: cpuinfoDelegate
                }
            }
        }

    // the main element definition of the ListElements
    // use ListEntryBox for a simple ListElement with the "label"-info on the left and the "content"-info on the right side
    // information that does not fit into the box will not be displayed, but indicated with "..."
    // use ExpandableEntry for a more complex layout, where individual items can be clicked to display more information
    Component {
        id: cpuinfoDelegate
        ListEntryBox {
        }
    }


    // the button for reading the CPU info file
    StyledButton {
        id: loadCPUinfo
        x: 75
        y: 21
        width: 103
        height: 26
        buttontext: qsTr("Read CPU info")
        onClicked: {

            // set "loaded"-flag
            isCPUinfoLoaded = true

            // display the return-status of the function cpureader.readCPUinfoFile
            statusinfo.text = cpureader.readCPUinfoFile(filepath)

            // write number of CPUs found to property
            numberOfCPUs = cpureader.getNumberOfCPUs()

            // display the number of CPUs found
            displayCurrentCPU.text = cpureader.getNumberOfCPUs()
        }
    }

    // display the information of the previous CPU
    StyledButton {
        id: decrementCurrentCPU
        x: 75
        y: 66
        buttontext: qsTr("-")
        onClicked: {

            // check if first CPU
            currentCPU = (currentCPU - 1)<1 ? 1 : (currentCPU - 1)

            // set default if /proc/cpuinfo is not read yet
            currentCPU = isCPUinfoLoaded? currentCPU : -1

            // display the number of the selected CPU
            displayCurrentCPU.text = isCPUinfoLoaded? "CPU #" + currentCPU : "no CPUs loaded"

            // reload the model to write updated CPU information to ListView
            liste.model = 0
            liste.model = cpureader.getNumberOfEntries(currentCPU)

        }
    }

    StyledButton {
        id: incrementCurrentCPU
        x: 411
        y: 66
        buttontext: qsTr("+")
        onClicked: {

            // check if last CPU
            currentCPU = (currentCPU + 1)>cpureader.getNumberOfCPUs() ? cpureader.getNumberOfCPUs() : (currentCPU + 1)

            // set default if /proc/cpuinfo is not read yet
            currentCPU = isCPUinfoLoaded? currentCPU : -1

            // display the number of the selected CPU
            displayCurrentCPU.text = isCPUinfoLoaded? "CPU #" + currentCPU : "no CPUs loaded"

            // reload the model to write updated CPU information to ListView
            liste.model = 0
            liste.model = cpureader.getNumberOfEntries(currentCPU)
        }
    }

}
