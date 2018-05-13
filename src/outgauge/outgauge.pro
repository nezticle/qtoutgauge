TARGET = QtOutGauge
MODULE = outgauge

QT = core network

SOURCES += \
    qoutgaugebackend.cpp \
    qoutgauge.cpp

HEADERS += \
    qoutgauge.h \
    qoutgaugebackend_p.h \
    qtoutgaugeglobal.h \
    qtoutgaugeglobal_p.h

load(qt_module)
