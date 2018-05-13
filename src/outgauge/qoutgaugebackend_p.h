#ifndef OUTGAUGE_H
#define OUTGAUGE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtOutGauge/private/qtoutgaugeglobal_p.h>

#include <QObject>
#include <QVector>

class QUdpSocket;
class QOutGauge;
// Flags
#define OG_SHIFT        1
#define OG_CTRL         2
#define OG_TURBO        8192    // show turbo gauge
#define OG_KM           16384   // if not set - user prefers MILES
#define OG_BAR          32768   //if not set - user prefers PSI

#define DL_SHIFT        1       // bit 0 - shift light
#define DL_FULLBEAM     2       // bit 1 - full beam
#define DL_HANDBRAKE    4       // bit 2 - handbrake
#define DL_PITSPEED     8       // bit 3 - pit speed limiter
#define DL_TC           16      // bit 4 - TC active or switched off
#define DL_SIGNAL_L     32      // bit 5 - left turn signal
#define DL_SIGNAL_R     64      // bit 6 - right turn signal
#define DL_SIGNAL_ANY   128     // bit 7 - shared turn signal
#define DL_OILWARN      256     // bit 8 - oil pressure warning
#define DL_BATTERY      512     // bit 9 - battery warning
#define DL_ABS          1024    // bit 10 - ABS active or switched off
#define DL_SPARE        2048    // bit 11

class Q_OUTGAUGE_PRIVATE_EXPORT QOutGaugeBackend : public QObject
{
    Q_OBJECT
public:
    explicit QOutGaugeBackend(QObject *parent = nullptr);

    void registerGauge(QOutGauge *gauge);
    void deregisterGauge(QOutGauge *gauge);

private Q_SLOTS:
    void processPendingDatagrams();
private:
    QUdpSocket *m_outGaugeSocket = nullptr;
    QVector<QOutGauge*> m_gauges;
};

#endif // OUTGAUGE_H
