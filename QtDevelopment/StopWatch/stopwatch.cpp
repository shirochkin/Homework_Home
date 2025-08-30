#include "stopwatch.h"
#include <QtWidgets>

stopwatch::stopwatch() : timer{new QTimer()} {
};

void stopwatch::start(){
    isWorking = !isWorking;
    if(isWorking){
        timer->start(100);
    }
    else{
        timer->stop();
    }
}

QString stopwatch::cur_time(){
    ++t;
    if(t >= 36000 && t%36000 == 0){
        ++h; m = 0; s = 0; ms = 0;
    }
    else if(t >= 600 && t%600 == 0){
        ++m; s = 0; ms = 0;
    }
    else if(t >= 10 && t%10 == 0){
        ++s; ms = 0;
    }
    else if (ms >= 999){
        ms = 0;
    }
    else {
        ms += 100;
    }

    str_time = QString("%1 h : %2 min : %3 sec : %4 ms").arg(QString::number(h), QString::number(m), QString::number(s), QString::number(ms));
    return str_time;
}

QString stopwatch::circle(){
    notch_time = t;
    double diff = notch_time - last;
    str_circle = "Круг " + QString::number(N_circle) + ", Время: " + QString::number(diff/10) + " сек.";
   last = notch_time;
    ++N_circle;
    return str_circle;
}


void stopwatch::clear(){
    notch_time = 0; last = 0; ms = 0; s = 0; m = 0; h = 0; t=0;
    N_circle = 0;
    str_time = "0 h : 0 min : 0 sec : 0 ms";
}

QTimer* stopwatch::get(){
    return timer;
}

