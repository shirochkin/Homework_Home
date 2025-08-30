#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), sender{new UDPworker(this)}, receiver{new UDPworker(this)}
{
    ui->setupUi(this);
    sender->InitSocket();
    receiver->InitSocket();
    sender->serviceUdpSocket->bind(QHostAddress::LocalHost);
    receiver->serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray arr;
    QDataStream out(&arr, QIODevice::WriteOnly);
    QString str = ui->textEdit->toPlainText();
    out << str;
    sender->SendDatagram(arr);
    receiver->readPendingDatagrams();
    ui->textEdit_2->append("Принято сообщение от " + receiver->sender_address + ", размер " + QString::number(receiver->message_size)
                           + " байт. Содержание: " + receiver->read);
}


