#include "stopwatch.h"
#include <QtWidgets>
#include <windows.h>

stopwatch::stopwatch() : timer{new QTimer()}, t{0}, h{0}, m{0}, s{0}, ms{0},
    last{0}, notch_time{0} {
};

void stopwatch::start(){
    timer->start(100);
}

/*void stopwatch::elapsed(){
    int el_ms{0}, el_s{0}, el_m{0}, el_h{0};
    while(true){
    el_ms = timer->interval() - timer->remainingTime();

    if(el_ms >= 3600000){
        el_h = el_ms/3600000;
        el_ms -= el_h*3600000;
    }

    if(el_ms >= 60000){
        el_m = el_ms/60000;
        el_ms -= el_m*60000;
    }

    if(el_ms >= 1000){
        el_s = el_ms/1000;
        el_ms -= el_s*1000;
    }

    elapsed_time->setHMS(QTime::currentTime().hour(), QTime::currentTime().minute(), QTime::currentTime().second(), QTime::currentTime().msec());
    Sleep(100);
    }
}*/

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

void stopwatch::stop(){
    timer->stop();
}

void stopwatch::circle(){
    notch_time = t;
    str_circle = QString::number(notch_time - last);
   last = notch_time;
}


void stopwatch::clear(){
    //cur_time->setHMS(0, 0, 0, 0);
}

