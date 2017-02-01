#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x5bc066b6

# Compiled with Coconut version 1.2.0 [Colonel]

"""
Created on Wed Dec 21 11:40:05 2016

@author: User
"""

from __future__ import print_function, absolute_import, unicode_literals, division
import sys as _coconut_sys, os.path as _coconut_os_path
_coconut_file_path = _coconut_os_path.dirname(_coconut_os_path.abspath(__file__))
_coconut_sys.path.insert(0, _coconut_file_path)
from __coconut__ import *
import __coconut__
_coconut_sys.path.remove(_coconut_file_path)
for name in dir(__coconut__):
 if name.startswith("_") and not name.startswith("__"):
  globals()[name] = getattr(__coconut__, name)

import spidev
import time
import os
spi = spidev.SpiDev()
spi.open(0, 0)
def ReadChannel(channel):
 adc = spi.xfer2([1, (8 + channel) << 4, 0])
 data = ((adc[1] & 3) << 8) + adc[2]
 return data
from converter import ConvertVolts
from calculator import addUp
from calculator import average
from distance_sensor import ConvertDistance
def repeat(funct, arg, repetitions=100):
 items = []
 while repetitions > 0:
  processed = funct(arg)
  repetitions -= 1
  items.append(processed)
 return items
def print_distances(channels):
 for channel in channels:
  levels = repeat(ReadChannel, channel)
  print("levels: ", levels)
  volts = list(map(ConvertVolts, levels))
  distances = list(map(ConvertDistance, volts))
  average_levels = average(levels)
  average_volts = average(volts)
  average_distance = average(distances)
  format_data(channel, average_distance, average_levels, average_volts)
def format_data(channel, data, level, volts):
 (print)("Distance {}: {} ({}V) {} cm".format(channel, level, volts, data))
while True:
 get_time = _coconut_compose(time.asctime, time.localtime, time.time)
 (print)("--------------------------------------------")
 (print_distances)(range(3))
 print("Time: " + get_time())
 time.sleep(5)
