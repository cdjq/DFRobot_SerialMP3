# DFRobot_SerialMP3
- [中文版](./README_CN.md)

    This is a library for the serial MP3 playback module.

![](./resources/images/SEN0628.png)

## Product link(https://www.dfrobot.com)

    SKU：SEN0628

## 目录

* [Overview](#Overview)
* [installation](#installation)
* [Methods](#Methods)
* [compatibility](#compatibility)
* [history](#history)
* [credits](#credits)

## Overview
This is a library for the serial MP3 playback module.

## installation

Before using this library, first download the library files, paste them into the \Arduino\libraries directory, then open the examples folder and run the examples within that folder.

## Methods

```python
  def next(self):
        '''
            @fn next
            @brief Next track
            @return 0:Failure, 1:Success
        '''

    def previou(self):
        '''
            @fn previou
            @breif Previous track
            @return 0:Failure, 1:Success
        '''

    def specify(self, q):
        '''
            @fn specify
            @brief Play specified track
            @return 0:Failure, 1:Success
        '''
    
    def volume_add(self):
        '''
            @fn volume_add
            @brief Increase volume
            @return 0:Failure, 1:Success
        '''

    def volume_sub(self):
        '''
            @fn volume_sub
            @brief Decrease volume
            @return 0:Failure, 1:Success
        '''
    
    def volume_set(self, vol):
        '''
            @fn volume_set
            @brief Set volume
            @param vol Volume level, range 0~30
            @return 0:Failure, 1:Success
        '''
    
    def volume_get(self):
        '''
            @fn volume_get
            @brief Get current volume
            @return Returns the volume
        '''
        
    def specify_loop(self, sp):
        '''
            @fn specify_loop
            @brief Single track loop
            @param sp Loop track number
            @return 0:Failure, 1:Success
        '''

    def lPower(self):
        '''
            @fn lPower
            @brief Set low power mode
            @return 0:Failure, 1:Success
        '''

    def reset(self):
        '''
            @fn reset
            @brief Reset the serial MP3 module
            @return 0:Failure, 1:Success
        '''

    def start_play(self):
        '''
            @fn start_play
            @brief Start playing music
            @return 0:Failure, 1:Success
        '''

    def pause_play(self):
        '''
            @fn pause_play
            @brief Pause playback
            @return 0:Failure, 1:Success
        '''

    def specify_trask(self,folder, sp):
        '''
            @fn specify_trask
            @brief Play track from specified folder
            @param folder Folder code
            @param sp Song code
            @return 0:Failure, 1:Success
        '''

    def loop_all(self):
        '''
            @fn loop_all
            @brief Loop through all songs
            @return 0:Failure, 1:Success
        '''

    def stop_play(self):
        '''
            @fn stop_play
            @brief Stop playback
            @return 0:Failure, 1:Success
        '''

    def random_all(self):
        '''
            @fn random_all
            @brief Randomly play all songs
            @return 0:Failure, 1:Success
        '''

    def current_loop(self):
        '''
            @fn current_loop
            @brief Loop current song
            @return 0:Failure, 1:Success
        '''

    def play_audio_mix(self, buf, number):
        '''
            @fn play_audio_mix
            @brief Play specified songs in combination
            @param buf Songs to be played
            @param number Number of songs in the combination
            @return 0:Failure, 1:Success
        '''

    def get_state(self):
        '''
            @fn get_state
            @brief Get the module's playback status
            @return Returns the playback status: 1: Playing, 2: Paused, 3: Stopped, 0: Error
        '''

    def get_version(self):
        '''
            @fn get_version
            @brief Get current version
            @return Returns the current version
        '''
    
    def get_file(self):
        '''
            @fn get_file
            @brief Get total number of files in built-in storage
            @return Returns the number of files
        '''

    def get_file_number(self):
        '''
            @fn get_file_number
            @brief Get current song sequence number
            @return Returns the sequence number
        '''
```

## compatibility

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


## history

- 2024-11-22 - Version 1.0.0 released.

## credits

Written by TangJie(jie.tang@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))





