#include "UdpClient.h"
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>

UdpClient::UdpClient(QObject* parent) : QObject(parent) {
    udp_socket = new QUdpSocket();
    udp_socket->bind(12345);
    connect(udp_socket, &QUdpSocket::readyRead, this, &UdpClient::slotProcessDatagrams);
}

void UdpClient::slotProcessDatagrams(){
    QByteArray baDatagram;
    do{
        baDatagram.resize(udp_socket->pendingDatagramSize());
        udp_socket->readDatagram(baDatagram.data(), baDatagram.size());
    } while(udp_socket->hasPendingDatagrams());

}
