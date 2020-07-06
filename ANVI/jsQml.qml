import QtQuick 2.0
import "jsFile.js" as MyScript

Item {
    width: 100; height: 100

    Item {
        function myQmlFunction(msg: string) : string
        {
            MyScript.showCalculations(10)
            console.log("Call factorial() from QML:",
            MyScript.factorial(10))
        }
    }
}
