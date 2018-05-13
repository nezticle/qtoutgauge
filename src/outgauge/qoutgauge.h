#ifndef QOUTGAUGE_H
#define QOUTGAUGE_H

#include <QtOutGauge/qtoutgaugeglobal.h>
#include <QObject>

class QOutGaugeBackend;
class Q_OUTGAUGE_EXPORT QOutGauge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(float rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(float turbo READ turbo WRITE setTurbo NOTIFY turboChanged)
    Q_PROPERTY(float engineTemp READ engineTemp WRITE setEngineTemp NOTIFY engineTempChanged)
    Q_PROPERTY(float fuel READ fuel WRITE setFuel NOTIFY fuelChanged)
    Q_PROPERTY(float oilPressure READ oilPressure WRITE setOilPressure NOTIFY oilPressureChanged)
    Q_PROPERTY(float oilTemp READ oilTemp WRITE setOilTemp NOTIFY oilTempChanged)
    Q_PROPERTY(float throttle READ throttle WRITE setThrottle NOTIFY throttleChanged)
    Q_PROPERTY(float brake READ brake WRITE setBrake NOTIFY brakeChanged)
    Q_PROPERTY(float clutch READ clutch WRITE setClutch NOTIFY clutchChanged)
    Q_PROPERTY(int gear READ gear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(bool isShiftEnabled READ isShiftEnabled WRITE setIsShiftEnabled NOTIFY isShiftEnabledChanged)
    Q_PROPERTY(bool isCtrlEnabled READ isCtrlEnabled WRITE setIsCtrlEnabled NOTIFY isCtrlEnabledChanged)
    Q_PROPERTY(bool isTurboEnabled READ isTurboEnabled WRITE setIsTurboEnabled NOTIFY isTurboEnabledChanged)
    Q_PROPERTY(bool preferKM READ preferKM WRITE setPreferKM NOTIFY preferKMChanged)
    Q_PROPERTY(bool preferBar READ preferBar WRITE setPreferBar NOTIFY preferBarChanged)
    // Lights
    Q_PROPERTY(bool shiftLight READ shiftLight WRITE setShiftLight NOTIFY shiftLightChanged)
    Q_PROPERTY(bool fullBeamLight READ fullBeamLight WRITE setFullBeamLight NOTIFY fullBeamLightChanged)
    Q_PROPERTY(bool handbrakeLight READ handbrakeLight WRITE setHandbrakeLight NOTIFY handbrakeLightChanged)
    Q_PROPERTY(bool pitspeedLight READ pitspeedLight WRITE setPitspeedLight NOTIFY pitspeedLightChanged)
    Q_PROPERTY(bool tcLight READ tcLight WRITE setTcLight NOTIFY tcLightChanged)
    Q_PROPERTY(bool signalLeftLight READ signalLeftLight WRITE setSignalLeftLight NOTIFY signalLeftLightChanged)
    Q_PROPERTY(bool signalRightLight READ signalRightLight WRITE setSignalRightLight NOTIFY signalRightLightChanged)
    Q_PROPERTY(bool signalAnyLight READ signalAnyLight WRITE setSignalAnyLight NOTIFY signalAnyLightChanged)
    Q_PROPERTY(bool oilWarnLight READ oilWarnLight WRITE setOilWarnLight NOTIFY oilWarnLightChanged)
    Q_PROPERTY(bool batteryLight READ batteryLight WRITE setBatteryLight NOTIFY batteryLightChanged)
    Q_PROPERTY(bool absLight READ absLight WRITE setAbsLight NOTIFY absLightChanged)
    Q_PROPERTY(bool spareLight READ spareLight WRITE setSpareLight NOTIFY spareLightChanged)

public:
    explicit QOutGauge(QObject *parent = nullptr);

    float speed() const;
    float rpm() const;
    float turbo() const;
    float engineTemp() const;
    float fuel() const;
    float oilPressure() const;
    float oilTemp() const;
    float throttle() const;
    float brake() const;
    float clutch() const;
    bool isShiftEnabled() const;
    bool isCtrlEnabled() const;
    bool isTurboEnabled() const;
    bool preferKM() const;
    bool preferBar() const;
    bool shiftLight() const;
    bool fullBeamLight() const;
    bool handbrakeLight() const;
    bool pitspeedLight() const;
    bool tcLight() const;
    bool signalLeftLight() const;
    bool signalRightLight() const;
    bool signalAnyLight() const;
    bool oilWarnLight() const;
    bool batteryLight() const;
    bool absLight() const;
    bool spareLight() const;
    int gear() const;

    void processFlags(quint16 flags);
    void processLights(quint32 lights);

Q_SIGNALS:

    void speedChanged(float speed);
    void rpmChanged(float rpm);
    void turboChanged(float turbo);
    void engineTempChanged(float engineTemp);
    void fuelChanged(float fuel);
    void oilPressureChanged(float oilPressure);
    void oilTempChanged(float oilTemp);
    void throttleChanged(float throttle);
    void brakeChanged(float brake);
    void clutchChanged(float clutch);
    void isShiftEnabledChanged(bool isShiftEnabled);
    void isCtrlEnabledChanged(bool isCtrlEnabled);
    void isTurboEnabledChanged(bool isTurboEnabled);
    void preferKMChanged(bool preferKM);
    void preferBarChanged(bool preferBar);
    void shiftLightChanged(bool shiftLight);
    void fullBeamLightChanged(bool fullBeamLight);
    void handbrakeLightChanged(bool handbrakeLight);
    void pitspeedLightChanged(bool pitspeedLight);
    void tcLightChanged(bool tcLight);
    void signalLeftLightChanged(bool signalLeftLight);
    void signalRightLightChanged(bool signalRightLight);
    void signalAnyLightChanged(bool signalAnyLight);
    void oilWarnLightChanged(bool oilWarnLight);
    void batteryLightChanged(bool batteryLight);
    void absLightChanged(bool absLight);
    void spareLightChanged(bool spareLight);
    void gearChanged(int gear);

public Q_SLOTS:
    void setSpeed(float speed);
    void setRpm(float rpm);
    void setTurbo(float turbo);
    void setEngineTemp(float engineTemp);
    void setFuel(float fuel);
    void setOilPressure(float oilPressure);
    void setOilTemp(float oilTemp);
    void setThrottle(float throttle);
    void setBrake(float brake);
    void setClutch(float clutch);
    void setIsShiftEnabled(bool isShiftEnabled);
    void setIsCtrlEnabled(bool isCtrlEnabled);
    void setIsTurboEnabled(bool isTurboEnabled);
    void setPreferKM(bool preferKM);
    void setPreferBar(bool preferBar);
    void setShiftLight(bool shiftLight);
    void setFullBeamLight(bool fullBeamLight);
    void setHandbrakeLight(bool handbrakeLight);
    void setPitspeedLight(bool pitspeedLight);
    void setTcLight(bool tcLight);
    void setSignalLeftLight(bool signalLeftLight);
    void setSignalRightLight(bool signalRightLight);
    void setSignalAnyLight(bool signalAnyLight);
    void setOilWarnLight(bool oilWarnLight);
    void setBatteryLight(bool batteryLight);
    void setAbsLight(bool absLight);
    void setSpareLight(bool spareLight);
    void setGear(int gear);

private:
    QOutGaugeBackend *m_outGauge = nullptr;

    float m_speed =         0.0f;
    float m_rpm =           0.0f;
    float m_turbo =         0.0f;
    float m_engineTemp =    0.0f;
    float m_fuel =          0.0f;
    float m_oilPressure =   0.0f;
    float m_oilTemp =       0.0f;
    float m_throttle =      0.0f;
    float m_brake =         0.0f;
    float m_clutch =        0.0f;
    bool m_isShiftEnabled = false;
    bool m_isCtrlEnabled =  false;
    bool m_isTurboEnabled = false;
    bool m_preferKM =       false;
    bool m_preferBar =      false;
    bool m_shiftLight =     false;
    bool m_fullBeamLight =  false;
    bool m_handbrakeLight = false;
    bool m_pitspeedLight =  false;
    bool m_tcLight =        false;
    bool m_signalLeftLight =false;
    bool m_signalRightLight=false;
    bool m_signalAnyLight = false;
    bool m_oilWarnLight =   false;
    bool m_batteryLight =   false;
    bool m_absLight =       false;
    bool m_spareLight =     false;
    int m_gear =            1;
};

#endif // QOUTGAUGE_H
