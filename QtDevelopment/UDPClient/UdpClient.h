#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>

class UdpClient : public QObject {
    Q_OBJECT
public:
    QUdpSocket* udp_socket;

public:
    UdpClient(QObject* parent = nullptr);

private slots:
    void slotProcessDatagrams();
signals:
    void sig();

};

#endif // UDPCLIENT_H
