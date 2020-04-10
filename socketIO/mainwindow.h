#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public Q_SLOTS:
    void SendBtnClicked();
    void TypingChanged();
    void LoginClicked();
    void OnMessageReturn();

Q_SIGNALS:
    void RequestAddListItem(QListWidgetItem *item);
private Q_SLOTS:
    void AddListItem(QListWidgetItem *item);


private:
    void OnNewMessage(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnUserJoined(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnUserLeft(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnTyping(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnStopTyping(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnLogin(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
    void OnConnected();
    void OnClosed(client::close_reason const& reason);
    void OnFailed();

    std::unique_ptr<client> _io;

};
#endif // MAINWINDOW_H
