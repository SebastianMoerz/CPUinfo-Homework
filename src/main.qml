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
    property string filepath: "./demo/cpuinfo3.txt"
    // property string filepath: "./demo/Test01 - empty file.txt"                  // BUTTON + returns -1
    // property string filepath: "./demo/Test02 - additional separtor.txt"
    // property string filepath: "./demo/Test03 - changed separator char.txt"      // ONLY DISPLAYS ONE CPU
    // property string filepath: "./demo/Test04 - header.txt"


    StatusText {
        id: displayCurrentCPU
        x: 206
        y: 70
        width: 134
        height: 25
        text: qsTr("no CPUs loaded")
    }


    StatusText{
        id: statusinfo
        x: 206
        y: 25
        width: 298
        height: 25
        text: qsTr("file not read yet. click button!")
    }


    // the List where the CPU information is displayed
    // the information of the selected CPU is displayed in a flickable list
    Rectangle {

        id : listbackground
        x: 105
        y: 110
        width: 373
        height: 514
        color: "#ffffff"
        radius: 8
        border.width: 4
        border.color: "#808080"

            Column {

                width: 373
                height: 514

                spacing: 5
                clip: true

                ListView {

                    id: liste
                    anchors.rightMargin: 45
                    anchors.leftMargin: 45
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                    anchors.fill: parent
                    interactive: true
                    boundsBehavior: Flickable.DragOverBounds


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
        //ListEntryBox {
        ExpandableEntry {
        }
    }


    // the button for reading the CPU info file
    StyledButton {
        id: loadCPUinfo
        x: 75
        y: 21       
        buttontext: qsTr("Read CPU info")
        onClicked: {

            // set "loaded"-flag
            isCPUinfoLoaded = true

            // display the return-status of the function cpureader.readCPUinfoFile
            statusinfo.text = cpureader.readCPUinfoFile(filepath)

            // write number of CPUs found to property
            numberOfCPUs = cpureader.getNumberOfCPUs()

            // prompt user
            displayCurrentCPU.text = "    <- select CPU ->"


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

            // reload the model to write updated CPU information to ListView
            liste.model = 0
            liste.model = cpureader.getNumberOfEntries(currentCPU-1)

            // display the number of the selected CPU
            displayCurrentCPU.text = isCPUinfoLoaded? "CPU #" + currentCPU : "no CPUs loaded"

        }
    }

    StyledButton {
        id: incrementCurrentCPU
        x: 384
        y: 66
        buttontext: qsTr("+")
        onClicked: {

            // check if last CPU
            currentCPU = (currentCPU + 1)>=cpureader.getNumberOfCPUs() ? cpureader.getNumberOfCPUs() : (currentCPU + 1)

            // set default if /proc/cpuinfo is not read yet
            currentCPU = isCPUinfoLoaded? currentCPU : -1

            // reload the model to write updated CPU information to ListView
            liste.model = 0
            liste.model = cpureader.getNumberOfEntries(currentCPU-1)

            // display the number of the selected CPU
            displayCurrentCPU.text = isCPUinfoLoaded? "CPU #" + currentCPU : "no CPUs loaded"


        }
    }

}
