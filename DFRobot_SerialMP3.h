
/**
 * @file DFRobot_SerialMP3.h
 * @brief 这是串口MP3模块驱动库的构造函数
 * @copyright Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2024-11-22
 * @url https://github.com/DFRobot/DFRobot_SerialMP3
 */

#ifndef _DFROBOT_SERIALMP3_
#define _DFROBOT_SERIALMP3_
#include "Arduino.h"

#define TIME_OUT                1000   ///< 数据接收超时时间，1ms
#define CMD_START               0x7E   ///< 命令包头
#define CMD_END                 0xEF   ///< 命令包尾
#define CMD_OK                  0x41   ///< 命令包返回接收成功
#define CMD_ERROR               0X40   ///< 命令包返回接收错误
#define CMD_VERSION             0x46   ///<请求版本号
#define CMD_PLAYSTATE           0x42   ///<播放状态

#define CMD_NEXT                0x01   ///< 下一曲
#define CMD_PREVIOU             0x02   ///< 上一曲
#define CMD_SPECIFY             0x03   ///< 播放指定歌曲
#define CMD_VOLUME_ADD          0x04   ///< 音量加
#define CMD_VOLUME_SUB          0x05   ///< 音量减
#define CMD_VOLUME_SET          0x06   ///< 指定音量等级设置
#define CMD_SPECIFY_LOOP        0x08   ///< 指定歌曲单曲循环
#define CMD_L_POWER             0x0A   ///< 芯片进入低功耗
#define CMD_RESET               0x0C   ///< 芯片复位
#define CMD_START_PLAY          0x0D   ///< 播放
#define CMD_PAUSE               0x0E   ///< 暂停
#define CMD_SPECIFY_TRACK       0x0F   ///< 播放指定文件夹中的歌曲
#define CMD_LOOP_ALL            0x11   ///< 当前全部歌曲循环播放
#define CMD_STOP_PLAY           0x16   ///< 停止
#define CMD_RANDOM_ALL          0x18   ///< 当前全部歌曲随机播放
#define CMD_LOOP                0x19   ///< 当前歌曲单曲循环
#define CMD_PLAYBACK            0x21   ///< 组合播放歌曲
#define CMD_GET_STATE           0x42   ///< 获取播放状态
#define CMD_GET_VOLUME          0x43   ///< 获取当前音量
#define CMD_GET_VERSION         0x46   ///< 查询当前版本
#define CMD_GET_FILE            0x4A   ///< 查询内置文件总数量`
#define CMD_GET_FILENUMBER      0x4E   ///< 查询内置文件当前文件序列号



#define DATA_ZERO              0x00
#define ACHE_MAX_LEN            32


//#define ENABLE_DBG ///< Enable this macro to see the detailed execution process of the program
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

class DFRobot_SerialMP3
{
public:
    /**
     * @brief 初始化串口MP3对象
     * @param s 串口接口
     */

    DFRobot_SerialMP3(Stream* s);
    ~DFRobot_SerialMP3();

    /**
     * @fn next
     * @brief 下一曲
     * @return 0: 失败，1：成功
     */

    uint8_t next(void);

    /**
     * @fn previou
     * @brief 上一曲
     * @return 0: 失败，1：成功
     */

    uint8_t previou(void);

    /**
     * @fn specify
     * @brief 播放指定曲目,
     * @return 0: 失败，1：成功
     */

    uint8_t specify(uint16_t q);

    /**
     * @fn volumeAdd
     * @brief 音量加
     * @return NULL
     */

    void volumeAdd(void);

    /**
     * @fn volumeSub
     * @brief 音量减
     * @return NULL
     */

    void volumeSub(void);

    /**
     * @fn volumeSet
     * @brief 音量设置
     * @param vol 音量大小，范围0~30
     * @return 0: 失败，1：成功
     */

    uint8_t volumeSet(uint8_t vol);

    /**
     * @fn volumeGet
     * @brief 获取当前音量
     * @return 返回音量
     */

    uint8_t volumeGet(void);

    /**
     * @fn specifyLoop
     * @brief 单曲循环
     * @param sp 循环曲目编号
     * @return 0：失败，1：成功
     */

    uint8_t specifyLoop(uint16_t sp);

    /**
     * @fn lPower
     * @brief 设置低功耗模式
     * @return 0：失败，1：成功
     */

    uint8_t lPower(void);

    /**
     * @fn reset
     * @brief 复位串口MP模块
     * @return 0：失败，1：成功
     */

    void reset(void);

    /**
     * @fn startPlay
     * @brief 开始播放音乐
     * @return 0：失败，1：成功
     */

    uint8_t startPlay(void);

    /**
     * @fn pausePlay
     * @brief 暂停播放
     * @return 0：失败，1：成功
     */

    uint8_t pausePlay(void);

    /**
     * @fn specifyTrask
     * @brief 播放指定文件夹中的曲目
     * @param folder 文件夹代号
     * @param sp 歌曲代号
     * @return 0：失败，1：成功
     */

    uint8_t specifyTrask(uint8_t folder, uint8_t sp);

    /**
     * @fn loopAll
     * @brief 循环播放全部歌曲
     * @return 0：失败，1：成功
     */

    uint8_t loopAll(void);

    /**
     * @fn stopPlay
     * @brief 停止播放
     * @return 0：失败，1：成功
     */

    uint8_t stopPlay(void);

    /**
     * @fn randomAll
     * @brief 随机播放全部歌曲
     * @return 0：失败，1：成功
     */

    uint8_t randomAll(void);

    /**
     * @fn currentLoop
     * @brief 循环播放当前歌曲
     * @return 0：失败，1：成功
     */

    uint8_t currentLoop(void);

    /**
     * @fn playAudioMix
     * @brief 组合播放指定歌曲
     * @param buf 需要播放的歌曲
     * @param number 组合的歌曲数量
     * @return 0：失败，1：成功
     */

    uint8_t playAudioMix(uint8_t* buf, uint8_t number); 

    /**
     * @fn getState
     * @brief 获取模块播放状态
     * @return 返回播放状态，1：播放，2：暂停，3：停止, 0：错误
     */

    uint8_t getState(void);

    /**
     * @fn getVersion
     * @brief 获取当前版本
     * @return 返回当前版本
     */

    uint16_t getVersion(void);

    /**
     * @fn getFile
     * @brief 获取内置空间总文件数量
     * @return 返回文件数量
     */
    
    uint16_t getFile(void);

    /**
     * @fn getFileNumber
     * @brief 获取当前歌曲序列号
     * @return 返回序列号
     */

    uint16_t getFileNumber(void);

private:

uint8_t sendCMDAndDetectAck(uint8_t cmd, uint16_t data, bool ack = true);
uint8_t sendCMDAndDetectAck(uint8_t cmd, uint8_t* data, uint16_t len, bool ack = true);
uint8_t processPacket(uint8_t* buf, uint8_t length);


Stream* _s;


};

#endif
