#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QtWidgets>

class stopwatch
{

    int t{0}, notch_time{0}, h{0}, m{0}, s{0}, ms{0}, last{0}, N_circle{1};
    QString str_circle;
    QString str_time;
    QTimer* timer;
    public:
    QTimer* get();
    stopwatch();
    void start();
    QString circle();
    QString cur_time();
    void clear();
    bool isWorking{false};
};

#endif // STOPWATCH_H
