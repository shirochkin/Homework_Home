#include "stopwatch.h"
#include <QtWidgets>
#include <windows.h>

stopwatch::stopwatch() : timer{new QTimer()}, start_time{new QTime(0, 0, 0, 0)}, pas_time{new QTime(0, 0, 0, 0)}, t{0}, h{0}, m{0}, s{0}, ms{0},
    last{}, c_h{0}, c_m{0}, c_s{0}, c_ms{0}, c{0}, c_t{0}, changed{0} {
    //timer->setInterval(3600000);
};

void stopwatch::start(){
   // *start_time = start_time->currentTime();
    timer->start(100);
    //elapsed();
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
    //c_t = t;
    //c = c_t - last;

    //c_h = j/36000;
   // c_m = (j - c_h * 36000)/600;
    //c_s = (j - c_h * 36000 - c_m * 600) / 10;
    //c_ms = int(j - c_h * 36000 - c_m * 600 - c_s * 10) * 100;
    str_circle = QString::number(t - last);
        //QString::number(c_h) + "h : " + QString::number(c_m) + "m : " + QString::number(c_s) + "s : " + QString::number(c_ms) + "ms : ";
        //QString("%1 h : %2 min : %3 sec : %4 ms\n").arg(QString::number(c_h), QString::number(c_m), QString::number(c_s), QString::number(c_ms));
   last = str_circle.toInt();
}

void stopwatch::new_last(){
    Sleep(1000);
    last += c;
}


void stopwatch::clear(){
    //cur_time->setHMS(0, 0, 0, 0);
}

