#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345


class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket();
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data);
    QString sender_address;
    int message_size;
    bool text_is_sent{0}, time_is_sent{0};


public slots:
    void readPendingDatagrams();

public:
    QUdpSocket* serviceUdpSocket;
    QString read;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendTextToGUI(QString str);

};

#endif // UDPWORKER_H
