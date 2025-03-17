# -*- coding: utf-8 -*-
'''!
 * @file DFRobot_SerialMP3.py
 * @brief This is the constructor for the serial MP3 module driver library.
 * @copyright Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2024-11-22
 * @url https://github.com/DFRobot/DFRobot_SerialMP3
'''
import serial
import time

class DFRobot_SerialMP3:

    TIME_OUT            =    10     # Data reception timeout, 1ms
    CMD_START           =    0x7E   # Command packet header
    CMD_END             =    0xEF   # Command packet tail
    CMD_OK              =    0x41   # Command packet indicates successful reception
    CMD_ERROR           =    0X40   # Command packet indicates reception error
    CMD_VERSION         =    0x46   # Request version number
    CMD_PLAYSTATE       =    0x42   # Play state

    CMD_NEXT            =    0x01   # Next track
    CMD_PREVIOU         =    0x02   # Previous track
    CMD_SPECIFY         =    0x03   # Play specified song
    CMD_VOLUME_ADD      =    0x04   # Increase volume
    CMD_VOLUME_SUB      =    0x05   # Decrease volume
    CMD_VOLUME_SET      =    0x06   # Set specified volume level
    CMD_SPECIFY_LOOP    =    0x08   # Repeat specified song 
    CMD_L_POWER         =    0x0A   # Chip enters low power mode
    CMD_RESET           =    0x0C   # Chip reset
    CMD_START_PLAY      =    0x0D   # Start playing
    CMD_PAUSE           =    0x0E   # Pause
    CMD_SPECIFY_TRACK   =    0x0F   # Play song from specified folder
    CMD_LOOP_ALL        =    0x11   #Loop all current songs
    CMD_STOP_PLAY       =    0x16   # Stop playing
    CMD_RANDOM_ALL      =    0x18   # Randomly play all current songs
    CMD_LOOP            =    0x19   # Repeat current song
    CMD_PLAYBACK        =    0x21   # Play songs in combination
    CMD_GET_STATE       =    0x42   # Get playback status
    CMD_GET_VOLUME      =    0x43   # Get current volume
    CMD_GET_VERSION     =    0x46   # Query current version
    CMD_GET_FILE        =    0x4A   # Query total number of built-in files
    CMD_GET_FILENUMBER  =    0x4E   # Query current file sequence number in built-in files


    DATA_ZERO          =    0X00
    def __init__(self):
        self.recVBuf = bytearray(100)
        self.cmd_buf = bytearray(7)
        self.recvState = 0
        self.ser = serial.Serial("/dev/ttyAMA0", 9600, timeout=1)
        if self.ser.isOpen == False:
            self.ser.open()

    def next(self):
        '''
            @fn next
            @brief Next track
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_NEXT, self.DATA_ZERO)

    def previou(self):
        '''
            @fn previou
            @breif Previous track
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_PREVIOU, self.DATA_ZERO)

    def specify(self, q):
        '''
            @fn specify
            @brief Play specified track
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_SPECIFY, q)
    
    def volume_add(self):
        '''
            @fn volume_add
            @brief Increase volume
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_ADD, self.DATA_ZERO)

    def volume_sub(self):
        '''
            @fn volume_sub
            @brief Decrease volume
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_SUB, self.DATA_ZERO)
    
    def volume_set(self, vol):
        '''
            @fn volume_set
            @brief Set volume
            @param vol Volume level, range 0~30
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_SET, vol, False)
    
    def volume_get(self):
        '''
            @fn volume_get
            @brief Get current volume
            @return Returns the volume
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_VOLUME, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[5]
            
        return self.ret
        
        
    def specify_loop(self, sp):
        '''
            @fn specify_loop
            @brief Single track loop
            @param sp Loop track number
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_SPECIFY_LOOP, sp, False)

    def lPower(self):
        '''
            @fn lPower
            @brief Set low power mode
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_L_POWER, self.DATA_ZERO)

    def reset(self):
        '''
            @fn reset
            @brief Reset the serial MP3 module
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_RESET, self.DATA_ZERO, False)

    def start_play(self):
        '''
            @fn start_play
            @brief Start playing music
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_START_PLAY, self.DATA_ZERO)

    def pause_play(self):
        '''
            @fn pause_play
            @brief Pause playback
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_PAUSE, self.DATA_ZERO)

    def specify_trask(self,folder, sp):
        '''
            @fn specify_trask
            @brief Play track from specified folder
            @param folder Folder code
            @param sp Song code
            @return 0:Failure, 1:Success
        '''
        self._send_buf = bytearray(2)
        self._send_buf = folder
        self._send_buf = sp
        return self._send_cmd_and_detect_ack(self.CMD_SPECIFY_TRACK, self._send_buf, 2, True)

    def loop_all(self):
        '''
            @fn loop_all
            @brief Loop through all songs
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_LOOP_ALL, self.DATA_ZERO)

    def stop_play(self):
        '''
            @fn stop_play
            @brief Stop playback
            @return 0:Failure, 1:Success
        '''
        return self._send_cmd_and_detect_ack(self.CMD_STOP_PLAY, self.DATA_ZERO)

    def random_all(self):
        '''
            @fn random_all
            @brief Randomly play all songs
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_RANDOM_ALL, self.DATA_ZERO)

    def current_loop(self):
        '''
            @fn current_loop
            @brief Loop current song
            @return 0:Failure, 1:Success
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_LOOP, self.DATA_ZERO)

    def play_audio_mix(self, buf, number):
        '''
            @fn play_audio_mix
            @brief Play specified songs in combination
            @param buf Songs to be played
            @param number Number of songs in the combination
            @return 0:Failure, 1:Success
        '''
        return self._send_cmd_and_detect_ack(self.CMD_LOOP, buf, number,True)


    def get_state(self):
        '''
            @fn get_state
            @brief Get the module's playback status
            @return Returns the playback status: 1: Playing, 2: Paused, 3: Stopped, 0: Error
        '''
        if self.__send_cmd_and_detect_ack(self.CMD_GET_STATE, self.DATA_ZERO, True):
            self.state = self.cmd_buf[4]  + self.cmd_buf[5]
            if self.state == 3:
                return 1
            elif self.state == 4:
                return 2
            elif self.state == 2:
                return 3
        return 0

    def get_version(self):
        '''
            @fn get_version
            @brief Get current version
            @return Returns the current version
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_VERSION, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[4] << 8  | self.cmd_buf[5]
        return self.ret
    
    def get_file(self):
        '''
            @fn get_file
            @brief Get total number of files in built-in storage
            @return Returns the number of files
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_FILE, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[4] << 8 | self.cmd_buf[5]
            
        return self.ret

    def get_file_number(self):
        '''
            @fn get_file_number
            @brief Get current song sequence number
            @return Returns the sequence number
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_FILENUMBER, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[4] << 8 | self.cmd_buf[5]
            
        return self.ret



        
    def __send_cmd_and_detect_ack(self, cmd, data, ack = True):
        self._send_buf = bytearray(2)
        self._send_buf[0] = (data >> 8) & 0xff
        self._send_buf[1] = data & 0xff
        return self._send_cmd_and_detect_ack(cmd, self._send_buf, 2, ack)

    def _send_cmd_and_detect_ack(self, cmd, buf, len, ack = True):
        self._send_buf = bytearray(len+5)

        self._send_buf[0] = self.CMD_START
        self._send_buf[1] = cmd
        self._send_buf[2] = (len >> 8) & 0xff
        self._send_buf[3] = len & 0xff
        for i in range(len):
            self._send_buf[4+i] = buf[i]
        self._send_buf[4+len] = self.CMD_END

        self.ser.write(self._send_buf)
        time.sleep(0.01)
        if ack:
            t_start = time.time()
            while (time.time() - t_start) < self.TIME_OUT:
                data = self.ser.read(1)
                if data:
                    t_start = time.time()
                    hex_value = ord(data[0])
                    if hex_value == self.CMD_START:
                        self.recvState = 0
                        self.recVBuf[self.recvState] = self.CMD_START
                        self.recvState += 1
                    elif hex_value == self.CMD_END:
                        self.recVBuf[self.recvState] = self.CMD_END
                        break
                    elif self.recvState > 0:
                        if self.recvState < (100-1):
                            self.recVBuf[self.recvState] = hex_value
                            self.recvState += 1
                        else:
                            return 0
        
        return self._process_packet(self.recVBuf, self.recvState)
    
    def _process_packet(self, buf, len):
        if buf[1] in (self.CMD_OK, self.CMD_GET_VERSION, self.CMD_GET_FILE, self.CMD_GET_FILENUMBER, self.CMD_GET_STATE, self.CMD_GET_VOLUME):
            self.cmd_buf = buf[:7]
            return 1
        else:
            return 0

                

        