#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    using std::placeholders::_4;
    socket::ptr sock = _io->socket();
    sock->on("new message",std::bind(&MainWindow::OnNewMessage,this,_1,_2,_3,_4));
    sock->on("user joined",std::bind(&MainWindow::OnUserJoined,this,_1,_2,_3,_4));
    sock->on("user left",std::bind(&MainWindow::OnUserLeft,this,_1,_2,_3,_4));
    sock->on("typing",std::bind(&MainWindow::OnTyping,this,_1,_2,_3,_4));
    sock->on("stop typing",std::bind(&MainWindow::OnStopTyping,this,_1,_2,_3,_4));
    sock->on("login",std::bind(&MainWindow::OnLogin,this,_1,_2,_3,_4));
    //default socket opened, also we have "set_open_listener" for monitoring physical connection opened.
    _io->set_socket_open_listener(std::bind(&MainWindow::OnConnected,this,std::placeholders::_1));
    //physical connection closed or drop.
    _io->set_close_listener(std::bind(&MainWindow::OnClosed,this,_1));
    //physical connection fail to establish.
    _io->set_fail_listener(std::bind(&MainWindow::OnFailed,this));
    connect(this,SIGNAL(RequestAddListItem(QListWidgetItem*)),this,SLOT(AddListItem(QListWidgetItem*)));

}

MainWindow::~MainWindow()
{
    _io->socket()->off_all();
    _io->socket()->off_error();
    delete ui;
}

void MainWindow::AddListItem(QListWidgetItem* item)
{
    this->findChild<QListWidget*>("listView")->addItem(item);
}

void MainWindow::OnConnected()
{
    QByteArray bytes = m_name.toUtf8();
    std::string nickName(bytes.data(),bytes.length());
    _io->socket()->emit("add user", nickName);
}

void MainWindow::OnClosed(client::close_reason const& reason)
{
    //restore UI to pre-login state
}

void MainWindow::OnFailed()
{
    //restore UI to pre-login state
}

void MainWindow::OnNewMessage(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp)
{
    if(data->get_flag() == message::flag_object)
    {
        std::string msg = data->get_map()["message"]->get_string();
        std::string name = data->get_map()["username"]->get_string();
        QString label = QString::fromUtf8(name.data(),name.length());
        label.append(':');
        label.append(QString::fromUtf8(msg.data(),msg.length()));
        QListWidgetItem *item= new QListWidgetItem(label);
        //emit RequestAddListItem signal
        //so that 'AddListItem' will be executed in UI thread.
        Q_EMIT RequestAddListItem(item);
    }
}

void MainWindow::SendBtnClicked()
{
    QLineEdit* messageEdit = this->findChild<QLineEdit*>("messageEdit");
    QString text = messageEdit->text();
    if(text.length()>0)
    {
        QByteArray bytes = text.toUtf8();
        std::string msg(bytes.data(),bytes.length());
        _io->socket()->emit("new message",msg);//emit new message
        text.append(":You");
        QListWidgetItem *item = new QListWidgetItem(text);
        item->setTextAlignment(Qt::AlignRight);
        Q_EMIT RequestAddListItem(item);
        messageEdit->clear();
    }
}
