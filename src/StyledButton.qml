import QtQuick 2.0
import QtQuick.Controls 1.2


Button {

    property alias buttontext : text1.text

    width: 120
    height: 32



    ColorBox {
        id : box

      text : ""
      gradient: Gradient {
          GradientStop {
              position: 0
              color: "#ffffff"
          }

          GradientStop {
              position: 0.656
              color: "#000000"
          }

      }
      border.color: "#02122b"



      Text {
          id: text1
          width: 120
          height: 32

          verticalAlignment: Text.AlignVCenter
          font.bold: true
          horizontalAlignment: Text.AlignHCenter
          color: "#c7cfd8"
          font.pixelSize: 12
      }



  }

}


