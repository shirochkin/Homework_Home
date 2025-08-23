#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QtWidgets>

class stopwatch
{
public:
    int t, notch_time, h, m, s, ms, last;
    QString str_circle;
    QString str_time;
    QTimer* timer;
    stopwatch();
    void start();
    void stop();
    void circle();
    QString cur_time();
    void clear();
    void elapsed();
};

#endif // STOPWATCH_H
