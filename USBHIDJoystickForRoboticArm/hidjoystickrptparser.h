#if !defined(__HIDJOYSTICKRPTPARSER_H__)
#define __HIDJOYSTICKRPTPARSER_H__

#include <usbhid.h>

struct GamePadEventData {
        uint8_t X, Y, Z1, Z2, Rz;
};

class JoystickEvents {
public:
        boolean debug = true;
        boolean motor1Sentido1 = false;
        boolean motor1Sentido2 = false;
        boolean motor2Sentido1 = false;
        boolean motor2Sentido2 = false;
        boolean motor3Sentido1 = false;
        boolean motor3Sentido2 = false;
        boolean motor4Sentido1 = false;
        boolean motor4Sentido2 = false;
        boolean motor5Sentido1 = false;
        boolean motor5Sentido2 = false;
        boolean motor6Sentido1 = false;
        boolean motor6Sentido2 = false;
        
        virtual void OnGamePadChanged(const GamePadEventData *evt);
        virtual void OnHatSwitch(uint8_t hat);
        virtual void OnButtonUp(uint8_t but_id);
        virtual void OnButtonDn(uint8_t but_id);
        virtual void callMovMotorBtn(uint8_t but_id, boolean statusMotorMov);
        virtual void callMovMotorPad(const GamePadEventData *evt);
};

#define RPT_GEMEPAD_LEN		5

class JoystickReportParser : public HIDReportParser {
        JoystickEvents *joyEvents;

        uint8_t oldPad[RPT_GEMEPAD_LEN];
        uint8_t oldHat;
        uint16_t oldButtons;

public:
        JoystickReportParser(JoystickEvents *evt);

        virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};

#endif // __HIDJOYSTICKRPTPARSER_H__
