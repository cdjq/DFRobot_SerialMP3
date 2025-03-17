/**
 * @file DFRobot_SerialMP3.h
 * @brief This is the implementation of the serial MP3 module driver library
 * @copyright Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2024-11-22
 * @url https://github.com/DFRobot/DFRobot_SerialMP3
 */

#include "DFRobot_SerialMP3.h"
#include "stdio.h"
#include "stdlib.h"

#define BUF_SIZE  100

static uint8_t cmdBuf[7];

DFRobot_SerialMP3::DFRobot_SerialMP3(Stream* s):_s(s){}
DFRobot_SerialMP3::~DFRobot_SerialMP3(){}


uint8_t DFRobot_SerialMP3::next(void)
{
    return sendCMDAndDetectAck(CMD_NEXT, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::previou(void)
{
    return sendCMDAndDetectAck(CMD_PREVIOU, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::specify(uint16_t q)
{
    return sendCMDAndDetectAck(CMD_SPECIFY, q);
}

void DFRobot_SerialMP3::volumeAdd(void)
{
    sendCMDAndDetectAck(CMD_VOLUME_ADD, DATA_ZERO, false);
}

void DFRobot_SerialMP3::volumeSub(void)
{
    sendCMDAndDetectAck(CMD_VOLUME_SUB, DATA_ZERO, false);
}

uint8_t DFRobot_SerialMP3::volumeSet(uint8_t vol)
{
    return sendCMDAndDetectAck(CMD_VOLUME_SET, (uint16_t)vol, false);

}

uint8_t DFRobot_SerialMP3::specifyLoop(uint16_t sp)
{
    return sendCMDAndDetectAck(CMD_SPECIFY_LOOP, sp, false);

}

uint8_t DFRobot_SerialMP3::lPower(void)
{
    return sendCMDAndDetectAck(CMD_L_POWER, DATA_ZERO);
}

void DFRobot_SerialMP3::reset(void)
{
    sendCMDAndDetectAck(CMD_RESET, DATA_ZERO, false);
}

uint8_t DFRobot_SerialMP3::startPlay(void)
{
    return sendCMDAndDetectAck(CMD_START_PLAY, DATA_ZERO);

}

uint8_t DFRobot_SerialMP3::pausePlay(void)
{
    return sendCMDAndDetectAck(CMD_PAUSE, DATA_ZERO);

}

uint8_t DFRobot_SerialMP3::specifyTrask(uint8_t folder, uint8_t sp)
{
    uint8_t sendBuf[2];
    sendBuf[0] = folder;
    sendBuf[1] = sp;
    return sendCMDAndDetectAck(CMD_SPECIFY_TRACK, sendBuf, 2, true);
}

uint8_t DFRobot_SerialMP3::loopAll(void)
{
    return sendCMDAndDetectAck(CMD_LOOP_ALL, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::stopPlay(void)
{
    return sendCMDAndDetectAck(CMD_STOP_PLAY, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::randomAll(void)
{
    return sendCMDAndDetectAck(CMD_RANDOM_ALL, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::currentLoop(void)
{
    return sendCMDAndDetectAck(CMD_LOOP, DATA_ZERO);
}

uint8_t DFRobot_SerialMP3::playAudioMix(uint8_t* buf, uint8_t number)
{
    return sendCMDAndDetectAck(CMD_PLAYBACK, buf, number, true);
}


uint8_t DFRobot_SerialMP3::getState(void)
{
    uint8_t ret = 0;
    if(sendCMDAndDetectAck(CMD_GET_STATE, DATA_ZERO, true)){
        uint16_t state = cmdBuf[4] + cmdBuf[5];
        switch(state){
            case 0x03:
                ret = 1;
            break;
            case 0x04:
                ret = 2;
            break;
            case 0x02:
                ret = 3;
            break;
            default:
                ret = 0;
            break;
        }
    }
    return ret;
}

uint16_t DFRobot_SerialMP3::getVersion(void){
    uint16_t ret = 0;
    if(sendCMDAndDetectAck(CMD_GET_VERSION, DATA_ZERO, true)){
        ret = cmdBuf[4] << 8 | cmdBuf[5];
    }
    return ret;
}

 uint16_t DFRobot_SerialMP3::getFile(void){
    uint16_t ret = 0;
    if(sendCMDAndDetectAck(CMD_GET_FILE, DATA_ZERO, true)){
        ret = cmdBuf[4] << 8 | cmdBuf[5];
    }
    return ret;
 }

 uint16_t DFRobot_SerialMP3::getFileNumber(void){
    uint16_t ret = 0;
    if(sendCMDAndDetectAck(CMD_GET_FILENUMBER, DATA_ZERO, true)){

        ret = cmdBuf[4] << 8 | cmdBuf[5];
    }
    return ret;
 }

 uint8_t DFRobot_SerialMP3::volumeGet(void){
    uint16_t ret = 0;
    if(sendCMDAndDetectAck(CMD_GET_VOLUME, DATA_ZERO, true)){
        ret = cmdBuf[5];
    }
    return ret;
 }


uint8_t DFRobot_SerialMP3::sendCMDAndDetectAck(uint8_t cmd, uint16_t data, bool ack)
{
    uint8_t sendBuf[2];
    sendBuf[0] = data >> 8 & 0xff;
    sendBuf[1] = data & 0xff;
    return sendCMDAndDetectAck(cmd, sendBuf, 2, ack);
}

uint8_t DFRobot_SerialMP3::sendCMDAndDetectAck(uint8_t cmd, uint8_t* data, uint16_t len, bool ack)
{
    uint8_t sendBuf[len+5];
    uint8_t recVBuf[BUF_SIZE];
    uint8_t recvState = 0;
    sendBuf[0] = CMD_START;
    sendBuf[1] = cmd;
    sendBuf[2] = len >> 8 & 0xff;
    sendBuf[3] = len & 0xff;
    for(uint8_t i= 0; i < len; i++){
        sendBuf[4+i] = data[i];
    }
    sendBuf[4+len] = CMD_END;

    for(uint8_t i = 0;i < len+5; i++){
        _s->write(sendBuf[i]);
    }
    delay(10);
    if(ack){
        uint32_t staritTime = millis();
        while((millis() - staritTime) < TIME_OUT){
            if(_s->available()>0){
                staritTime = millis();
                uint8_t data = _s->read();
                if(data == CMD_START){
                    recvState = 0;
                    recVBuf[recvState++] = CMD_START;
                }else if(data == CMD_END){
                    recVBuf[recvState++] = CMD_END;     
                    break; ///< End loop
                }else if(recvState > 0){
                    if(recvState < BUF_SIZE - 1){
                        recVBuf[recvState++] = data;
                    }else{
                        return 0; ///< Throw exception
                    }
                }
            }
        }
    }
    
    return processPacket(recVBuf, recvState);
}

uint8_t DFRobot_SerialMP3::processPacket(uint8_t* buf, uint8_t length)
{
    DBG(length);
    DBG(buf[1]);
    switch(buf[1]){
        case CMD_OK:
        case CMD_GET_VERSION:
        case CMD_GET_FILE: 
        case CMD_GET_STATE:
        case CMD_GET_VOLUME:
        case CMD_GET_FILENUMBER:
            memcpy(cmdBuf,buf,7);
            return 1;
        default:
        break;
    }
    return 0;
}

