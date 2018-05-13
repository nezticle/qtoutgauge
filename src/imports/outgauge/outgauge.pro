TARGET = qtoutgaugeplugin
TARGETPATH = QtOutGauge
IMPORT_VERSION = 1.0

QT += outgauge quick

OTHER_FILES += qmldir

SOURCES += \
    qoutgaugeplugin.cpp
HEADERS += \
    qoutgaugeplugin.h

load(qml_plugin)
