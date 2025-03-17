
/**
 * @file DFRobot_SerialMP3.h
 * @brief This is the constructor for the serial MP3 module driver library.
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

#define TIME_OUT                1000   ///< Data reception timeout, 1ms
#define CMD_START               0x7E   ///< Command packet header
#define CMD_END                 0xEF   ///< Command packet tail
#define CMD_OK                  0x41   ///< Command packet indicates successful reception
#define CMD_ERROR               0X40   ///< Command packet indicates reception error
#define CMD_VERSION             0x46   ///< Request version number
#define CMD_PLAYSTATE           0x42   ///< Play state

#define CMD_NEXT                0x01   ///< Next track
#define CMD_PREVIOU             0x02   ///< Previous track
#define CMD_SPECIFY             0x03   ///< Play specified song
#define CMD_VOLUME_ADD          0x04   ///< Increase volume
#define CMD_VOLUME_SUB          0x05   ///< Decrease volume
#define CMD_VOLUME_SET          0x06   ///< Set specified volume level
#define CMD_SPECIFY_LOOP        0x08   ///< Repeat specified song
#define CMD_L_POWER             0x0A   ///< Chip enters low power mode
#define CMD_RESET               0x0C   ///< Chip reset
#define CMD_START_PLAY          0x0D   ///< Start playing
#define CMD_PAUSE               0x0E   ///< Pause
#define CMD_SPECIFY_TRACK       0x0F   ///< Play song from specified folder
#define CMD_LOOP_ALL            0x11   ///< Loop all current songs
#define CMD_STOP_PLAY           0x16   ///< Stop playing
#define CMD_RANDOM_ALL          0x18   ///< Randomly play all current songs
#define CMD_LOOP                0x19   ///< Repeat current song
#define CMD_PLAYBACK            0x21   ///< Play songs in combination
#define CMD_GET_STATE           0x42   ///< Get playback status
#define CMD_GET_VOLUME          0x43   ///< Get current volume
#define CMD_GET_VERSION         0x46   ///< Query current version
#define CMD_GET_FILE            0x4A   ///< Query total number of built-in files
#define CMD_GET_FILENUMBER      0x4E   ///< Query current file sequence number in built-in files



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
     * @brief Initialize the serial MP3 object
     * @param s Serial interface
     */
    DFRobot_SerialMP3(Stream* s);
    ~DFRobot_SerialMP3();

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

private:

uint8_t sendCMDAndDetectAck(uint8_t cmd, uint16_t data, bool ack = true);
uint8_t sendCMDAndDetectAck(uint8_t cmd, uint8_t* data, uint16_t len, bool ack = true);
uint8_t processPacket(uint8_t* buf, uint8_t length);


Stream* _s;


};

#endif
