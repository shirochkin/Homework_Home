#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void count_h();
    void count_m();
    void count_s();
    void count_ms();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_timeout();
    void show_time();

   void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    stopwatch* sw;
    QTimer* tm;
    QTime* pas_time;
    int t, h, m, s, ms;
    QString str_time;
    bool exp_h, exp_m, exp_s;
};
#endif // MAINWINDOW_H
