import QtQuick 2.3
import "chat.js" as Chat;


//Item
//{

//}


Item {
    id: item
    width: 200; height: 200

    MouseArea
    {
        id: mouseArea
        anchors.fill: parent
    }

    Component.onCompleted:
    {
        mouseArea.clicked.connect(chat.addEventListener)
    }
}
