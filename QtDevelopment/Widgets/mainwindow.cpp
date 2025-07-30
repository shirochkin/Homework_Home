#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton->setObjectName("Button_1");
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setObjectName("Button_2");
    ui->comboBox->addItem("Item_1");
    ui->comboBox->addItem("Item_2");
    ui->comboBox->addItem("Item_3");
    ui->comboBox->addItem("Item_4");
    ui->comboBox->addItem("Item_5");
    ui->pushButton->setText("Click here!");
    ui->pushButton = qobject_cast<QPushButton*>(ui->pushButton);
    ui->progressBar->setMinimum(100);
    ui->progressBar->setMaximum(500);
    ui->progressBar->setValue(140);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int k = ui-> progressBar->value();
    if(k <= 460){
        ui->progressBar->setValue(k + 40);
    }

    else {
        ui->progressBar->setValue(100);
    }

}

