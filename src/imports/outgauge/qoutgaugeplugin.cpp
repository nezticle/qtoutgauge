#include "qoutgaugeplugin.h"
#include <QOutGauge>

#include <qqml.h>

void QOutGaugePlugin::registerTypes(const char *uri)
{
    // @uri io.qad.OutGauge
    qmlRegisterType<QOutGauge>(uri, 1, 0, "OutGuage");
}

