#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), worker{new UDPworker(this)}
{
    ui->setupUi(this);
    worker->InitSocket();
    connect(worker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    connect(worker, &UDPworker::sig_sendTextToGUI, this, &MainWindow::DisplayText);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        worker->SendDatagram(dataToSend);
        worker->time_is_sent = 1;
    });


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete worker;
}

void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}

void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->textEdit_2->clear();
    }

    ui->textEdit_2->append("Текущее время: " + data.toString() + ". "
                                                                "Принято пакетов " + QString::number(counterPck));


}

void MainWindow::DisplayText(QString data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->textEdit_2->clear();
    }

    ui->textEdit_2->append("Принято сообщение от " + worker->sender_address + ", размер " + QString::number(worker->message_size)
                           + " байт. Содержание: " + data + ". Принято пакетов " + QString::number(counterPck));


}

void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}

void MainWindow::on_pb_send_mes_clicked()
{
    QByteArray arr;
    QDataStream out(&arr, QIODevice::WriteOnly);
    QString str = ui->textEdit->toPlainText();
    out << str;
    worker->SendDatagram(arr);
    worker->text_is_sent = 1;
}


