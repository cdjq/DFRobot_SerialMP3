# -*- coding: utf-8 -*-
'''!
  @file  play_all_music.py
  @brief This is a demo for looping playback of built-in music.
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


def loop():
  time.sleep(10)
  mp3.next()


if __name__ == "__main__":
  setup()
  while True:
    loop()