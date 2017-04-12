import QtQuick 2.0
import QtQuick.Controls 1.4


Button {

    property alias buttontext : text1.text

    ColorBox {
      id : box
      gradient: Gradient {
          GradientStop {
              position: 0
              color: "#636bd3"
          }

          GradientStop {
              position: 0.85
              color: "#0a0c27"
          }
      }

      Text {
          id: text1
          width: 120
          height: 32

          text: qsTr("Text")
          verticalAlignment: Text.AlignVCenter
          font.bold: true
          horizontalAlignment: Text.AlignHCenter
          color: "#b0c4de"
          font.pixelSize: 12
      }



  }

}


