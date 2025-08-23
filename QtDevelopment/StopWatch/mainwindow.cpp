#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), sw{new stopwatch()}
{
    ui->setupUi(this);
    QPushButton* pb{ui->pushButton};
    QPushButton* pb_2{ui->pushButton_2};
    connect(pb, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(sw->timer, &QTimer::timeout, this, &MainWindow::on_timeout);
   connect(pb_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

      sw->start();
      ui->pushButton->setText("СТОП");

}

void MainWindow::on_timeout(){
ui->label->setText(sw->cur_time());
}


void MainWindow::on_pushButton_2_clicked()
{

    sw->circle();
    ui->textBrowser->append(sw->str_circle);
}

