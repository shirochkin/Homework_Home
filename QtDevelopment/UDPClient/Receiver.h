#ifndef RECEIVER_H
#define RECEIVER_H
#include <Qwidget>
#include "udpworker.h"

class Receiver : public QWidget{
    UDPworker r;
public:
   void receive();
};

#endif // RECEIVER_H
