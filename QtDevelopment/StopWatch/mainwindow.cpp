#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), sw{new stopwatch()}
{
    ui->setupUi(this);
    ui->label->setText("0 h : 0 min : 0 sec : 0 ms");
    ui->circle_button->setEnabled(false);
    connect(sw->get(), &QTimer::timeout, this, &MainWindow::on_timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sw;
}


void MainWindow::on_start_button_clicked()
{

      sw->start();
    if(sw->isWorking){
      ui->start_button->setText("СТОП");
        ui->circle_button->setEnabled(true);
    }
    else{
       ui->start_button->setText("СТАРТ");
        ui->circle_button->setEnabled(false);
    }

}

void MainWindow::on_timeout(){
ui->label->setText(sw->cur_time());
}


void MainWindow::on_circle_button_clicked()
{
    ui->textBrowser->append(sw->circle());
}


void MainWindow::on_clear_button_clicked()
{
    sw->clear();
    ui->label->setText("0 h : 0 min : 0 sec : 0 ms");
    ui->textBrowser->clear();
}

