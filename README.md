# DFRobot_SerialMP3

- [中文版](./README_CN.md)

    This is a library for the serial MP3 playback module.

![](./resources/images/SEN0628.png)

## Product Link (https://www.dfrobot.com)
    SKU:NULL

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
    This is a library for the serial MP3 playback module.

## Installation

To use this library, download the library file first, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

    /**
     * @fn next
     * @brief Next track
     * @return 0: Failure, 1: Success
     */
    uint8_t next(void);

    /**
     * @fn previou
     * @brief Previous track
     * @return 0: Failure, 1: Success
     */
    uint8_t previou(void);

    /**
     * @fn specify
     * @brief Play specified track
     * @return 0: Failure, 1: Success
     */
    uint8_t specify(uint16_t q);

    /**
     * @fn volumeAdd
     * @brief Increase volume
     * @return NULL
     */
    void volumeAdd(void);

    /**
     * @fn volumeSub
     * @brief Decrease volume
     * @return NULL
     */
    void volumeSub(void);

    /**
     * @fn volumeSet
     * @brief Set volume
     * @param vol Volume level, range 0~30
     * @return 0: Failure, 1: Success
     */
    uint8_t volumeSet(uint8_t vol);

    /**
     * @fn volumeGet
     * @brief Get current volume
     * @return Returns the volume
     */
    uint8_t volumeGet(void);

    /**
     * @fn specifyLoop
     * @brief Single track loop
     * @param sp Loop track number
     * @return 0: Failure, 1: Success
     */
    uint8_t specifyLoop(uint16_t sp);

    /**
     * @fn lPower
     * @brief Set low power mode
     * @return 0: Failure, 1: Success
     */
    uint8_t lPower(void);

    /**
     * @fn reset
     * @brief Reset the serial MP3 module
     * @return 0: Failure, 1: Success
     */
    void reset(void);

    /**
     * @fn startPlay
     * @brief Start playing music
     * @return 0: Failure, 1: Success
     */
    uint8_t startPlay(void);

    /**
     * @fn pausePlay
     * @brief Pause playback
     * @return 0: Failure, 1: Success
     */
    uint8_t pausePlay(void);

    /**
     * @fn specifyTrack
     * @brief Play track from specified folder
     * @param folder Folder code
     * @param sp Song code
     * @return 0: Failure, 1: Success
     */
    uint8_t specifyTrask(uint8_t folder, uint8_t sp);

    /**
     * @fn loopAll
     * @brief Loop through all songs
     * @return 0: Failure, 1: Success
     */
    uint8_t loopAll(void);

    /**
     * @fn stopPlay
     * @brief Stop playback
     * @return 0: Failure, 1: Success
     */
    uint8_t stopPlay(void);

    /**
     * @fn randomAll
     * @brief Randomly play all songs
     * @return 0: Failure, 1: Success
     */
    uint8_t randomAll(void);

    /**
     * @fn currentLoop
     * @brief Loop current song
     * @return 0: Failure, 1: Success
     */
    uint8_t currentLoop(void);

    /**
     * @fn playAudioMix
     * @brief Play specified songs in combination
     * @param buf Songs to be played
     * @param number Number of songs in the combination
     * @return 0: Failure, 1: Success
     */
    uint8_t playAudioMix(uint8_t* buf, uint8_t number); 

    /**
     * @fn getState
     * @brief Get the module's playback status
     * @return Returns the playback status: 1: Playing, 2: Paused, 3: Stopped, 0: Error
     */
    uint8_t getState(void);

    /**
     * @fn getVersion
     * @brief Get current version
     * @return Returns the current version
     */
    uint16_t getVersion(void);

    /**
     * @fn getFile
     * @brief Get total number of files in built-in storage
     * @return Returns the number of files
     */
    uint16_t getFile(void);

    /**
     * @fn getFileNumber
     * @brief Get current song sequence number
     * @return Returns the sequence number
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
