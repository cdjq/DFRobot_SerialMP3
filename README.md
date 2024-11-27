# DFRobot_SerialMP3

- [中文版](./README_CN.md)

    这是一个串口MP3播放模块的库。

![](./resources/images/SEN0628.png)

## Product Link (https://www.dfrobot.com)
    SKU:无

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
    这是一个串口MP3播放模块的库。

## Installation

To use this library, download the library file first, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
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

```


## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno |       √      |             |            | 
FireBeetle esp32 |       √      |             |            | 
FireBeetle esp8266 |       √      |             |            | 
FireBeetle m0 |       √      |             |            | 
Leonardo |       √      |             |            | 
Microbit |       √      |             |            | 
Arduino MEGA2560 | √ | | | 


## History

- data 2024-11-22
- version V1.0


## Credits

Written by tangjie(jie.tang@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))
