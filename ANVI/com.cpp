#include "com.h"
#include <QQmlComponent>
//#include <EngineQQml>
#include <QQmlContext>
com::com()
{


}
void com::init()
  {
      //QQmlEngine *engine = qmlEngine(this);
      // Or:
      QQmlEngine *engine = qmlContext(this)->engine();
      QQmlComponent component(engine, QUrl::fromLocalFile("jsQml.qml"));
      QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
      childItem->setParentItem(this);
  }
