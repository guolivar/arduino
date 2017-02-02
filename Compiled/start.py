#!/usr/bin/env python
# -*- coding: utf-8 -*-
# __coconut_hash__ = 0xb18274d7

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
import os
spi = spidev.SpiDev()
spi.open(0, 0)
def ReadChannel(channel):
 adc = spi.xfer2([1, (8 + channel) << 4, 0])
 data = ((adc[1] & 3) << 8) + adc[2]
 return data
from skomobo import *
def print_distance(channel):
 levels = (times)(_coconut.functools.partial(ReadChannel, channel), 100)
 data = convert(levels, to_volts, to_distance)
 averages = resolve(average, data)
 (print)(format_data(channel, *averages))
@_coconut_tco
def print_distances(channels):
 raise _coconut_tail_call(resolve, print_distance, channels)
while True:
 (print)((save)((to_volts)((average)((times)(_coconut.functools.partial(ReadChannel, 2), 100)))))
