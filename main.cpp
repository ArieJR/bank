#include "login.h"
//#include "data.h"
#include <QApplication>
//#include "NodeImport.qml"

//! [0]
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    Login start;
    start.show();
    return app.exec();
}
