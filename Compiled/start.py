#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x87b0b10e

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
ir_channel = 0
delay = 5
from distance_sensor import ConvertDistance
def repeat(data, repetitions, result=[]):
 if (repetitions == 0):
  return result
 addItem = _coconut_compose(result.append, list)
 repeat(data, repetitions - 1, addItem(data))
def print_distances(channels):
 times_100 = _coconut.functools.partial(repeat, 100)
 print_data = _coconut_compose(format_data, average)
 extract = _coconut_compose(times_100, map)
 levels = (extract)(*(ReadChannel, channels))
 print("levels: ", levels)
 volts = (extract)(*(ConvertVolts, levels))
 print("volts: ", volts)
 distances = (extract)(*(ConvertDistance, volts))
 print("distances: ", distances)
 (print_data)(*(channels, levels, volts, distances))
def format_data(channel, data, level, volts):
 (print)("Distance {}: {} ({}V) {} cm".format(channel, level, volts, data))
while True:
 get_time = _coconut_compose(time.asctime, time.localtime, time.time)
 (print)("--------------------------------------------")
 (print_distances)(range(3))
 print("Time: " + get_time())
 time.sleep(delay)
