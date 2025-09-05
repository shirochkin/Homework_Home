#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "udpworker.h"

#define TIMER_DELAY 1000

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
    ~MainWindow();

private slots:
    void on_pb_send_mes_clicked();
    void on_pb_start_clicked();
    void DisplayTime(QDateTime data);
    void DisplayText(QString data);
    void on_pb_stop_clicked();


private:
    Ui::MainWindow *ui;
    UDPworker* worker;
    uint32_t counterPck = 0;
    QTimer* timer;
};
#endif // MAINWINDOW_H
