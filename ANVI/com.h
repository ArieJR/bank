#ifndef COM_H
#define COM_H

#include <QQuickItem>

class com : public QQuickItem//, private QQmlComponent::com
{
    Q_OBJECT
public:
    explicit com();
    void init();
private:

};

#endif // COM_H
