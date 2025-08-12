#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QtWidgets>

class stopwatch
{
public:
    QTime* pas_time;
    QVector<int> circles;
    int t, h, m, s, ms, last, c_h, c_m, c_s, c_ms, c, c_t;
    bool changed;
    QString str_circle;
    QString str_time;
    QTime* start_time;
    QTime* nick_time;
    QTime* circle_time;

    QTimer* timer;
    stopwatch();
    void start();
    void stop();
    QString cur_time();
    void circle();
    int count_circles();
    void new_last();
    void clear();
    void show_time();
    void elapsed();
    QString toShow();

signals:
    void time_started();
    void circle_finished();
    void time_finished();
};

#endif // STOPWATCH_H
