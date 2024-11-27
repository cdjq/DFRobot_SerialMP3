# -*- coding: utf-8 -*-
'''!
 * @file DFRobot_SerialMP3.py
 * @brief 这是串口MP3模块驱动库的构造函数
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

    TIME_OUT            =    10     #数据接收超时时间，10ms
    CMD_START           =    0x7E   #命令包头
    CMD_END             =    0xEF   #命令包尾
    CMD_OK              =    0x41   #命令包返回接收成功
    CMD_ERROR           =    0X40   #命令包返回接收错误
    CMD_VERSION         =    0x46   #请求版本号
    CMD_PLAYSTATE       =    0x42   #播放状态
    CMD_NEXT            =    0x01   #下一曲
    CMD_PREVIOU         =    0x02   #上一曲
    CMD_SPECIFY         =    0x03   #播放指定歌曲
    CMD_VOLUME_ADD      =    0x04   #音量加
    CMD_VOLUME_SUB      =    0x05   #音量减
    CMD_VOLUME_SET      =    0x06   #指定音量等级设置
    CMD_SPECIFY_LOOP    =    0x08   #指定歌曲单曲循环
    CMD_L_POWER         =    0x0A   #芯片进入低功耗
    CMD_RESET           =    0x0C   #芯片复位
    CMD_START_PLAY      =    0x0D   #播放
    CMD_PAUSE           =    0x0E   #暂停
    CMD_SPECIFY_TRACK   =    0x0F   #播放指定文件夹中的歌曲
    CMD_LOOP_ALL        =    0x11   #当前全部歌曲循环播放
    CMD_STOP_PLAY       =    0x16   #停止
    CMD_RANDOM_ALL      =    0x18   #当前全部歌曲随机播放
    CMD_LOOP            =    0x19   #当前歌曲单曲循环
    CMD_PLAYBACK        =    0x21   #组合播放歌曲
    CMD_GET_STATE       =    0x42   #获取播放状态
    CMD_GET_VOLUME      =    0x43   #获取当前音量
    CMD_GET_VERSION     =    0x46   #查询当前版本
    CMD_GET_FILE        =    0x4A   #查询内置文件总数量
    CMD_GET_FILENUMBER  =    0x4E   #查询内置文件当前文件序列号

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
            @brief 下一曲
            @return 0:error, 1:ok
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_NEXT, self.DATA_ZERO)

    def previou(self):
        '''
            @fn previou
            @breif 上一曲
            @return 0:error, 1:ok
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_PREVIOU, self.DATA_ZERO)

    def specify(self, q):
        '''
            @fn specify
            @brief 播放指定曲目
            @return 0:error, 1:ok
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_SPECIFY, q)
    
    def volume_add(self):
        '''
            @fn volume_add
            @brief 音量加
            @return 0:error, 1:ok
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_ADD, self.DATA_ZERO)

    def volume_sub(self):
        '''
            @fn volume_sub
            @brief 音量减
            @return 0:error, 1:ok
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_SUB, self.DATA_ZERO)
    
    def volume_set(self, vol):
        '''
            @fn volume_set
            @brief 音量设置
            @param vol 音量大小，范围0~30
            @return 0: 失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_VOLUME_SET, vol, False)
    
    def volume_get(self):
        '''
            @fn volume_get
            @brief 获取当前音量
            @return 返回音量
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_VOLUME, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[5]
            
        return self.ret
        
        
    def specify_loop(self, sp):
        '''
            @fn specify_loop
            @brief 单曲循环
            @param sp 循环曲目编号
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_SPECIFY_LOOP, sp, False)

    def lPower(self):
        '''
            @fn lPower
            @brief 设置低功耗模式
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_L_POWER, self.DATA_ZERO)

    def reset(self):
        '''
            @fn reset
            @brief 复位串口MP模块
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_RESET, self.DATA_ZERO, False)

    def start_play(self):
        '''
            @fn startPlay
            @brief 开始播放音乐
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_START_PLAY, self.DATA_ZERO)

    def pause_play(self):
        '''
            @fn pausePlay
            @brief 暂停播放
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_PAUSE, self.DATA_ZERO)

    def specify_trask(self,folder, sp):
        '''
            @fn specifyTrask
            @brief 播放指定文件夹中的曲目
            @param folder 文件夹代号
            @param sp 歌曲代号
            @return 0：失败，1：成功
        '''
        self._send_buf = bytearray(2)
        self._send_buf = folder
        self._send_buf = sp
        return self._send_cmd_and_detect_ack(self.CMD_SPECIFY_TRACK, self._send_buf, 2, True)

    def loop_all(self):
        '''
            @fn loopAll
            @brief 循环播放全部歌曲
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_LOOP_ALL, self.DATA_ZERO)

    def stop_play(self):
        '''
            @fn stopPlay
            @brief 停止播放
            @return 0：失败，1：成功
        '''
        return self._send_cmd_and_detect_ack(self.CMD_STOP_PLAY, self.DATA_ZERO)

    def random_all(self):
        '''
            @fn randomAll
            @brief 随机播放全部歌曲
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_RANDOM_ALL, self.DATA_ZERO)

    def current_loop(self):
        '''
            @fn currentLoop
            @brief 循环播放当前歌曲
            @return 0：失败，1：成功
        '''
        return self.__send_cmd_and_detect_ack(self.CMD_LOOP, self.DATA_ZERO)

    def play_audio_mix(self, buf, number):
        '''
            @fn playAudioMix
            @brief 组合播放指定歌曲
            @param buf 需要播放的歌曲
            @param number 组合的歌曲数量
            @return 0：失败，1：成功
        '''
        return self._send_cmd_and_detect_ack(self.CMD_LOOP, buf, number,True)


    def get_state(self):
        '''
            @fn getState
            @brief 获取模块播放状态
            @return 返回播放状态，1：播放，2：暂停，3：停止, 0：错误
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
            @fn getVersion
            @brief 获取当前版本
            @return 返回当前版本
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_VERSION, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[4] << 8  | self.cmd_buf[5]
        return self.ret
    
    def get_file(self):
        '''
            @fn getFile
            @brief 获取内置空间总文件数量
            @return 返回文件数量
        '''
        self.ret = 0
        if self.__send_cmd_and_detect_ack(self.CMD_GET_FILE, self.DATA_ZERO, True):
            self.ret = self.cmd_buf[4] << 8 | self.cmd_buf[5]
            
        return self.ret

    def get_file_number(self):
        '''
            @fn getFileNumber
            @brief 获取当前歌曲序列号
            @return 返回序列号
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

                

        