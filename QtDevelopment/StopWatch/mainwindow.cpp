#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), sw{new stopwatch()}, tm {new QTimer()}, pas_time{new QTime(0, 0, 0, 0)}, t{0}, h{0}, m{0}, s{0}, ms{0}, str_time{}, exp_h{0}, exp_m{0}, exp_s{0}
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

void MainWindow::show_time()
{
    while(true){
        Sleep(100);
    }

}

void MainWindow::count_h() {
    while(true){
        Sleep(3595000);
        while(exp_h == 0){
            if(t - 36000*h >= 36000){
                exp_h = 1;
                ++h;
            }
        }
        exp_h = 0;
    }
}

void MainWindow::count_m() {
    while(true){
        Sleep(55000);
        while(exp_m == 0){
            if(t - 600*m >= 600 && m < 59){
                exp_m = 1;
                ++m;
            }
        }
        exp_m = 0;
    }
}

void MainWindow::count_s() {
    while(true){
        Sleep(800);
        while(exp_s == 0){
            if(t - 10*s >= 10 && s < 59){
                exp_s = 1;
                ++s;
            }
        }
        exp_s = 0;
    }
}

void MainWindow::count_ms() {
    while(true){
        Sleep(100);
        if(t >= 10) {
            ms = (t%10)*100;
        }
        else {
            ms = t*100;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
  // emit sw->time_started();
    //ui->label->setText("56778");
  //sw->start();
  //if(sw->timer->isActive() == false){
      sw->start();
      ui->pushButton->setText("СТОП");
 // }

 // else if(sw->timer->isActive() == true){
   //   sw->stop();
     // ui->pushButton->setText("СТАРТ");
  //}

 // count_ms(); count_s(); count_m(); count_h();
 // show_time();
//QThread::msleep(1000);
//QThread::msleep(1000);
//ui->label->setText(sw->toShow());
//QThread::msleep(1000);

 /*do {
    ui->label->setText(sw->toShow());
    ui->label->update();
    QThread::msleep(100);
  } while(true);*/
}

void MainWindow::on_timeout(){

    ui->label->setText(sw->cur_time());
}


void MainWindow::on_pushButton_2_clicked()
{
    sw->circle();
    ui->textBrowser->setText(sw->str_circle);
    //sw->new_last();
}

