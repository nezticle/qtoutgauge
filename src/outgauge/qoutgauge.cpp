#include "qoutgauge.h"
#include "qoutgaugebackend_p.h"

QOutGauge::QOutGauge(QObject *parent)
    : QObject(parent)
    , m_outGauge(new QOutGaugeBackend(this))
{
    m_outGauge->registerGauge(this);
}

float QOutGauge::speed() const
{
    return m_speed;
}

float QOutGauge::rpm() const
{
    return m_rpm;
}

float QOutGauge::turbo() const
{
    return m_turbo;
}

float QOutGauge::engineTemp() const
{
    return m_engineTemp;
}

float QOutGauge::fuel() const
{
    return m_fuel;
}

float QOutGauge::oilPressure() const
{
    return m_oilPressure;
}

float QOutGauge::oilTemp() const
{
    return m_oilTemp;
}

float QOutGauge::throttle() const
{
    return m_throttle;
}

float QOutGauge::brake() const
{
    return m_brake;
}

float QOutGauge::clutch() const
{
    return m_clutch;
}

bool QOutGauge::isShiftEnabled() const
{
    return m_isShiftEnabled;
}

bool QOutGauge::isCtrlEnabled() const
{
    return m_isCtrlEnabled;
}

bool QOutGauge::isTurboEnabled() const
{
    return m_isTurboEnabled;
}

bool QOutGauge::preferKM() const
{
    return m_preferKM;
}

bool QOutGauge::preferBar() const
{
    return m_preferBar;
}

bool QOutGauge::shiftLight() const
{
    return m_shiftLight;
}

bool QOutGauge::fullBeamLight() const
{
    return m_fullBeamLight;
}

bool QOutGauge::handbrakeLight() const
{
    return m_handbrakeLight;
}

bool QOutGauge::pitspeedLight() const
{
    return m_pitspeedLight;
}

bool QOutGauge::tcLight() const
{
    return m_tcLight;
}

bool QOutGauge::signalLeftLight() const
{
    return m_signalLeftLight;
}

bool QOutGauge::signalRightLight() const
{
    return m_signalRightLight;
}

bool QOutGauge::signalAnyLight() const
{
    return m_signalAnyLight;
}

bool QOutGauge::oilWarnLight() const
{
    return m_oilWarnLight;
}

bool QOutGauge::batteryLight() const
{
    return m_batteryLight;
}

bool QOutGauge::absLight() const
{
    return m_absLight;
}

bool QOutGauge::spareLight() const
{
    return m_spareLight;
}

int QOutGauge::gear() const
{
    return m_gear;
}

void QOutGauge::processFlags(quint16 flags)
{
    setIsShiftEnabled(flags & OG_SHIFT);
    setIsCtrlEnabled(flags & OG_CTRL);
    setIsTurboEnabled(flags & OG_TURBO);
    setPreferKM(flags & OG_KM);
    setPreferBar(flags & OG_BAR);
}

void QOutGauge::processLights(quint32 lights)
{
    setShiftLight(lights & DL_SHIFT);
    setFullBeamLight(lights & DL_FULLBEAM);
    setHandbrakeLight(lights & DL_HANDBRAKE);
    setPitspeedLight(lights & DL_PITSPEED);
    setTcLight(lights & DL_TC);
    setSignalLeftLight(lights & DL_SIGNAL_L);
    setSignalRightLight(lights & DL_SIGNAL_R);
    setSignalAnyLight(lights & DL_SIGNAL_ANY);
    setOilWarnLight(lights & DL_OILWARN);
    setBatteryLight(lights & DL_BATTERY);
    setAbsLight(lights & DL_ABS);
    setSpareLight(lights & DL_SPARE);
}

void QOutGauge::setSpeed(float speed)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_speed, speed))
        return;

    m_speed = speed;
    emit speedChanged(m_speed);
}

void QOutGauge::setRpm(float rpm)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_rpm, rpm))
        return;

    m_rpm = rpm;
    emit rpmChanged(m_rpm);
}

void QOutGauge::setTurbo(float turbo)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_turbo, turbo))
        return;

    m_turbo = turbo;
    emit turboChanged(m_turbo);
}

void QOutGauge::setEngineTemp(float engineTemp)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_engineTemp, engineTemp))
        return;

    m_engineTemp = engineTemp;
    emit engineTempChanged(m_engineTemp);
}

void QOutGauge::setFuel(float fuel)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_fuel, fuel))
        return;

    m_fuel = fuel;
    emit fuelChanged(m_fuel);
}

void QOutGauge::setOilPressure(float oilPressure)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_oilPressure, oilPressure))
        return;

    m_oilPressure = oilPressure;
    emit oilPressureChanged(m_oilPressure);
}

void QOutGauge::setOilTemp(float oilTemp)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_oilTemp, oilTemp))
        return;

    m_oilTemp = oilTemp;
    emit oilTempChanged(m_oilTemp);
}

void QOutGauge::setThrottle(float throttle)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_throttle, throttle))
        return;

    m_throttle = throttle;
    emit throttleChanged(m_throttle);
}

void QOutGauge::setBrake(float brake)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_brake, brake))
        return;

    m_brake = brake;
    emit brakeChanged(m_brake);
}

void QOutGauge::setClutch(float clutch)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_clutch, clutch))
        return;

    m_clutch = clutch;
    emit clutchChanged(m_clutch);
}

void QOutGauge::setIsShiftEnabled(bool isShiftEnabled)
{
    if (m_isShiftEnabled == isShiftEnabled)
        return;

    m_isShiftEnabled = isShiftEnabled;
    emit isShiftEnabledChanged(m_isShiftEnabled);
}

void QOutGauge::setIsCtrlEnabled(bool isCtrlEnabled)
{
    if (m_isCtrlEnabled == isCtrlEnabled)
        return;

    m_isCtrlEnabled = isCtrlEnabled;
    emit isCtrlEnabledChanged(m_isCtrlEnabled);
}

void QOutGauge::setIsTurboEnabled(bool isTurboEnabled)
{
    if (m_isTurboEnabled == isTurboEnabled)
        return;

    m_isTurboEnabled = isTurboEnabled;
    emit isTurboEnabledChanged(m_isTurboEnabled);
}

void QOutGauge::setPreferKM(bool preferKM)
{
    if (m_preferKM == preferKM)
        return;

    m_preferKM = preferKM;
    emit preferKMChanged(m_preferKM);
}

void QOutGauge::setPreferBar(bool preferBar)
{
    if (m_preferBar == preferBar)
        return;

    m_preferBar = preferBar;
    emit preferBarChanged(m_preferBar);
}

void QOutGauge::setShiftLight(bool shiftLight)
{
    if (m_shiftLight == shiftLight)
        return;

    m_shiftLight = shiftLight;
    emit shiftLightChanged(m_shiftLight);
}

void QOutGauge::setFullBeamLight(bool fullBeamLight)
{
    if (m_fullBeamLight == fullBeamLight)
        return;

    m_fullBeamLight = fullBeamLight;
    emit fullBeamLightChanged(m_fullBeamLight);
}

void QOutGauge::setHandbrakeLight(bool handbrakeLight)
{
    if (m_handbrakeLight == handbrakeLight)
        return;

    m_handbrakeLight = handbrakeLight;
    emit handbrakeLightChanged(m_handbrakeLight);
}

void QOutGauge::setPitspeedLight(bool pitspeedLight)
{
    if (m_pitspeedLight == pitspeedLight)
        return;

    m_pitspeedLight = pitspeedLight;
    emit pitspeedLightChanged(m_pitspeedLight);
}

void QOutGauge::setTcLight(bool tcLight)
{
    if (m_tcLight == tcLight)
        return;

    m_tcLight = tcLight;
    emit tcLightChanged(m_tcLight);
}

void QOutGauge::setSignalLeftLight(bool signalLeftLight)
{
    if (m_signalLeftLight == signalLeftLight)
        return;

    m_signalLeftLight = signalLeftLight;
    emit signalLeftLightChanged(m_signalLeftLight);
}

void QOutGauge::setSignalRightLight(bool signalRightLight)
{
    if (m_signalRightLight == signalRightLight)
        return;

    m_signalRightLight = signalRightLight;
    emit signalRightLightChanged(m_signalRightLight);
}

void QOutGauge::setSignalAnyLight(bool signalAnyLight)
{
    if (m_signalAnyLight == signalAnyLight)
        return;

    m_signalAnyLight = signalAnyLight;
    emit signalAnyLightChanged(m_signalAnyLight);
}

void QOutGauge::setOilWarnLight(bool oilWarnLight)
{
    if (m_oilWarnLight == oilWarnLight)
        return;

    m_oilWarnLight = oilWarnLight;
    emit oilWarnLightChanged(m_oilWarnLight);
}

void QOutGauge::setBatteryLight(bool batteryLight)
{
    if (m_batteryLight == batteryLight)
        return;

    m_batteryLight = batteryLight;
    emit batteryLightChanged(m_batteryLight);
}

void QOutGauge::setAbsLight(bool absLight)
{
    if (m_absLight == absLight)
        return;

    m_absLight = absLight;
    emit absLightChanged(m_absLight);
}

void QOutGauge::setSpareLight(bool spareLight)
{
    if (m_spareLight == spareLight)
        return;

    m_spareLight = spareLight;
    emit spareLightChanged(m_spareLight);
}

void QOutGauge::setGear(int gear)
{
    if (m_gear == gear)
        return;

    m_gear = gear;
    emit gearChanged(m_gear);
}
