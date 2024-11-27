/*!
 *@file  playMusicSet.ino
 *@brief 这是一个设置模块的示例代码。
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
    ///<复位设备
    mp3.reset();
    delay(1000);

    ///<检测设备
    while(mp3.getVersion() == 0){
        Serial.println("not fount device !!!");
        delay(100);
    }

    ///<设置音量
    mp3.volumeSet(10);

    ///<开始播放
    mp3.startPlay();
    delay(10000);

    ///<播放暂停
    mp3.pausePlay();
    delay(100);

    ///<设置单曲循环
    mp3.specifyLoop(3);
    delay(10);

}

void loop() 
{
    delay(1000);

}

