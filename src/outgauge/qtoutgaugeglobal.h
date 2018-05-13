#ifndef QTOUTGAUGEGLOBAL_H
#define QTOUTGAUGEGLOBAL_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_OUTGAUGE_LIB)
#    define Q_OUTGAUGE_EXPORT Q_DECL_EXPORT
#  else
#    define Q_OUTGAUGE_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_OUTGAUGE_EXPORT
#endif

QT_END_NAMESPACE

#endif // QTOUTGAUGEGLOBAL_H
