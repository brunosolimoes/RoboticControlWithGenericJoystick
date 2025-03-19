#include "hidjoystickrptparser.h"



JoystickReportParser::JoystickReportParser(JoystickEvents *evt) :
joyEvents(evt),
oldHat(0xDE),
oldButtons(0) {
        for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
                oldPad[i] = 0xD;
}


void JoystickReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
        bool match = true;

        // Checking if there are changes in report since the method was last called
        for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++)
                if (buf[i] != oldPad[i]) {
                        match = false;
                        break;
                }

        // Calling Game Pad event handler
        if (!match && joyEvents) {
                joyEvents->OnGamePadChanged((const GamePadEventData*)buf);

                for (uint8_t i = 0; i < RPT_GEMEPAD_LEN; i++) oldPad[i] = buf[i];
        }

        uint8_t hat = (buf[5] & 0xF);

        // Calling Hat Switch event handler
        if (hat != oldHat && joyEvents) {
                joyEvents->OnHatSwitch(hat);
                oldHat = hat;
        }

        uint16_t buttons = (0x0000 | buf[6]);
        buttons <<= 4;
        buttons |= (buf[5] >> 4);
        uint16_t changes = (buttons ^ oldButtons);

        // Calling Button Event Handler for every button changed
        if (changes) {
                for (uint8_t i = 0; i < 0x0C; i++) {
                        uint16_t mask = (0x0001 << i);

                        if (((mask & changes) > 0) && joyEvents) {
                                if ((buttons & mask) > 0)
                                        joyEvents->OnButtonDn(i + 1);
                                else
                                        joyEvents->OnButtonUp(i + 1);
                        }
                }
                oldButtons = buttons;
        }
}

void JoystickEvents::OnHatSwitch(uint8_t hat) {
        Serial.print("Hat Switch: ");
        PrintHex<uint8_t > (hat, 0x80);
        Serial.println("");
}

void JoystickEvents::callMovMotorPad(const GamePadEventData *evt){
        
        if(evt->Rz == 255){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor1Sentido1 = true;                
          }else{
                this->motor1Sentido1 = true;
          }
          
        }
        if(evt->Rz == 0){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor1Sentido2 = true;
          }else{
                this->motor1Sentido2 = true;
          }
          
        }

        if(evt->Z2 == 0){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor2Sentido1 = true;                
          }else{
                this->motor2Sentido1 = true;
          }
          
        }
        if(evt->Z2 == 255){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor2Sentido2 = true;
          }else{
                this->motor2Sentido2 = true;
          }
          
        }


        if(evt->Rz == 127){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor1Sentido1 = false;
                this->motor1Sentido2 = false;
          }else{
                this->motor1Sentido1 = false;
                this->motor1Sentido2 = false;
          }
          
        }

        if(evt->Z2 == 127){
          if(this->debug){
                Serial.print("Print debug ON");
                this->motor2Sentido1 = false;
                this->motor2Sentido2 = false;
          }else{
                this->motor2Sentido1 = false;
                this->motor2Sentido2 = false;
          }
          
        }
        // ^: Rz: 0

        // v: Rz: 255


        // < Y2: 0

        // > Y2: 255


        // +: Y2: 127
        //    Rz: 127
}

void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt) {
        
         Serial.print("X1: ");
         // PrintHex<uint8_t > (evt->X, 0x80);
         Serial.println(evt->X);
         
         Serial.print("\tY1: ");
         // PrintHex<uint8_t > (evt->Y, 0x80);
         Serial.println(evt->Y);
        
         Serial.print("\tX2: ");
         // PrintHex<uint8_t > (evt->Z1, 0x80);
         Serial.println(evt->Z1);
        
         Serial.print("\tY2: ");
         // PrintHex<uint8_t > (evt->Z2, 0x80);
         Serial.println(evt->Z2);
        
         Serial.print("\tRz: ");
         // PrintHex<uint8_t > (evt->Rz, 0x80);
         Serial.println(evt->Rz);
        
        Serial.println("");

        callMovMotorPad(evt);
}

void JoystickEvents::callMovMotorBtn(uint8_t but_id, boolean statusMotorMov){

        if(but_id == 1){
          if(this->debug){
                this->motor3Sentido1 = statusMotorMov;
                Serial.print("valor na .h: ");
                Serial.println(this->motor3Sentido1);
          }else{
                this->motor3Sentido1 = statusMotorMov;
          }
          
        }
        if(but_id == 3){
          if(this->debug){
                this->motor3Sentido2 = statusMotorMov;
                Serial.print("valor na .h: ");
                Serial.println(this->motor3Sentido2);
          }else{
                this->motor3Sentido2 = statusMotorMov;
          }
        }

        if(but_id == 2){
          if(this->debug){
                this->motor4Sentido1 = statusMotorMov;
                Serial.print("valor na .h: ");
                Serial.println(this->motor4Sentido1);
          }else{
                this->motor4Sentido1 = statusMotorMov;
          }
        }

        if(but_id == 4){
          if(this->debug){
                this->motor4Sentido2 = statusMotorMov;
                Serial.print("valor na .h: ");
                Serial.println(this->motor4Sentido2);
          }else{
                this->motor4Sentido2 = statusMotorMov;
          }
        }

        if(but_id == 5){
            if(this->debug){
                  this->motor5Sentido1 = statusMotorMov;
                  Serial.print("valor na .h: ");
                  Serial.println(this->motor5Sentido1);
            }else{
                  this->motor5Sentido1 = statusMotorMov;
            }
          }
  
          if(but_id == 6){
            if(this->debug){
                  this->motor5Sentido2 = statusMotorMov;
                  Serial.print("valor na .h: ");
                  Serial.println(this->motor5Sentido2);
            }else{
                  this->motor5Sentido2 = statusMotorMov;
            }
          }

          if(but_id == 7){
            if(this->debug){
                  this->motor6Sentido1 = statusMotorMov;
                  Serial.print("valor na .h: ");
                  Serial.println(this->motor6Sentido1);
            }else{
                  this->motor6Sentido1 = statusMotorMov;
            }
          }
  
          if(but_id == 8){
            if(this->debug){
                  this->motor6Sentido2 = statusMotorMov;
                  Serial.print("valor na .h: ");
                  Serial.println(this->motor6Sentido2);
            }else{
                  this->motor6Sentido2 = statusMotorMov;
            }
          }

}


void JoystickEvents::OnButtonUp(uint8_t but_id) {
        boolean statusMotorMov = false;

        if(this->debug){
          Serial.print("Up: ");
          Serial.println(but_id, DEC);
        }
        
        callMovMotorBtn(but_id, statusMotorMov);
   
}

void JoystickEvents::OnButtonDn(uint8_t but_id) {
        boolean statusMotorMov = true;

        if(this->debug){
          Serial.print("Dn: ");
          Serial.println(but_id, DEC);
        }
        
        callMovMotorBtn(but_id, statusMotorMov);
        
}
