# -*- coding: utf-8 -*-
'''!
  @play_music_set.py
  @brief This is an example code for setting up the module.
  @copyright   Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      [TangJie](jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-11-22
  @url         https://github.com/DFRobot/DFRobot_SerialMP3
'''

from __future__ import print_function
import sys
import os
sys.path.append("../")
import time

from DFRobot_SerialMP3 import *

mp3 = DFRobot_SerialMP3()


def setup():
  mp3.reset()
  time.sleep(1)

  mp3.volume_set(10)
  time.sleep(0.1)

  mp3.start_play()
  time.sleep(10)

  mp3.pause_play()
  time.sleep(10)

  mp3.specify_loop(3)
  time.sleep(10)


def loop():
  time.sleep(10)
  

if __name__ == "__main__":
  setup()
  while True:
    loop()