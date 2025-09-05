#include "udpworker.h"


UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);
}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */

void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();
    sender_address = datagram.senderAddress().toString();
    message_size = datagram.data().size();

    QDataStream inStr(&data, QIODevice::ReadOnly);
    if(time_is_sent == 1){
        QDateTime dateTime;
        inStr >> dateTime;
        emit sig_sendTimeToGUI(dateTime);
        time_is_sent = 0;
    }

    else if (text_is_sent == 1){
        QString str;
        inStr >> str;
        emit sig_sendTextToGUI(str);
        time_is_sent = 0;
}
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( )
{

    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}

