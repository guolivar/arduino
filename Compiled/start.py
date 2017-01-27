#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0x8e38367

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
def ConvertVolts(data, places=2):
 volts = (data * 3.3) / float(1023)
 volts = round(volts, places)
 return volts
def ConvertTemp(data, places):
 temp = ((data * 330) / float(1023)) - 50
 temp = round(temp, places)
 return temp
def ConvertDistance(v, places=2):
 return 16.2537 * v**4 - 129.893 * v**3 + 382.268 * v**2 - 512.611 * v + 306.439
ir_channel = 0
delay = 5
@_coconut_tco
def addUp(items, total=0):
 """ Our owm summing function because the python one has a memory leak"""
 if len(items) == 0:
  return total
 total += items.pop()
 raise _coconut_tail_call(addUp, items, total)
@_coconut_tco
def normalize(data, arg, repetitions=10, result=[]):
 if repetitions == 0:
  length = len(result)
  if length == 0:
   return 0
  total = addUp(result)
  average = total / length
  print("sum: ", total, "average: ", average)
  return average
 read = data(arg)
 if read >= 0:
  print("repetitions: ", repetitions, "read: ", read)
  result.append(read)
 raise _coconut_tail_call(normalize, data, arg, repetitions - 1, result)
while True:
 ir_level = ReadChannel(ir_channel)
 ir_volts = ConvertVolts(ir_level)
 distance = ConvertDistance(ir_volts)
 ir_channel2 = ir_channel + 1
 ir_level2 = ReadChannel(ir_channel2)
 ir_volts2 = ConvertVolts(ir_level2)
 distance2 = ConvertDistance(ir_level2)
 ir_channel3 = ir_channel + 2
 ir_level3 = ReadChannel(ir_channel3)
 ir_volts3 = ConvertVolts(ir_level3)
 distance3 = ConvertDistance(ir_level3)
 get_time = _coconut_compose(time.asctime, time.localtime, time.time)
 (print)("--------------------------------------------")
 print("Distance : {} ({}V) {} cm".format(ir_level, ir_volts, distance))
 print("Distance2 : {} ({}V) {} cm".format(ir_level2, ir_volts2, distance2))
 print("Distance2 : {} ({}V) {} cm".format(ir_level3, ir_volts3, distance3))
 print(("Time: {}".format)(get_time()))
 time.sleep(delay)
