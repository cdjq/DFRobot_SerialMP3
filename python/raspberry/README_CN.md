# DFRobot_SerialMP3
- [English Version](./README.md)

    这是一个串口MP3播放模块的库。

![](./resources/images/SEN0628.png)

## 产品链接(https://www.dfrobot.com.cn)

    SKU：无

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)

## 概述
  这是一个串口MP3播放模块的库。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```python
    def next(self):
        '''
            @fn next
            @brief 下一曲
            @return 0:error, 1:ok
        '''

    def previou(self):
        '''
            @fn previou
            @breif 上一曲
            @return 0:error, 1:ok
        '''

    def specify(self, q):
        '''
            @fn specify
            @brief 播放指定曲目
            @return 0:error, 1:ok
        '''
    
    def volume_add(self):
        '''
            @fn volume_add
            @brief 音量加
            @return 0:error, 1:ok
        '''

    def volume_sub(self):
        '''
            @fn volume_sub
            @brief 音量减
            @return 0:error, 1:ok
        '''
    
    def volume_set(self, vol):
        '''
            @fn volume_set
            @brief 音量设置
            @param vol 音量大小，范围0~30
            @return 0: 失败，1：成功
        '''
    
    def volume_get(self):
        '''
            @fn volume_get
            @brief 获取当前音量
            @return 返回音量
        '''
        
    def specify_loop(self, sp):
        '''
            @fn specify_loop
            @brief 单曲循环
            @param sp 循环曲目编号
            @return 0：失败，1：成功
        '''

    def lPower(self):
        '''
            @fn lPower
            @brief 设置低功耗模式
            @return 0：失败，1：成功
        '''

    def reset(self):
        '''
            @fn reset
            @brief 复位串口MP模块
            @return 0：失败，1：成功
        '''

    def start_play(self):
        '''
            @fn startPlay
            @brief 开始播放音乐
            @return 0：失败，1：成功
        '''

    def pause_play(self):
        '''
            @fn pausePlay
            @brief 暂停播放
            @return 0：失败，1：成功
        '''

    def specify_trask(self,folder, sp):
        '''
            @fn specifyTrask
            @brief 播放指定文件夹中的曲目
            @param folder 文件夹代号
            @param sp 歌曲代号
            @return 0：失败，1：成功
        '''

    def loop_all(self):
        '''
            @fn loopAll
            @brief 循环播放全部歌曲
            @return 0：失败，1：成功
        '''

    def stop_play(self):
        '''
            @fn stopPlay
            @brief 停止播放
            @return 0：失败，1：成功
        '''

    def random_all(self):
        '''
            @fn randomAll
            @brief 随机播放全部歌曲
            @return 0：失败，1：成功
        '''

    def current_loop(self):
        '''
            @fn currentLoop
            @brief 循环播放当前歌曲
            @return 0：失败，1：成功
        '''

    def play_audio_mix(self, buf, number):
        '''
            @fn playAudioMix
            @brief 组合播放指定歌曲
            @param buf 需要播放的歌曲
            @param number 组合的歌曲数量
            @return 0：失败，1：成功
        '''

    def get_state(self):
        '''
            @fn getState
            @brief 获取模块播放状态
            @return 返回播放状态，1：播放，2：暂停，3：停止, 0：错误
        '''

    def get_version(self):
        '''
            @fn getVersion
            @brief 获取当前版本
            @return 返回当前版本
        '''
    
    def get_file(self):
        '''
            @fn getFile
            @brief 获取内置空间总文件数量
            @return 返回文件数量
        '''

    def get_file_number(self):
        '''
            @fn getFileNumber
            @brief 获取当前歌曲序列号
            @return 返回序列号
        '''
```

## 兼容性

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |     √     |            |          |         |
| RaspberryPi4 |           |            |     √    |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |           |            |    √     |         |
| Python3 |     √     |            |          |         |


## 历史

- 2024-11-22 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))




