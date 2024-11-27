# -*- coding: utf-8 -*-
'''!

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

  mp3.specify_loop(1)
  time.sleep(0.1)


def loop():
  print("Version:",mp3.get_version())
  print("Play State:",mp3.get_state())
  print("File number:",mp3.get_file_number())
  print("All file number:",mp3.get_file())
  time.sleep(1)


if __name__ == "__main__":
  setup()
  while True:
    loop()