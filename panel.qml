import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15 as Controls
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.13 as Kirigami

Window {
  //設定系は先に済ませておきます
  property bool isvertical: false
  property bool istop: false
  property bool isright: false
  property int settingwidth: 20
  property real settingopacity: 0.7

  id: panel
  visible: true
  width: isvertical == false ? Screen.width : settingwidth
  height: isvertical == false ? settingwidth : Screen.height
  x: isright == true ? Screen.width - width : 0
  y: istop == true ? 0 : Screen.height - height
  color: Qt.rgba(Kirigami.Theme.backgroundColor.r * settingopacity,
                 Kirigami.Theme.backgroundColor.g * settingopacity,
                 Kirigami.Theme.backgroundColor.b * settingopacity,
                 settingopacity)
}
