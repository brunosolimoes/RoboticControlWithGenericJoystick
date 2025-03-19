#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>
#include <Servo.h>

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include "hidjoystickrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;


int ang1 = 90;
int ang2 = 110;
int ang3 = 160;
int ang4 = 0;
int ang5 = 90;
int ang6 = 10;

int tempDelay = 40;

void setup() {
        Serial.begin(115200);
#if !defined(__MIPSEL__)
        while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
        Serial.println("Start");

        if (Usb.Init() == -1)
                Serial.println("OSC did not start.");

        delay(200);

        if (!Hid.SetReportParser(0, &Joy))
                ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);

        motor1.attach(2);
        motor2.attach(3);
        motor3.attach(4);
        motor4.attach(5);
        motor5.attach(6);
        motor6.attach(8);

        motor1.write(ang1);
        motor2.write(ang2);
        motor3.write(ang3);
        motor4.write(ang4);
        motor5.write(ang5);
        motor6.write(ang6);
}



void loop() {
        Usb.Task();
        
//================== motor 1 ==================//
      if(JoyEvents.motor1Sentido1){
        if(ang1<=180){
        Serial.print("ang1: ");
        Serial.println(ang1);
        motor1.write(ang1);
        ang1++;
        delay(tempDelay);
        }
      }
      
      if(JoyEvents.motor1Sentido2){
        if(ang1>0){
        Serial.print("ang1: ");
        Serial.println(ang1);
        motor1.write(ang1);
        ang1--;
        delay(tempDelay);
        }
      }

//================== motor 2 ==================//
      if(JoyEvents.motor2Sentido1){
        if(ang2<=180){
        Serial.print("ang2: ");
        Serial.println(ang2);
        motor2.write(ang2);
        ang2++;  
        delay(tempDelay);
        }
      }
      if(JoyEvents.motor2Sentido2){
        if(ang2>0){
        Serial.print("ang2: ");
        Serial.println(ang2);
        motor2.write(ang2);
        ang2--;
        delay(tempDelay);
        }
      }

//================== motor 3 ==================//
      if(JoyEvents.motor3Sentido1){
        if(ang3<=180){
        Serial.print("ang3: ");
        Serial.println(ang3);
        motor3.write(ang3);
        ang3++;  
        delay(tempDelay);
        }
      }
      if(JoyEvents.motor3Sentido2){
        if(ang3>0){
        Serial.print("ang3: ");
        Serial.println(ang3);
        motor3.write(ang3);
        ang3--;
        delay(tempDelay);
        }
      }

//================== motor 4 ==================//
      if(JoyEvents.motor4Sentido1){
        if(ang4<=180){
        Serial.print("ang4: ");
        Serial.println(ang4);
        motor4.write(ang4);
        ang4++;  
        delay(tempDelay);
        }
      }
      if(JoyEvents.motor4Sentido2){
        if(ang4>0){
        Serial.print("ang4: ");
        Serial.println(ang4);
        motor4.write(ang4);
        ang4--;
        delay(tempDelay);
        }
      }

//================== motor 5 ==================//
      if(JoyEvents.motor5Sentido1){
        if(ang5<=180){
        Serial.print("ang5: ");
        Serial.println(ang5);
        motor5.write(ang5);
        ang5++;  
        delay(tempDelay);
        }
      }
      if(JoyEvents.motor5Sentido2){
        if(ang5>0){
        Serial.print("ang5: ");
        Serial.println(ang5);
        motor5.write(ang5);
        ang5--;
        delay(tempDelay);
        }
      }

//================== motor 6 ==================//
      if(JoyEvents.motor6Sentido1){
        if(ang6<=90){
        Serial.print("ang6: ");
        Serial.println(ang6);
        motor6.write(ang6);
        ang6++;  
        delay(tempDelay);
        }
      }
      if(JoyEvents.motor6Sentido2){
        if(ang6>0){
        Serial.print("ang6: ");
        Serial.println(ang6);
        motor6.write(ang6);
        ang6--;
        delay(tempDelay);
        }
      }
}
