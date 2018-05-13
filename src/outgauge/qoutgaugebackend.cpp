#include "qoutgaugebackend_p.h"
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkDatagram>
#include <QtCore/QDataStream>
#include <QtCore/qendian.h>
#include "qoutgauge.h"

struct OutGaugePack
{
    quint32     Time;       // time in milliseconds (to check order)
    QByteArray  Car;        // Car name. (4 chars)
    quint16     Flags;
    quint8      Gear;       // Reverse:0, Neutral:1, First:2...
    quint8      PLID;       // Unique ID of viewed player (0 = none)
    float       Speed;      // M/S.
    float       RPM;        // RPM.
    float       Turbo;      // BAR.
    float       EngTemp;    // C.
    float       Fuel;       // 0 - 1
    float       OilPressure;// BAR.
    float       OilTemp;    // C.
    quint32     DashLights; // Dash Lights Available
    quint32     ShowLights; // Dash lights currently switched on.
    float       Throttle;   // 0 - 1
    float       Brake;      // 0 - 1
    float       Clutch;     // 0 - 1
    QByteArray  Display1;   // Usually Fuel. (16 chars)
    QByteArray  Display2;   // Usually Settings (16 chars)
    qint32      ID;         // optional - only if OutGauge ID is specified
};


QOutGaugeBackend::QOutGaugeBackend(QObject *parent)
    : QObject(parent)
{
    m_outGaugeSocket = new QUdpSocket(this);
    m_outGaugeSocket->bind(QHostAddress::Any, 4444, QAbstractSocket::DefaultForPlatform);

    connect(m_outGaugeSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void QOutGaugeBackend::registerGauge(QOutGauge *gauge)
{
    if (!m_gauges.contains(gauge))
        m_gauges.append(gauge);
}

void QOutGaugeBackend::deregisterGauge(QOutGauge *gauge)
{
    m_gauges.removeOne(gauge);
}

namespace  {

float readFloat(const char* floatData)
{
    float retVal;
    char *returnFloat = ( char* ) & retVal;

    // swap the bytes into a temporary buffer
    returnFloat[0] = floatData[0];
    returnFloat[1] = floatData[1];
    returnFloat[2] = floatData[2];
    returnFloat[3] = floatData[3];

    return retVal;
}

}

void QOutGaugeBackend::processPendingDatagrams()
{
    QNetworkDatagram datagram = m_outGaugeSocket->receiveDatagram();
    if (datagram.data().size() != sizeof(OutGaugePack)) {
        return;
    }

    OutGaugePack packet;
    const char* data = datagram.data().constData();
    int seek = 0;
    packet.Time = static_cast<quint32>(data[seek]);
    seek += sizeof(quint32);
    packet.Car = QByteArray(&data[seek], 4);
    seek += sizeof(char) * 4;
    packet.Flags = static_cast<quint16>(data[seek]);
    seek += sizeof(quint16);
    packet.Gear = static_cast<quint8>(data[seek]);
    seek += sizeof(quint8);
    packet.PLID = static_cast<quint8>(data[seek]);
    seek += sizeof(quint8);
    packet.Speed = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.RPM = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.Turbo = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.EngTemp = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.Fuel = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.OilPressure = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.OilTemp = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.DashLights = static_cast<quint32>(data[seek]);
    seek += sizeof(quint32);
    packet.ShowLights = static_cast<quint32>(data[seek]);
    seek += sizeof(quint32);
    packet.Throttle = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.Brake = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.Clutch = readFloat(&data[seek]);
    seek += sizeof(float);
    packet.Display1 = QByteArray(&data[seek], 16);
    seek += sizeof(char) * 16;
    packet.Display2 = QByteArray(&data[seek], 16);
    seek += sizeof(char) * 16;
    packet.ID = static_cast<quint32>(data[seek]);
    seek += sizeof(quint32);

    for (QOutGauge *gauge : m_gauges) {
        gauge->setGear(packet.Gear);
        gauge->setSpeed(packet.Speed);
        gauge->setRpm(packet.RPM);
        gauge->setTurbo(packet.Turbo);
        gauge->setEngineTemp(packet.EngTemp);
        gauge->setFuel(packet.Fuel);
        gauge->setOilPressure(packet.OilPressure);
        gauge->setOilTemp(packet.OilTemp);
        gauge->setThrottle(packet.Throttle);
        gauge->setBrake(packet.Brake);
        gauge->setClutch(packet.Clutch);
        gauge->processFlags(packet.Flags);
        gauge->processLights(packet.ShowLights);
    }
#if 0
    qDebug() << "Time: " << packet.Time;
    qDebug() << "Car: " << packet.Car;
    qDebug() << "Flags: " << packet.Flags;
    qDebug() << "Gear: " << packet.Gear;
    qDebug() << "PLID: " << packet.PLID;
    qDebug() << "Speed: " << packet.Speed;
    qDebug() << "RPM: " << packet.RPM;
    qDebug() << "Turbo: " << packet.Turbo;
    qDebug() << "Engine Temp: " << packet.EngTemp;
    qDebug() << "Fuel: " << packet.Fuel;
    qDebug() << "Oil Pressure: " << packet.OilPressure;
    qDebug() << "Oil Temp: " << packet.OilTemp;
    qDebug() << "Dash Lights: " << packet.DashLights;
    qDebug() << "Show Lights: " << packet.ShowLights;
    qDebug() << "Throttle: " << packet.Throttle;
    qDebug() << "Brake: " << packet.Brake;
    qDebug() << "Clutch: " << packet.Clutch;
    qDebug() << "Display1: " << packet.Display1;
    qDebug() << "Display2: " << packet.Display2;
    qDebug() << "ID: " << packet.ID;
#endif

}
