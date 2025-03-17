/*!
 *@file  playAllMusic.ino
 *@brief This is a demo for looping playback of built-in music.
 * ---------------------------------------------------------------------------------------------------------------
 *    board   |             MCU                | Leonardo/Mega2560/M0 |    UNO    | ESP8266 | ESP32 |  microbit  |
 *     VCC    |            3.3V/5V             |        VCC           |    VCC    |   VCC   |  VCC  |     X      |
 *     GND    |              GND               |        GND           |    GND    |   GND   |  GND  |     X      |
 *     RX     |              TX                |     Serial1 TX1      |     5     |   5/D6  |  D2   |     X      |
 *     TX     |              RX                |     Serial1 RX1      |     4     |   4/D7  |  D3   |     X      |
 * ---------------------------------------------------------------------------------------------------------------
 * 
 * @copyright   Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [TangJie](jie.tang@dfrobot.com)
 * @version     V1.0
 * @date        2024-11-22
 * @url         https://github.com/DFRobot/DFRobot_SerialMP3
 */

#include "DFRobot_SerialMP3.h"
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
#include <SoftwareSerial.h>
#endif
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  SoftwareSerial mySerial(/*rx =*/4, /*tx =*/5);
  DFRobot_SerialMP3 mp3(/*s =*/&mySerial);
#else
  DFRobot_SerialMP3 mp3(/*s =*/&Serial1);
#endif

void setup()
{
    #if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
        mySerial.begin(9600);
    #elif defined(ESP32)
        Serial1.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
    #else
        Serial1.begin(9600);
    #endif
    
    Serial.begin(115200);
    ///< Reset the device
    mp3.reset();
    delay(1000);

    ///< Detect the device
    while(mp3.getVersion() == 0){
        Serial.println("not fount device !!!");
        delay(100);
    }

    ///< Set volume
    mp3.volumeSet(10);
    delay(10);

    ///< Start playing
    mp3.startPlay();
    delay(10);

}

void loop() 
{
    ///< Wait for 10 seconds of playback
    delay(10000);
    mp3.next();

}

